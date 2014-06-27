//
//  Math.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Math__
#define __Three_cpp__Math__

#include <iostream>
#include <glm/glm.hpp>

namespace three {
    class Math {
    public:
        static std::string generateUUID();
        static float getMaxScaleOnAxis( glm::mat4x4& mat );
        static float clamp( float val, float min, float max );
        static float clampBottom( float val, float min );
        static float mapLinear( float val, float a1, float a2, float b1, float b2 );
        static float smoothStep( float val, float min, float max );
        static float smootherStep( float val, float min, float max );
        static int random16();
        static int randomInt(float low, float high);
        static float randomFloat(float low, float high);
        static float randomFloatSpread( float range );
        static int sign( float x );
        static float degToRad( float degree );
        static float radToDeg( float radians );
        static bool isPowerOfTwo( int value );
    };
}

#endif /* defined(__Three_cpp__Math__) */
