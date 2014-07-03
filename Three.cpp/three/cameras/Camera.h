//
//  Camera.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Camera__
#define __Three_cpp__Camera__

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Utils.h"
#include "Object3D.h"


namespace three {
    class Camera : public Object3D {
        public:
            Camera();
            Camera( const Camera& rhs );
            Camera clone() const;
            ~Camera();
        
            void lookAt( glm::vec3 vec );
        
            /* Data members */
            glm::mat4x4 matrixWorldInverse;
            glm::mat4x4 projectionMatrix;
        
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const Camera& obj ) {
                os << "matrixWorldInverse: " << Utils::toString(obj.matrixWorldInverse) << std::endl;
                os << "projectionMatrix  : " << Utils::toString(obj.projectionMatrix)   << std::endl;
                return os;
            }

    };
}

#endif /* defined(__Three_cpp__Camera__) */
