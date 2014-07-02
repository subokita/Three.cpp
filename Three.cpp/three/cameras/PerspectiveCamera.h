//
//  PerspectiveCamera.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__PerspectiveCamera__
#define __Three_cpp__PerspectiveCamera__

#include <iostream>

#include "Camera.h"


namespace three {
    class PerspectiveCamera: public Camera {
        public:
            PerspectiveCamera();
            PerspectiveCamera( float fov, float aspect, float near, float far );
            PerspectiveCamera( const PerspectiveCamera& rhs );
            PerspectiveCamera clone();
            ~PerspectiveCamera();
        
            void setLens( float focal_length, float frame_height );
            void setViewOffset( float full_width, float full_height, float x, float y, float width, float height );
            void updateProjectionMatrix();
        
            /* Data members */
            float fov;
            float aspect;
            float near;
            float far;
        
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const PerspectiveCamera& obj ) {
                os << "PerspectiveCamera {" << std::endl;
                os << "\tfov   : " << obj.fov    << std::endl;
                os << "\taspect: " << obj.aspect << std::endl;
                os << "\tnear  : " << obj.near   << std::endl;
                os << "\tfar   : " << obj.far    << std::endl;
                os << "}";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__PerspectiveCamera__) */
