//
//  PointLight.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "PointLight.h"

namespace three {
    
    PointLight::PointLight():
        intensity( 1.0 ),
        distance ( 0.0 )
    {}
    
    PointLight::PointLight( float intensity, float distance ):
        intensity( intensity ),
        distance ( distance )
    {}
    
    PointLight::PointLight( const PointLight& rhs ):
        Light    ( rhs ),
        intensity( rhs.intensity ),
        distance ( rhs.distance )
    {}
    
    PointLight PointLight::clone(){
        return PointLight(*this);
    }
    
    PointLight::~PointLight(){}
}