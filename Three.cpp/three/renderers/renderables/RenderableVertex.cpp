//
//  RenderableVertex.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "RenderableVertex.h"


namespace three {
    
    RenderableVertex::RenderableVertex():
        visible(true)
    {}
    
    RenderableVertex::RenderableVertex( const RenderableVertex& rhs ):
        position      ( rhs.position ),
        positionWorld ( rhs.positionWorld ),
        positionScreen( rhs.positionScreen ),
        visible       ( rhs.visible ){
    }
    
    RenderableVertex RenderableVertex::clone(){
        return RenderableVertex(*this);
    }
    RenderableVertex::~RenderableVertex(){
    }
    
    RenderableVertex& RenderableVertex::operator=( const RenderableVertex& rhs ){
        this->position       = rhs.position;
        this->positionWorld  = rhs.positionWorld;
        this->positionScreen = rhs.positionScreen;
        this->visible        = rhs.visible;
        return *this;
    }
}