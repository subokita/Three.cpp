//
//  FogExp2.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "FogExp2.h"


namespace three {
    
    FogExp2::FogExp2():
        distance( 0.00025 )
    {}
    
    FogExp2::FogExp2( Color& color, float distance ) :
        color   ( color ),
        distance( distance )
    {}
    
    FogExp2::FogExp2( const FogExp2& rhs ):
        color   ( rhs.color ),
        distance( rhs.distance )
    {}
    
    FogExp2 FogExp2::clone(){
        return FogExp2(*this);
    }
    
    FogExp2::~FogExp2(){}
}