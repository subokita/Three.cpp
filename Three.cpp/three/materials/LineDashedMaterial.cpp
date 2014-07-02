//
//  LineDashedMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "LineDashedMaterial.h"

namespace three {
    
    LineDashedMaterial::LineDashedMaterial():
        linewidth   ( 1 ),
        scale       ( 1.0 ),
        dashSize    ( 1 ),
        gapSize     ( 1 ),
        vertexColors( false ),
        fog         ( false ),
        color       ( 0xFFFFFF )
    {}
    
    LineDashedMaterial::LineDashedMaterial( const LineDashedMaterial& rhs ):
        Material    ( rhs ),
        linewidth   ( rhs.linewidth ),
        scale       ( rhs.scale ),
        dashSize    ( rhs.dashSize ),
        gapSize     ( rhs.gapSize ),
        vertexColors( rhs.vertexColors ),
        fog         ( rhs.fog ),
        color       ( rhs.color )
    {}
    
    LineDashedMaterial::~LineDashedMaterial(){
    }
    
    LineDashedMaterial LineDashedMaterial::clone() const{
        return LineDashedMaterial(*this);
    }
}