//
//  Quaternion.h
//  Three.cpp
//
//  Created by Saburo Okita on 29/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Quaternion__
#define __Three_cpp__Quaternion__

#include <iostream>
#include <glm/glm.hpp>

namespace three {
    class Euler;
    
    class Quaternion {
        public:
            Quaternion();
            ~Quaternion();
            Quaternion( float param_x, float param_y, float param_z, float param_w );
            Quaternion& set( float x, float y, float z, float w );
        
            Quaternion& operator=( const Quaternion& other );
            Quaternion& setFrom( Euler& euler );
            Quaternion& setFrom( glm::vec3& axis, float angle );
        
            Quaternion& setFrom( glm::mat4x4& mat );
            Quaternion& setFrom( glm::vec3& v_from, glm::vec3& v_to );
        
            Quaternion& inverse();
            Quaternion& conjugate();
            float lengthSquared();
            float length();
            Quaternion& normalize();
        
            Quaternion& multiply(Quaternion& q);
        
            float x;
            float y;
            float z;
            float w;
    };
}

#endif /* defined(__Three_cpp__Quaternion__) */
