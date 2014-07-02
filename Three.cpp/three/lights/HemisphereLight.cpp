//
//  HemisphereLight.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "HemisphereLight.h"


namespace three {
    
    HemisphereLight::HemisphereLight():
        intensity( 1.0 )
    {
        /* not possible on initializer list, unless I create special Object3D constructor just for this */
        this->position = glm::vec3(0.0, 100.0, 0.0);
    }
    
    
    HemisphereLight::HemisphereLight( Color& sky_color, Color& ground_color, float intensity ) :
        Light       ( sky_color ),
        groundColor ( ground_color ),
        intensity   ( intensity )
    {
    }
    
    HemisphereLight::HemisphereLight( const HemisphereLight& rhs ) :
        Light      ( rhs ),
        groundColor( rhs.groundColor ),
        intensity  ( rhs.intensity )
    {}
    
    HemisphereLight HemisphereLight::clone(){
        return HemisphereLight( *this );
    }
    
    HemisphereLight::~HemisphereLight(){
    }
}