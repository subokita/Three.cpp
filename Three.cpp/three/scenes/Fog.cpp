//
//  Fog.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Fog.h"


namespace three {
    Fog::Fog():
        near ( 1.0 ),
        far  ( 1000.0 )
    {}
    
    Fog::Fog( Color& color, float near, float far ){}
    
    Fog::Fog( const Fog& rhs ):
        color( rhs.color ),
        near ( rhs.near ),
        far  ( rhs.far )
    {}
    
    
    Fog Fog::clone(){
        return Fog(*this);
    }
    
    Fog::~Fog(){}
    
}