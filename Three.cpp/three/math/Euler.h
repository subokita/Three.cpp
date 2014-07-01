//
//  Euler.h
//  Three.cpp
//
//  Created by Saburo Okita on 28/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Euler__
#define __Three_cpp__Euler__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace three {
    /* Declaring to avoid circular reference */
    class Quaternion;
    
    /**
     * Enum for Euler rotation order
     */
    enum class RotationOrders {
        XYZ = 0, YZX = 1, ZXY = 2,
        XZY = 3, YXZ = 4, ZYX = 5
    };
    
    class Euler {
        public:
            /**
             * Default constructor
             */
            Euler();
        
            /**
             * Constructor that sets the x, y, z, and the order of the Euler angle
             */
            Euler( float x, float y, float z, RotationOrders rot_order );
        
            /**
             * Copy constructor
             */
            Euler( const Euler& rhs );
        
            /**
             * Destructor
             */
            ~Euler();
        
            Euler& setX( float x );
            Euler& setY( float y );
            Euler& setZ( float z );
            Euler& setRotationOrder( RotationOrders order );
        
            Euler& set( float x, float y, float z, RotationOrders order );
            Euler& operator=( const Euler& rhs );
        
            /**
             * Set Euler angles from 4x4 matrix
             */
            Euler& setFrom( glm::mat4x4& mat, RotationOrders order  );
        
            /**
             * Set Euler angles from quaternion q, q is assumed to be normalized
             * Based on: http://www.mathworks.com/matlabcentral/fileexchange/20696-function-to-convert-between-dcm-euler-angles-quaternions-and-euler-vectors/content/SpinCalc.m
             */
            Euler& setFrom( Quaternion& q, RotationOrders order, bool update );
        
            /**
             * Change the rotation order
             * This discards revolution information
             */
            void reorder( RotationOrders new_order );
        
            /**
             * Returns true if all the members of this euler object
             * match rhs's
             */
            bool equals( Euler& rhs );
        
            /**
             * Set the Euler angle from an array (vector)
             */
            Euler& fromArray( std::vector<float>& array );
        
            /**
             * From euler angle to array representation
             */
            std::vector<float> toArray();
        
            /**
             * Clone the current object
             */
            Euler clone();
        
            /**
             * Set the callback function
             */
            Euler& onChange( std::function<void()> callback );
        
        
            float x;
            float y;
            float z;
            RotationOrders order;
            std::function<void()> onChangeCallback = [](){};
        
        
            /**
             * Stream overloading for printing
             */
            friend std::ostream &operator <<( std::ostream& os, const Euler& euler ) {
                os << "(" << euler.x << ", " << euler.y << ", " << euler.z << ", " ;
                switch ( euler.order) {
                    case RotationOrders::XYZ: os << "XYZ)"; break;
                    case RotationOrders::YXZ: os << "YXZ)"; break;
                    case RotationOrders::ZXY: os << "ZXY)"; break;
                    case RotationOrders::ZYX: os << "ZYX)"; break;
                    case RotationOrders::YZX: os << "YZX)"; break;
                    case RotationOrders::XZY: os << "XZY)"; break;
                }
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Euler__) */
