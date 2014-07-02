//
//  ParticleSystemMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "ParticleSystemMaterial.h"


namespace three {
    
    ParticleSystemMaterial::ParticleSystemMaterial():
        color          ( Color(0xFFFFFF) ),
        size           ( 1.0 ),
        sizeAttenuation( true ),
        vertexColors   ( false ),
        fog            ( true )
    {}
    
    ParticleSystemMaterial::ParticleSystemMaterial( const ParticleSystemMaterial& rhs ):
        Material       ( rhs ),
        color          ( rhs.color ),
        map            ( rhs.map ),
        size           ( rhs.size ),
        sizeAttenuation( rhs.sizeAttenuation ),
        vertexColors   ( rhs.vertexColors ),
        fog            ( rhs.fog )
    {}
    
    ParticleSystemMaterial ParticleSystemMaterial::clone(){
        return ParticleSystemMaterial(*this);
    }
    
    ParticleSystemMaterial::~ParticleSystemMaterial(){}
}