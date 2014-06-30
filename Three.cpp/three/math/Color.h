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
    struct HSL {
        float h;
        float s;
        float l;
    };
    
    class Color {
        public:
            Color();
            Color( float param_r, float param_g, float param_b );
            ~Color();
        
            Color& set( float r, float g, float b );
            Color& set( int hex );
            Color& set( std::string style );
            Color& setHSL( float h, float s, float l );
            Color& operator=( Color& other );
            Color& copyGammaToLinear( Color& other );
            Color& copyLinearToGamma( Color& other );
        
            Color& convertGammaToLinear();
            Color& convertLinearToGamma();
        
            int getHex();
            std::string getHexString();
            HSL getHSL();
            Color& offsetHSL( float h, float s, float l );
        
            Color operator+(const Color& other);
            Color& operator+=(const Color& other);
            Color operator+(float scalar);
            Color& operator+=(float scalar);
            Color operator*( const Color& other );
            Color& operator*=( const Color& other );
            Color operator*( float scalar );
            Color& operator*=( float scalar );
        
            Color& lerp(Color& other, float alpha);
            bool equals( Color& other );
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
