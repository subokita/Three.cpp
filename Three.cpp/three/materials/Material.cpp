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
    
    
    Material::Material(const Material& other) {
        this->name                = other.name;
        this->side                = other.side;
        this->opacity             = other.opacity;
        this->transparent         = other.transparent;
        
        this->blending            = other.blending;
        this->blendSrc            = other.blendSrc;
        this->blendDst            = other.blendDst;
        this->blendEquation       = other.blendEquation;
        
        this->depthTest           = other.depthTest;
        this->depthWrite          = other.depthWrite;
        
        this->polygonOffset       = other.polygonOffset;
        this->polygonOffsetFactor = other.polygonOffsetFactor;
        this->polygonOffsetUnits  = other.polygonOffsetUnits;
        
        this->alphaTest           = other.alphaTest;
        
        this->overdraw            = other.overdraw;
        
        this->visible             = other.visible;
    }
    
    Material Material::clone() const{
        return Material ( *this );
    }
    
    //FIXME: dispose()
}