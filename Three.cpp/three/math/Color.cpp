//
//  Color.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Color.h"
#include "Math.h"
#include <sstream>
#include <iomanip>

using namespace std;

namespace three {
    
    Color::Color():
        r( 1.0 ),
        g( 1.0 ),
        b( 1.0 )
    {}
    
    Color::Color( float r, float g, float b ):
        r( r ),
        g( g ),
        b( b )
    {}
    
    Color::Color(const Color& rhs) :
        r( rhs.r ),
        g( rhs.g ),
        b( rhs.b )
    {}
    
    
    Color::Color( int hex_value ) {
        set( hex_value );
    }
    
    Color::~Color(){
    }
    
    Color& Color::set( float r, float g, float b ){
        this->r = r;
        this->g = g;
        this->b = b;
        return *this;
    }
    
    Color& Color::set( int hex ){
        this->r = (hex >> 16 & 255) / 255.0;
        this->g = (hex >> 8 & 255) / 255.0;
        this->b = (hex & 255) / 255.0;
        return *this;
    }
    
    //FIXME: ???
    Color& Color::set( std::string style ){
        return *this;
    }
    
    Color& Color::setHSL( float h, float s, float l ){
        if( s == 0.0 ) {
            this->r = l;
            this->g = l;
            this->b = l;
        }
        else {
            float p = l <= 0.5 ? l * (1.0 + s) : l + s - (l * s);
            float q = (2 * l) - p;
            
            this->r = Math::hueToRGB( q, p, h + 1.0 / 3.0 );
            this->g = Math::hueToRGB( q, p, h );
            this->b = Math::hueToRGB( q, p, h - 1.0 / 3.0 );
        }
        
        return *this;
    }
    
    Color& Color::operator=( const Color& rhs ){
        if( this == &rhs )
            return *this;
        
        this->r = rhs.r;
        this->g = rhs.g;
        this->b = rhs.b;
        
        return *this;
    }
    
    Color& Color::copyGammaToLinear( Color& rhs ){
        this->r = rhs.r * rhs.r;
        this->g = rhs.g * rhs.g;
        this->b = rhs.b * rhs.b;
        return *this;
    }
    
    Color& Color::copyLinearToGamma( Color& rhs ){
        this->r = sqrt( rhs.r );
        this->g = sqrt( rhs.g );
        this->b = sqrt( rhs.b );
        return *this;
    }
    
    Color& Color::convertGammaToLinear(){
        this->r = this->r * this->r;
        this->g = this->g * this->g;
        this->b = this->b * this->b;
        return *this;
    }
    
    Color& Color::convertLinearToGamma(){
        this->r = sqrt( this->r );
        this->g = sqrt( this->g );
        this->b = sqrt( this->b );
        return *this;
    }
    
    int Color::getHex(){
        int r = static_cast<int>(this->r * 255.0);
        int g = static_cast<int>(this->g * 255.0);
        int b = static_cast<int>(this->b * 255.0);
        return r << 16 ^ g << 8 ^ b << 0;
    }
    
    string Color::getHexString(){
        std::stringstream ss;
        ss << std::hex << getHex();
        return string( ss.str() );
    }
    
    HSL Color::getHSL(){
        
        HSL hsl;
        hsl.h = 0.0;
        hsl.s = 0.0;
        hsl.l = 0.0;
        
        float max = std::max(std::max( r, g ), b);
        float min = std::min(std::min( r, g ), b);
        
        float hue;
        float saturation;
        float lightness = (min + max) / 2.0;
        
        if( min == max ) {
            hue         = 0.0;
            saturation  = 0.0;
        }
        else {
            float delta = max - min;
            saturation = lightness <= 0.5 ? delta / (max + min) : delta / (2 - max - min);
            
            if( max == r )
                hue = (g - b) / delta + (g < b ? 6.0 : 0.0);
            else if ( max == g )
                hue = (b - r) / delta + 2;
            else if ( max == b )
                hue = (r - g) / delta + 4;
                
            hue /= 6.0;
        }
        
        hsl.h = hue;
        hsl.s = saturation;
        hsl.l = lightness;
        
        return hsl;
    }
    
    Color& Color::offsetHSL( float h, float s, float l ){
        HSL hsl = getHSL();
        hsl.h += h;
        hsl.s += s;
        hsl.l += l;
        setHSL( hsl.h, hsl.s, hsl.l );
        return *this;
    }
    
    Color Color::operator+(const Color& rhs){
        return Color( r + rhs.r, g + rhs.g, b + rhs.b );
    }
    
    Color& Color::operator+=(const Color& rhs){
        r += rhs.r;
        g += rhs.g;
        b += rhs.b;
        return *this;
    }
    
    Color Color::operator+(float scalar){
        return Color( r + scalar, g + scalar, b + scalar );
    }
    
    Color& Color::operator+=(float scalar){
        r += scalar;
        g += scalar;
        b += scalar;
        return (*this);
    }
    
    Color Color::operator*( const Color& rhs ){
        return Color( r * rhs.r, g * rhs.g, b * rhs.b );
    }
    
    Color& Color::operator*=( const Color& rhs ){
        r *= rhs.r;
        g *= rhs.g;
        b *= rhs.b;
        return *this;
    }
    
    Color Color::operator*( float scalar ){
        return Color( r * scalar, g * scalar, b * scalar );
    }
    
    Color& Color::operator*=( float scalar ){
        r *= scalar;
        g *= scalar;
        b *= scalar;
        return *this;
    }
    
    Color& Color::lerp(Color& rhs, float alpha) {
        r += (rhs.r - r) * alpha;
        g += (rhs.g - g) * alpha;
        b += (rhs.b - b) * alpha;
        return *this;
    }
    
    bool Color::equals( Color& rhs ){
        return r == rhs.r && g == rhs.g && b == rhs.b;
    }
    
    Color& Color::fromArray( std::vector<float>& vec ){
        r = vec[0];
        g = vec[1];
        b = vec[2];
        return *this;
    }
    
    std::vector<float> Color::toArray() {
        return vector<float> { r, g, b };
    }
    
    Color Color::clone() {
        return Color( *this );
    }
    
}