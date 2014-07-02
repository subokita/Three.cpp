//
//  MeshPhongMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshPhongMaterial.h"
#include "Constants.h"

namespace three {
    
    MeshPhongMaterial::MeshPhongMaterial():
        color             ( Color(0xFFFFFF) ),
        ambient           ( Color(0xFFFFFF) ),
        emissive          ( Color(0x000000) ),
        specular          ( Color(0x111111) ),
        shininess         ( 30.0 ),
        metal             ( false ),
        wrapAround        ( false ),
        wrapRGB           ( glm::vec3(1.0, 1.0, 1.0) ),
        bumpScale         ( 1.0 ),
        normalScale       ( glm::vec2(1.0, 1.0) ),
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
        skinning          ( false  ),
        morphTargets      ( false ),
        morphNormals      ( false )
    {}
    
    MeshPhongMaterial::MeshPhongMaterial( const MeshPhongMaterial& rhs ):
        Material          ( rhs ),
        color             ( rhs.color ),
        ambient           ( rhs.ambient ),
        emissive          ( rhs.emissive ),
        specular          ( rhs.specular ),
        shininess         ( rhs.shininess ),
        metal             ( rhs.metal ),
        wrapAround        ( rhs.wrapAround ),
        wrapRGB           ( rhs.wrapRGB ),
        map               ( rhs.map ),
        lightMap          ( rhs.lightMap ),
        bumpMap           ( rhs.bumpMap ),
        bumpScale         ( rhs.bumpScale ),
        normalMap         ( rhs.normalMap ),
        normalScale       ( rhs.normalScale ),
        specularMap       ( rhs.specularMap ),
        envMap            ( rhs.envMap ),
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
        morphNormals      ( rhs.morphNormals )
    {}
    
    MeshPhongMaterial MeshPhongMaterial::clone(){
        return MeshPhongMaterial(*this);
    }
    
    MeshPhongMaterial::~MeshPhongMaterial(){}
}