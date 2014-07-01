//
//  Object3D.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Object3D__
#define __Three_cpp__Object3D__

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include <json-c/json.h>
#include <glm/glm.hpp>

#include "EventDispatcher.h"
#include "Euler.h"
#include "Quaternion.h"


using namespace std;

namespace three {
    /* Keep state of next object ID */
    static int Object3DIDCount = 0;
    
    class Object3D : public EventDispatcher {
        public:
            Object3D();
        
            void applyMatrix( glm::mat4x4& mat );
            void setRotationFrom(glm::vec3& axis, float angle);
            void setRotationFrom( Euler& euler );
            void setRotationFrom( glm::mat4x4& mat );
            void setRotationFrom( Quaternion& quat );
        
            Object3D& rotateOnAxis(glm::vec3& axis, float angle);
            Object3D& rotateX( float angle );
            Object3D& rotateY( float angle );
            Object3D& rotateZ( float angle );
            Object3D& translate( glm::vec3& axis, float distance );
            Object3D& translateX( float distance );
            Object3D& translateY( float distance );
            Object3D& translateZ( float distance );
        
            glm::vec3 localToWorld( glm::vec3& vec );
            glm::vec4 localToWorld( glm::vec4& vec );
        
            glm::vec3 worldToLocal( glm::vec3& vec );
            glm::vec4 worldToLocal( glm::vec4& vec );
            void lookAt( glm::vec3& eye );
        
            void add( Object3D& object );
            void remove( Object3D& object );
            void traverse( std::function<void(Object3D&)> callback );
            shared_ptr<Object3D> getObjectById( int id, bool recursive );
            shared_ptr<Object3D> getObjectByName( string name, bool recursive );
            map<int, shared_ptr<Object3D>> getDescendants();
            void updateMatrix();
            void updateMatrixWorld( bool force );
            Object3D& operator=( const Object3D& other );
            Object3D clone( bool recursive = true );
        
        
            /* Data members, should have different access members, but let's wait and see */
        
            int id;
            string uuid;
            string name;
            
            shared_ptr<Object3D> parent;
            map<int, shared_ptr<Object3D>> children;
            glm::vec3 position;
            glm::vec3 up;
            Euler rotation;
            Quaternion quaternion;
            glm::vec3 scale;
        
            //FIXME: renderDepth
            bool rotationAutoUpdate;
            glm::mat4x4 matrix;
            glm::mat4x4 matrixWorld;
            bool matrixAutoUpdate;
            bool matrixWorldNeedsUpdate;
            
            bool visible;
            bool castShadow;
            bool receiveShadow;
            bool frustumCulled;
        
            json_object* userData;
        
    };
}

#endif /* defined(__Three_cpp__Object3D__) */
