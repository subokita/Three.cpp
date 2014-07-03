//
//  RenderableFace.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "RenderableFace.h"


namespace three {
    
    RenderableFace::RenderableFace():
        id                 ( 0 ),
        vertexNormalsModel ( { glm::vec3(), glm::vec3(), glm::vec3() } ),
        vertexNormalsLength( 0 ),
        uvs                ( { glm::vec2(), glm::vec2(), glm::vec2() } ),
        z                  ( 0 )
    {}
    
    RenderableFace::RenderableFace( const RenderableFace& rhs ):
        id                 ( rhs.id ),
        v1                 ( rhs.v1 ),
        v2                 ( rhs.v2 ),
        v3                 ( rhs.v3 ),
        normalModel        ( rhs.normalModel ),
        vertexNormalsModel ( rhs.vertexNormalsModel ),
        vertexNormalsLength( rhs.vertexNormalsLength ),
        color              ( rhs.color ),
        material           ( rhs.material ),
        uvs                ( rhs.uvs ),
        z                  ( rhs.z )
    {}
    
    RenderableFace RenderableFace::clone(){
        return RenderableFace( *this );
    }
    
    RenderableFace::~RenderableFace(){}
    
    RenderableFace& RenderableFace::operator=( const RenderableFace& rhs ) {
        this->id                  = rhs.id;
        this->v1                  = rhs.v1;
        this->v2                  = rhs.v2;
        this->v3                  = rhs.v3;
        this->normalModel         = rhs.normalModel;
        this->vertexNormalsModel  = rhs.vertexNormalsModel;
        this->vertexNormalsLength = rhs.vertexNormalsLength;
        this->color               = rhs.color;
        this->material            = rhs.material;
        this->uvs                 = rhs.uvs;
        this->z                   = rhs.z;
        return *this;
    }
    
    
    
    
    
    
    
}