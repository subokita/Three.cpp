//
//  MeshBasicMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshBasicMaterial.h"
#include "Constants.h"

namespace three {
    
    MeshBasicMaterial::MeshBasicMaterial() :
        combine           ( MultiplyOperation ),
        reflectivity      ( 1.0 ),
        refractionRatio   ( 0.98 ),
        fog               ( true ),
        shading           ( SmoothShading ),
        wireframe         ( false ),
        wireframeLineWidth( 1 ),
        wireframeLinecap  ( "round" ),
        wireframeLinejoin ( "round" ),
        vertexColors      ( NoColors ),
        skinning          ( false ),
        morphTargets      ( false ),
        color             ( Color(0xFFFFFF) )
    {}
    
    MeshBasicMaterial::MeshBasicMaterial( const MeshBasicMaterial& rhs ) :
        Material          ( rhs ),
        combine           ( rhs.combine ),
        reflectivity      ( rhs.reflectivity ),
        refractionRatio   ( rhs.refractionRatio ),
        fog               ( rhs.fog ),
        shading           ( rhs.shading ),
        wireframe         ( rhs.wireframe ),
        wireframeLineWidth( rhs.wireframeLineWidth ),
        wireframeLinecap  ( rhs.wireframeLinecap ),
        wireframeLinejoin ( rhs.wireframeLinejoin ),
        vertexColors      ( rhs.vertexColors ),
        skinning          ( rhs.skinning ),
        morphTargets      ( rhs.morphTargets ),
        color             ( rhs.color ),
        map               ( rhs.map ),
        lightMap          ( rhs.lightMap ),
        specularMap       ( rhs.specularMap ),
        envMap            ( rhs.envMap )
    {}
    
    MeshBasicMaterial MeshBasicMaterial::clone(){
        return MeshBasicMaterial(*this);
    }
    
    MeshBasicMaterial::~MeshBasicMaterial(){}
}