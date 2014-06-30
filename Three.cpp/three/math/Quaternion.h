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
#include <glm/gtc/quaternion.hpp>
#include <vector>


namespace three {
    class Euler;
    
    class Quaternion {
        public:
            Quaternion();
            ~Quaternion();
            Quaternion( float param_x, float param_y, float param_z, float param_w );
        
            Quaternion& setX( float x );
            Quaternion& setY( float y );
            Quaternion& setZ( float z );
            Quaternion& setW( float w );
        
            Quaternion& set( float x, float y, float z, float w );
            Quaternion& operator=( const Quaternion& other );
            Quaternion& setFrom( Euler& euler, bool update );
            Quaternion& setFrom( glm::vec3& axis, float angle );
        
            Quaternion& setFrom( glm::mat4x4& mat );
            Quaternion& setFrom( glm::vec3& v_from, glm::vec3& v_to );
        
            Quaternion& inverse();
            Quaternion& conjugate();
            float lengthSquared();
            float length();
            Quaternion& normalize();
        
            static Quaternion slerp( Quaternion& a, Quaternion& b, float t );
        
            static Quaternion multiply(Quaternion& a, Quaternion& b);
            Quaternion& multiply(Quaternion& q);
            Quaternion& slerp( Quaternion& q, float t );
            bool equals( Quaternion& q );
            
            Quaternion& fromArray( std::vector<float>& vec );
            std::vector<float> toArray();
            Quaternion clone();
        
            Quaternion& onChange( std::function<void()> callback );
        
        
            float x;
            float y;
            float z;
            float w;
            std::function<void()> onChangeCallback = [](){};
        
            /**
             * Stream overloading for printing
             */
            friend std::ostream &operator <<( std::ostream& os, const Quaternion& q ) {
                os << "(" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << ")" ;
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Quaternion__) */
