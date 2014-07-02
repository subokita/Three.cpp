//
//  PerspectiveCamera.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "PerspectiveCamera.h"
#include "Math.h"

namespace three {
    
    PerspectiveCamera::PerspectiveCamera():
        fov   ( 50.0 ),
        aspect( 1.0 ),
        near  ( 0.1 ),
        far   ( 2000.0 )
    {}
    
    PerspectiveCamera::PerspectiveCamera( float fov, float aspect, float near, float far ) :
        fov   ( fov ),
        aspect( aspect ),
        near  ( near ),
        far   ( far )
    {}
    
    PerspectiveCamera::PerspectiveCamera( const PerspectiveCamera& rhs ):
        Camera( rhs ),
        fov   ( rhs.fov ),
        aspect( rhs.aspect ),
        near  ( rhs.near ),
        far   ( rhs.far )
    {}
    
    PerspectiveCamera PerspectiveCamera::clone(){
        return PerspectiveCamera( *this );
    }
    
    PerspectiveCamera::~PerspectiveCamera(){
    }
    
    void PerspectiveCamera::setLens( float focal_length, float frame_height ){
        if ( frame_height < 1.0 )
            frame_height = 24.0;
        
        this->fov = 2 * Math::radToDeg( atan( frame_height / (focal_length * 2.0) ) );
        updateProjectionMatrix();
    }
    
    void PerspectiveCamera::setViewOffset( float full_width, float full_height, float x, float y, float width, float height ){
    //    FIXME: remember to implement this later
    }
    
    void PerspectiveCamera::updateProjectionMatrix() {
        projectionMatrix = glm::perspective( fov, aspect, near, far );
    }
}