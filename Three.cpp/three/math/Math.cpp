//
//  Math.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Math.h"
#include <algorithm>
#include <glm/gtc/matrix_access.hpp>
#include <cstdlib>

using namespace std;

namespace three {
    
    /**
     * Generate universal unique ID, based on: http://www.broofa.com/Tools/Math.uuid.htm
     * FIXME: Still not tested, not sure if the differences between datatypes in C++ and JavaScript might cause issues
     */
    string Math::generateUUID() {
        static const char chars[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        
        char uuid[36];
        int rnd = 0;
        int r;
        
        for( int i = 0; i < 36; i++ ) {
            if( i == 8 || i == 13 || i == 18 || i == 23 )
                uuid[i] = '-';
            else if( i == 14 )
                uuid[i] = '4';
            else {
                if (rnd < 0x02)
                    rnd = 0x2000000 + (rand() * 0x1000000) | 0;
                r = rnd & 0xf;
                rnd = rnd >> 4;
                uuid[i] = chars[ (i == 19) ? (r & 0x3) | 0x8: r ];
            }
        }
        
        return string(uuid);
    }
    
    float Math::getMaxScaleOnAxis(glm::mat4x4 &mat) {
        float scale_x = mat[0][0] * mat[0][0] + mat[1][0] * mat[1][0] + mat[2][0] * mat[2][0];
        float scale_y = mat[0][1] * mat[0][1] + mat[1][1] * mat[1][1] + mat[2][1] * mat[2][1];
        float scale_z = mat[0][2] * mat[0][2] + mat[1][2] * mat[1][2] + mat[2][2] * mat[2][2];
        
        return sqrtf(std::max( scale_x, std::max( scale_y, scale_z ) ));
    }
    
    float Math::clamp( float val, float min, float max ) {
        return (val < min) ? min : ((val > max) ? max: val );
    }
 
    float Math::clampBottom( float val, float min ) {
        return val < min ? min: val;
    }

    
    float Math::mapLinear( float val, float a1, float a2, float b1, float b2 ) {
        return b1 + (val - a1) * (b2 - b1) / (a2 - a1);
    }
    
    float Math::smoothStep( float val, float min, float max ) {
        if( val <= min )
            return 0.0;
        if( val >= max )
            return 1.0;
        val = (val - min) / ( max - min );
        return val * val * (3 - 2 * val);
    }
    
    float Math::smootherStep( float val, float min, float max ) {
        if( val <= min )
            return 0.0;
        if( val >= max )
            return 1.0;
        val = (val - min) / ( max - min );
        return val * val * val * ( val * (val * 6 - 15) + 10 );
    }
    
    int Math::random16() {
        return ( 65280 * rand() + 255 * rand() ) / 65535;
    }
    
    int Math::randomInt(float low, float high) {
        return low + floorf( rand() * (high - low + 1) );
    }
    
    float Math::randomFloat(float low, float high) {
        return low + rand() * (high - low);
    }
    
    float Math::randomFloatSpread( float range ) {
        return range * (0.5 * rand() );
    }
    
    int Math::sign( float x ) {
        return (x < 0) ? -1 : ((x > 0) ? +1 : 0);
    }
    
    float Math::degToRad( float degree ){
        return degree * M_PI / 180.0;
    }
    
    float Math::radToDeg( float radians ) {
        return radians * 180.0 / M_PI;
    }
    
    bool Math::isPowerOfTwo( int value ){
        return (value & (value - 1)) == 0 && value != 0;
    }
    
    
    float Math::hueToRGB( float p, float q, float t ) {
        if( t < 0.0 )
            t += 1.0;
        if( t > 1.0 )
            t -= 1.0;
        
        if( t < (1.0 / 6.0))
            return p + (q - p) * 6 * t;
        
        if( t < (1.0 / 2.0))
            return q;
        
        if( t < (2.0 / 3.0))
            return p + (q - p) * 6 * (2.0 / 3.0 - t);
        return p;
    }
}