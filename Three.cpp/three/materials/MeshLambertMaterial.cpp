//
//  MeshLambertMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshLambertMaterial.h"
#include "Constants.h"

namespace three {
    
    MeshLambertMaterial::MeshLambertMaterial():
        color             ( 0xFFFFFF ),
        ambient           ( 0xFFFFFF ),
        emissive          ( 0x000000 ),
        wrapAround        ( false ),
        wrapRGB           ( glm::vec3(1.0, 1.0, 1.0) ),
        combine           ( MultiplyOperation ),
        reflectivity      ( 1.0 ),
        refractionRatio   ( 0.98 ),
        fog               ( true ),
        shading           ( SmoothShading ),
        wireframe         ( false ),
        wireframeLinewidth( 1 ),
        wireframeLinecap  ( "round" ),
        wireframeLinejoin ( "round" ),
        vertexColors      ( NoColors ),
        skinning          ( false ),
        morphTargets      ( false ),
        morphNormals      ( false )
    {}
    
    
    MeshLambertMaterial::MeshLambertMaterial( const MeshLambertMaterial& rhs ):
        Material          ( rhs ),
        color             ( rhs.color ),
        ambient           ( rhs.ambient ),
        emissive          ( rhs.emissive ),
        wrapAround        ( rhs.wrapAround ),
        wrapRGB           ( rhs.wrapRGB ),
        combine           ( rhs.combine ),
        reflectivity      ( rhs.reflectivity ),
        refractionRatio   ( rhs.refractionRatio ),
        fog               ( rhs.fog ),
        shading           ( rhs.shading ),
        wireframe         ( rhs.wireframe ),
        wireframeLinewidth( rhs.wireframeLinewidth ),
        wireframeLinecap  ( rhs.wireframeLinecap ),
        wireframeLinejoin ( rhs.wireframeLinejoin ),
        vertexColors      ( rhs.vertexColors ),
        skinning          ( rhs.skinning ),
        morphTargets      ( rhs.morphTargets ),
        morphNormals      ( rhs.morphNormals ),
        map               ( rhs.map ),
        lightMap          ( rhs.lightMap ),
        specularMap       ( rhs.specularMap ),
        envMap            ( rhs.envMap )
    {}
    
    MeshLambertMaterial MeshLambertMaterial::clone(){
        return MeshLambertMaterial(*this);
    }
    
    MeshLambertMaterial::~MeshLambertMaterial(){
    }
}