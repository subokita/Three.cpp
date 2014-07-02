//
//  Light.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Light.h"


namespace three {
    
    Light::Light(){}
    
    
    Light::Light( Color& color ) :
        color(color )
    {}
    
    Light::Light( const Light& rhs ) :
        Object3D( rhs ),
        color( rhs.color )
    {}
    
    
    Light Light::clone(){
        return Light(*this);
    }
    
    Light::~Light(){}
}