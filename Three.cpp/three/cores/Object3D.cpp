//
//  Object3D.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Object3D.h"
#include "Math.h"
#include <glm/gtc/matrix_transform.hpp>

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
        userData               = json_object_new_object();
        
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
        glm::vec3 vec = Math::applyQuaternion( axis, this->quaternion );
        this->position += (vec * distance);
        return *this;
    }
    
    Object3D& Object3D::translateX( float distance ) {
        glm::vec3 axis( 1.0, 0.0, 0.0 );
        return translate( axis, distance );
    }
    
    Object3D& Object3D::translateY( float distance ){
        glm::vec3 axis( 0.0, 1.0, 0.0 );
        return translate( axis, distance );
    }
    
    Object3D& Object3D::translateZ( float distance ) {
        glm::vec3 axis( 0.0, 0.0, 1.0 );
        return translate( axis, distance );
    }
    
    glm::vec3 Object3D::localToWorld( glm::vec3& vec ) {
        return glm::vec3(glm::vec4(vec, 1.0) * matrixWorld);
    }
    
    glm::vec4 Object3D::localToWorld( glm::vec4& vec ) {
        return vec * matrixWorld;
    }
    
    glm::vec3 Object3D::worldToLocal( glm::vec3& vec ) {
        return glm::vec3(glm::vec4( vec, 1.0 ) * glm::inverse( matrixWorld ));
    }
    
    glm::vec4 Object3D::worldToLocal( glm::vec4& vec ) {
        return vec * glm::inverse( matrixWorld );
    }
    
    void Object3D::lookAt( glm::vec3& eye ) {
        glm::mat4x4 mat = glm::lookAt( eye, this->position, this->up );
        this->quaternion.setFrom( mat );
    }
    
    void Object3D::add( Object3D& object ) {
        
        if( object.parent != nullptr )
            object.parent->remove( object );
        
        object.parent = make_shared<Object3D>(*this);
        //FIXME: dispatchEvent;
        
        children[object.id] = make_shared<Object3D>(object);
        
        //FIXME: Add to Scene
    }
    
    
    void Object3D::remove( Object3D& object ) {
        if( this->children[object.id] != nullptr ) {
            this->children.erase( object.id );
            object.parent = nullptr;
            
            //FIXME: Remove from Scene
        }
    }
    
    
    void Object3D::traverse( std::function<void(Object3D&)> callback ) {
        callback(*this);
        for( auto entry: children )
            entry.second->traverse( callback );
    }
    
    shared_ptr<Object3D> Object3D::getObjectById( int id, bool recursive ) {    
        if( children.count(id) != 0 ) {
            return children[id];
        }
        else if( recursive ){
            for( auto entry: children ) {
                shared_ptr<Object3D> child = entry.second->getObjectById( id, true );
                if( child != nullptr )
                    return child;
            }
        }
        
        return nullptr;
    }
    
    
    shared_ptr<Object3D> Object3D::getObjectByName( string name, bool recursive ) {
        if( recursive ) {
            for( auto entry: children ) {
                if( entry.second->name.compare( name ) == 0 )
                    return entry.second;
                
                shared_ptr<Object3D> child = getObjectByName( name, recursive );
                if( child != nullptr )
                    return child;
            }
        }
        else {
            for( auto entry: children ) {
                if( entry.second->name.compare( name ) == 0 )
                    return entry.second;
            }
        }
        
        return nullptr;
    }
    
    map<int, shared_ptr<Object3D>> Object3D::getDescendants() {
        map<int, shared_ptr<Object3D>> result = children;

        for( auto entry: children ){
            map<int, shared_ptr<Object3D>> grandchildren = entry.second->getDescendants();
            result.insert( grandchildren.begin(), grandchildren.end() );
        }
        
        return result;
    }
    
    void Object3D::updateMatrix() {
        this->matrix = Math::composeMatrix( this->position, this->quaternion, this->scale );
        this->matrixWorldNeedsUpdate = true;
    }
    
    
    void Object3D::updateMatrixWorld( bool force ) {
        if( this->matrixAutoUpdate )
            updateMatrix();
        
        if( this-matrixWorldNeedsUpdate || force ) {
            if( parent == nullptr )
                matrixWorld = matrix;
            else
                matrixWorld = matrixWorld * matrix;
            
            this->matrixWorldNeedsUpdate = false;
            force = true;
        }
        
        for( auto entry: children )
            entry.second->updateMatrixWorld(force);
    }
    
    Object3D& Object3D::operator=( const Object3D& other ) {
        this->name = other.name;
        this->up = other.up;
        this->position = other.position;
        this->quaternion = other.quaternion;
        this->scale = other.scale;
        
        //FIXME: renderDepth???
        
        this->rotationAutoUpdate = other.rotationAutoUpdate;
        this->matrix = other.matrix;
        this->matrixWorld = other.matrixWorld;
        this->matrixAutoUpdate = other.matrixAutoUpdate;
        this->matrixWorldNeedsUpdate = other.matrixWorldNeedsUpdate;
        
        this->visible = other.visible;
        this->castShadow = other.castShadow;
        this->frustumCulled = other.frustumCulled;

        // FIXME: this is not right, should find a proper cloning function
        this->userData = other.userData;
        
        return *this;
    }
    
    Object3D Object3D::clone(bool recursive) {
        
        
        return Object3D();
    }
}