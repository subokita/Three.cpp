//
//  MeshDepthMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshDepthMaterial.h"


namespace three {
    
    MeshDepthMaterial::MeshDepthMaterial():
        morphTargets      ( false ),
        wireframe         ( false ),
        wireframeLinewidth( 1 )
    {}
    
    MeshDepthMaterial::MeshDepthMaterial( const MeshDepthMaterial& rhs ):
        Material          ( rhs ),
        morphTargets      ( rhs.morphTargets ),
        wireframe         ( rhs.wireframe ),
        wireframeLinewidth( rhs.wireframeLinewidth )
    {}
    
    MeshDepthMaterial MeshDepthMaterial::clone(){
        return MeshDepthMaterial(*this);
    }
    
    MeshDepthMaterial::~MeshDepthMaterial(){}
}