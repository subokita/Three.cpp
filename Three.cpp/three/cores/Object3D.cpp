//
//  Object3D.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Object3D.h"
#include "Math.h"

namespace three {
    Object3D::Object3D() {
        /* Again, maybe put these in initializer lists */
        id                     = Object3DIDCount++;
        uuid                   = Math::generateUUID();
        name                   = "";
        parent                 = nullptr;
        position               = glm::vec3(0, 0, 0);
        up                     = glm::vec3(0, 1.0, 0);
        scale                  = glm::vec3(1.0, 1.0, 1.0);
        rotationAutoUpdate     = true;
        matrixAutoUpdate       = true;
        matrixWorldNeedsUpdate = false;
        visible                = true;
        castShadow             = false;
        receiveShadow          = false;
        frustumCulled          = true;
        
        rotation.onChange([&]() {
            quaternion.setFrom( rotation, false );
        });
        
        quaternion.onChange([&]() {
            rotation.setFrom( quaternion, rotation.order, false );
        });
    }
    
    
    void Object3D::applyMatrix( glm::mat4x4& mat ) {
        this->matrix = mat * this->matrix;
        Math::decomposeMatrix( this->matrix, this->position, this->quaternion, this->scale );
    }
    
    
    void Object3D::setRotationFrom(glm::vec3& axis, float angle) {
        this->quaternion.setFrom( axis, angle );
    }
    
    void Object3D::setRotationFrom( Euler& euler ) {
        this->quaternion.setFrom( euler, true );
    }
    
    void Object3D::setRotationFrom( glm::mat4x4& mat ) {
        this->quaternion.setFrom( mat );
    }
    
    void Object3D::setRotationFrom( Quaternion& quat ) {
        this->quaternion = quat;
    }
    
    
    Object3D& Object3D::rotateOnAxis(glm::vec3& axis, float angle) {
        Quaternion q;
        q.setFrom( axis, angle );
        this->quaternion.multiply( q );
        return *this;
    }
    
    Object3D& Object3D::rotateX( float angle ){
        glm::vec3 axis(1.0, 0.0, 0.0);
        return rotateOnAxis( axis, angle );
    }
    
    Object3D& Object3D::rotateY( float angle ) {
        glm::vec3 axis(0.0, 1.0, 0.0);
        return rotateOnAxis( axis, angle );
    }
    
    Object3D& Object3D::rotateZ( float angle ) {
        glm::vec3 axis(0.0, 0.0, 1.0);
        return rotateOnAxis( axis, angle );
    }
    
    Object3D& Object3D::translate( glm::vec3& axis, float distance ) {
        glm::vec3 vec = axis;
        //FIXME: Complete this
        return *this;
    }
}