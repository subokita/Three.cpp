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
    
    enum class RotationOrders {
        XYZ = 0,
        YZX = 1,
        ZXY = 2,
        XZY = 3,
        YXZ = 4,
        ZYX = 5
    };
    
    class Euler {
        public:
            Euler();
            Euler( float x_val, float y_val, float z_val, RotationOrders rot_order );
            ~Euler();
        
            Euler& set( float x, float y, float z, RotationOrders order );
            Euler& operator=( const Euler& other );
            Euler& setFrom( glm::mat4x4& mat, RotationOrders order  );
            Euler& setFrom( glm::quat& q, RotationOrders order );
            void reorder( RotationOrders new_order );
            bool equals( Euler& other );
        
            Euler& fromArray( std::vector<float>& array );
            std::vector<float> toArray();
        
            //FIXME: onChange() ?
            Euler clone();
        
        
        
            float x;
            float y;
            float z;
            RotationOrders order = RotationOrders::XYZ;
    };
}

#endif /* defined(__Three_cpp__Euler__) */
