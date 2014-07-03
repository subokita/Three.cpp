//
//  Scene.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Scene.h"
#include "Event.h"
#include "Camera.h"
#include "Bone.h"

using namespace std;

namespace three {
    Scene::Scene():
        autoUpdate( true )
    {
        this->matrixAutoUpdate = false;
    }
    
    Scene::Scene( const Scene& rhs ):
        Object3D        ( rhs ),
        fog             ( rhs.fog ),
        overrideMaterial( rhs.overrideMaterial ),
        autoUpdate      ( rhs.autoUpdate )
    {
        this->matrixAutoUpdate = rhs.matrixAutoUpdate;
        
        lights.insert        ( rhs.lights.begin(), rhs.lights.end() );
        objectsAdded.insert  ( rhs.objectsAdded.begin(), rhs.objectsAdded.end() );
        objectsRemoved.insert( rhs.objectsRemoved.begin(), rhs.objectsRemoved.end() );
    }
    
    Scene Scene::clone() {
        return Scene(*this);
    }
    
    Scene::~Scene(){
    }
    
    
    
    void Scene::addObject( std::shared_ptr<Object3D> object ) {
        if( INSTANCE_OF(object, Light) ) {
            shared_ptr<Light> light = DOWN_CAST(object, Light);
            if( lights.count( light->id ) == 0 )
                lights[object->id] = light;
            
            if( light->parent == nullptr && light->target != nullptr )
                this->Object3D::add( light->target );
        }
        else if( !( INSTANCE_OF(object, Camera) || INSTANCE_OF(object, Bone) ) ) {
            objectsAdded[object->id] = object;
            
            if( objectsRemoved.count(object->id) != 0 )
                objectsRemoved.erase( object->id );
        }
        
        this->dispatchEvent( Event{ "objectAdded", object, nullptr } );
        object->dispatchEvent( Event{ "addedToScene", nullptr, shared_from_this() } );

        
        for( auto entry : children )
            addObject( entry.second );
    }
    
    
    void Scene::removeObject( std::shared_ptr<Object3D> object ) {
        
        if( INSTANCE_OF(object, Light) ) {
            shared_ptr<Light> light = DOWN_CAST(object, Light);
            if( lights.count( light->id ) != 0 )
                lights.erase( light->id );
            
            if( !light->shadowCascadeArray.empty() ) {
                for( shared_ptr<Light> l : light->shadowCascadeArray )
                    this->removeObject( l );
            }
        }
        else if ( !INSTANCE_OF(object, Camera) ) {
            objectsRemoved[object->id] = object;
            
            if( objectsAdded.count( object->id ) != 0 )
                objectsAdded.erase( object->id );
        }
        
        
        this->dispatchEvent( Event{ "objectRemoved", object, nullptr } );
        object->dispatchEvent( Event{ "removedFromScene", nullptr, shared_from_this() } );
        
        for( auto entry : children )
            removeObject( entry.second );
    }
}