//
//  Color.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Color__
#define __Three_cpp__Color__

#include <iostream>
#include <vector>

namespace three {
    /* Small datastructure to represent HSL */
    struct HSL {
        float h, s, l;
    };
    
    class Color {
        public:
            Color();
            Color( int hex_value );
            Color( float r, float g, float b );
            Color(const Color& rhs);
            ~Color();
        
            Color& set( float r, float g, float b );
            Color& set( int hex );
            Color& set( std::string style );
            Color& setHSL( float h, float s, float l );
            Color& operator=( const Color& rhs );
            Color& copyGammaToLinear( Color& rhs );
            Color& copyLinearToGamma( Color& rhs );
        
            Color& convertGammaToLinear();
            Color& convertLinearToGamma();
        
            int getHex();
            std::string getHexString();
            HSL getHSL();
            Color& offsetHSL( float h, float s, float l );
        
            Color operator+(const Color& rhs);
            Color& operator+=(const Color& rhs);
            Color operator+(float scalar);
            Color& operator+=(float scalar);
            Color operator*( const Color& rhs );
            Color& operator*=( const Color& rhs );
            Color operator*( float scalar );
            Color& operator*=( float scalar );
        
            Color& lerp(Color& rhs, float alpha);
            bool equals( Color& rhs );
            Color& fromArray( std::vector<float>& vec );
            std::vector<float> toArray();
            Color clone();
            
            float r;
            float g;
            float b;
        
            friend std::ostream &operator <<( std::ostream& os, const Color& color ) {
                os << "(" << color.r << " " << color.g << " " << color.b << ")";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Color__) */
