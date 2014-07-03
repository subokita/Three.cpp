//
//  Object3D.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Object3D.h"
#include "Math.h"
#include "Event.h"

namespace three {
    Object3D::Object3D() :
        id                    ( Object3DIDCount++ ),
        uuid                  ( Math::generateUUID() ),
        name                  ( "" ),
        position              ( glm::vec3(0, 0, 0) ),
        up                    ( glm::vec3(0, 1.0, 0) ),
        scale                 ( glm::vec3(1.0, 1.0, 1.0) ),
//       renderDepth            (),
        rotationAutoUpdate    ( true ),
        matrixAutoUpdate      ( true ),
        matrixWorldNeedsUpdate( false ),
        visible               ( true ),
        castShadow            ( false ),
        receiveShadow         ( false ),
        frustumCulled         ( true ),
        userData              ( json_object_new_object() )
    {
        rotation.onChange([&]() {
            quaternion.setFrom( rotation, false );
        });
        
        quaternion.onChange([&]() {
            rotation.setFrom( quaternion, rotation.order, false );
        });
    }
    
    
    Object3D::Object3D( const Object3D& rhs ) :
        id                    ( rhs.id ),
        uuid                  ( rhs.uuid ),
        name                  ( rhs.name ),
        parent                ( rhs.parent ),
        children              ( rhs.children ),
        position              ( rhs.position ),
        up                    ( rhs.up ),
        rotation              ( rhs.rotation ),
        quaternion            ( rhs.quaternion ),
        scale                 ( rhs.scale ),
//        renderDepth            ( rhs.renderDepth ),
        rotationAutoUpdate    ( rhs.rotationAutoUpdate ),
        matrix                ( rhs.matrix ),
        matrixWorld           ( rhs.matrixWorld ),
        matrixAutoUpdate      ( rhs.matrixAutoUpdate ),
        matrixWorldNeedsUpdate( rhs.matrixWorldNeedsUpdate ),
        visible               ( rhs.visible ),
        castShadow            ( rhs.castShadow ),
        receiveShadow         ( rhs.receiveShadow ),
        frustumCulled         ( rhs.frustumCulled ),
        userData              ( rhs.userData ) //FIXME: check whether it's copying or assigning reference
    {
        
    }
    
    Object3D::~Object3D(){
        
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
    
    void Object3D::lookAt( glm::vec3& vec ) {
        glm::mat4x4 mat = glm::lookAt( this->position, vec, this->up );
        this->quaternion.setFrom( mat );
    }

    
    void Object3D::add( shared_ptr<Object3D> object ) {
        if( this == object.get() )
            return;
        
        if( object->parent != nullptr  )
            object->parent->remove( object );
        
        object->parent = shared_from_this();
        object->dispatchEvent( Event{ "added", nullptr, nullptr } );
        this->children[object->id] = object;
        
        /* Add to scene */
        shared_ptr<Object3D> scene = shared_from_this();
        while( scene->parent != nullptr )
            scene = scene->parent;
        
        if( scene != nullptr && INSTANCE_OF(scene, Scene)) {
            shared_ptr<Scene> scene_object = DOWN_CAST( scene, Scene );
            scene_object->addObject( object );
        }
    }
    
    void Object3D::remove( shared_ptr<Object3D> object ) {
        if( children.count(object->id) != 0 ) {
            object->parent = nullptr;
            
            object->dispatchEvent( Event{ "removed" } );
            children.erase( object->id );
            
            /* Remove from scene */
            shared_ptr<Object3D> scene = shared_from_this();
            while( scene->parent != nullptr )
                scene = scene->parent;
            
            if( scene != nullptr && INSTANCE_OF(scene, Scene)) {
                shared_ptr<Scene> scene_object = DOWN_CAST( scene, Scene );
                scene_object->removeObject( object );
            }
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
    
    Object3D& Object3D::operator=( const Object3D& rhs ) {
        this->name       = rhs.name;
        this->up         = rhs.up;
        this->position   = rhs.position;
        this->quaternion = rhs.quaternion;
        this->scale      = rhs.scale;
        
        //FIXME: renderDepth???
        this->rotationAutoUpdate     = rhs.rotationAutoUpdate;
        this->matrix                 = rhs.matrix;
        this->matrixWorld            = rhs.matrixWorld;
        this->matrixAutoUpdate       = rhs.matrixAutoUpdate;
        this->matrixWorldNeedsUpdate = rhs.matrixWorldNeedsUpdate;
        this->visible                = rhs.visible;
        this->castShadow             = rhs.castShadow;
        this->frustumCulled          = rhs.frustumCulled;
        
        // FIXME: this is not right, should find a proper cloning function
        this->userData = rhs.userData;
        
        return *this;
    }
    
    Object3D Object3D::clone(bool recursive) const{
        //FIXME: double check the children, whether or not they require deep copy
        return Object3D( *this );
    }
}