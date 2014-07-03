//
//  Camera.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Camera.h"


namespace three {
    Camera::Camera(){}
    
    Camera::Camera( const Camera& rhs ):
        Object3D          ( rhs ),
        matrixWorldInverse( rhs.matrixWorldInverse ),
        projectionMatrix  ( rhs.projectionMatrix )
    {}
    
    Camera Camera::clone() const{
        return Camera(*this);
    }
    
    Camera::~Camera(){
    }
    
    
    void Camera::lookAt( glm::vec3 vec ) {
        glm::mat4x4 mat = glm::lookAt( this->position, vec, this->up );
        this->quaternion.setFrom( mat );
    }
}