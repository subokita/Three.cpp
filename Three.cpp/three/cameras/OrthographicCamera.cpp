//
//  OrthographicCamera.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "OrthographicCamera.h"


namespace three {
    
    OrthographicCamera::OrthographicCamera() :
        near( 0.1 ),
        far ( 2000.0 )
    {}
    
    
    OrthographicCamera::OrthographicCamera( float left, float right, float top, float bottom, float near, float far ) :
        left  ( left ),
        right ( right ),
        top   ( top ),
        bottom( bottom ),
        near  ( near ),
        far   ( far )
    {}
    
    OrthographicCamera::OrthographicCamera( const OrthographicCamera& rhs ):
        Camera( rhs ),
        left  ( rhs.left ),
        right ( rhs.right ),
        top   ( rhs.top ),
        bottom( rhs.bottom ),
        near  ( rhs.near ),
        far   ( rhs.far )
    {}
    
    OrthographicCamera OrthographicCamera::clone() const{
        return OrthographicCamera(*this);
    }
    
    OrthographicCamera::~OrthographicCamera() {}
    
    
    void OrthographicCamera::updateProjectionMatrix() {
        projectionMatrix = glm::ortho( left, right, bottom, top, near, far );
    }
}