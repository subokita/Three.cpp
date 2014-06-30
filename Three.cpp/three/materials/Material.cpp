//
//  Material.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Material.h"


namespace three {
    Material::Material() {
        // FIXME: should be in initializer list
        id                  = MaterialIDCount++;
        uuid                = Math::generateUUID();
        
        side                = three::FrontSide;
        opacity             = 1.0;
        transparent         = false;
        
        blending            = three::NormalBlending;
        blendSrc            = three::SrcAlphaFactor;
        blendDst            = three::OneMinusSrcAlphaFactor;
        blendEquation       = three::AddEquation;
        
        depthTest           = true;
        depthWrite          = true;
        
        polygonOffset       = false;
        polygonOffsetFactor = 0.0;
        polygonOffsetUnits  = 0.0;
        
        alphaTest           = 0.0;
        overdraw            = 0.0;
        
        visible             = true;
        needsUpdate         = true;
    }
    
    Material::~Material() {
        
    }
    
    
    Material Material::clone() {
        Material mat;
        
        mat.name                = name;
        mat.side                = side;
        mat.opacity             = opacity;
        mat.transparent         = transparent;
        
        mat.blending            = blending;
        mat.blendSrc            = blendSrc;
        mat.blendDst            = blendDst;
        mat.blendEquation       = blendEquation;
        
        mat.depthTest           = depthTest;
        mat.depthWrite          = depthWrite;
        
        mat.polygonOffset       = polygonOffset;
        mat.polygonOffsetFactor = polygonOffsetFactor;
        mat.polygonOffsetUnits  = polygonOffsetUnits;
        
        mat.alphaTest           = alphaTest;
        
        mat.overdraw            = overdraw;
        
        mat.visible             = visible;
        return mat;
    }
    
    //FIXME: dispose()
}