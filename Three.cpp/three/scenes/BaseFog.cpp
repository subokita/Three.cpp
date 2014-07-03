//
//  BaseFog.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "BaseFog.h"


namespace three {
    
    BaseFog::BaseFog(){}
    
    BaseFog::BaseFog( Color& color ) :
        color( color )
    {}
    
    BaseFog::BaseFog( const BaseFog& rhs ):
        color( rhs.color )
    {}
    
    BaseFog BaseFog::clone() const{
        return BaseFog(*this);
    }
    
    BaseFog::~BaseFog(){}
}