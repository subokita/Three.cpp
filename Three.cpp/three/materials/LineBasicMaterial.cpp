//
//  LineBasicMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 01/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "LineBasicMaterial.h"

namespace three {
    LineBasicMaterial::LineBasicMaterial() :
        Material    (),
        linewidth   ( 1 ),
        linecap     ( "round" ),
        linejoin    ( "round" ),
        vertexColors( false ),
        fog         ( true ),
        color       ( 0xFFFFFF )
    {}
    
    
    LineBasicMaterial::LineBasicMaterial( const LineBasicMaterial& rhs ) :
        Material    ( rhs ),
        linewidth   ( rhs.linewidth ),
        linecap     ( rhs.linecap ),
        linejoin    ( rhs.linejoin ),
        vertexColors( rhs.vertexColors ),
        fog         ( rhs.fog ),
        color       ( rhs.color )
    {}
    
    LineBasicMaterial::~LineBasicMaterial() {}
    
    LineBasicMaterial LineBasicMaterial::clone() const{
        return LineBasicMaterial( *this );
    }
}