//
//  AreaLight.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "AreaLight.h"

namespace three {
    AreaLight::AreaLight():
        normal              ( glm::vec3(0.0, -1.0, 0.0) ),
        right               ( glm::vec3(1.0,  0.0, 0.0) ),
        intensity           ( 1.0 ),
        width               ( 1.0 ),
        height              ( 1.0 ),
        constantAttenuation ( 1.5 ),
        linearAttenuation   ( 0.5 ),
        quadraticAttenuation( 0.1 )
    {}
    
    AreaLight::AreaLight( Color& color, float intensity ) :
        Light               ( color ),
        normal              ( glm::vec3(0.0, -1.0, 0.0) ),
        right               ( glm::vec3(1.0,  0.0, 0.0) ),
        intensity           ( intensity ),
        width               ( 1.0 ),
        height              ( 1.0 ),
        constantAttenuation ( 1.5 ),
        linearAttenuation   ( 0.5 ),
        quadraticAttenuation( 0.1 )
    {
    }
    
    AreaLight::AreaLight( const AreaLight& rhs ):
        Light               ( rhs ),
        normal              ( rhs.normal ),
        right               ( rhs.right ),
        intensity           ( rhs.intensity ),
        width               ( rhs.width ),
        height              ( rhs.height ),
        constantAttenuation ( rhs.constantAttenuation ),
        linearAttenuation   ( rhs.linearAttenuation ),
        quadraticAttenuation( rhs.quadraticAttenuation )
    {}
    
    AreaLight AreaLight::clone() const {
        return AreaLight(*this);
    }
    
    AreaLight::~AreaLight(){}
}