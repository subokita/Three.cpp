//
//  OrthographicCamera.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__OrthographicCamera__
#define __Three_cpp__OrthographicCamera__

#include <iostream>
#include "Camera.h"

namespace three {
    class OrthographicCamera : public Camera {
        public:
            OrthographicCamera();
            OrthographicCamera( float left, float right, float top, float bottom, float near, float far );
            OrthographicCamera( const OrthographicCamera& rhs );
            OrthographicCamera clone() const;
            ~OrthographicCamera();
        
            void updateProjectionMatrix();
        
        
            /* Data members */
            float left;
            float right;
            float top;
            float bottom;
            float near;
            float far;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const OrthographicCamera& obj ) {
                os << "OrthographicCamera {" << std::endl;
                os << "\tleft  : " << obj.left   << std::endl;
                os << "\tright : " << obj.right  << std::endl;
                os << "\ttop   : " << obj.top    << std::endl;
                os << "\tbottom: " << obj.bottom << std::endl;
                os << "\tnear  : " << obj.near   << std::endl;
                os << "\tfar   : " << obj.far    << std::endl;
                os << "}";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__OrthographicCamera__) */
