//
//  AmbientLight.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "AmbientLight.h"


namespace three {
    
    /** Constructors **/
    AmbientLight::AmbientLight()
    {}
    
    AmbientLight::AmbientLight(Color& color) :
        Light(color)
    {}
    
    AmbientLight::AmbientLight( const AmbientLight& rhs ) :
        Light( rhs )
    {}
    
    AmbientLight AmbientLight::clone(){
        return AmbientLight(*this);
    }
    
    AmbientLight::~AmbientLight(){}
}