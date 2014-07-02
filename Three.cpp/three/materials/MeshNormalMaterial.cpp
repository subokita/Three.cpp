//
//  MeshNormalMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshNormalMaterial.h"
#include "Constants.h"

namespace three {
    
    MeshNormalMaterial::MeshNormalMaterial():
        shading           ( FlatShading ),
        wireframe         ( false ),
        wireframeLinewidth( 1 ),
        morphTargets      ( false )
    {}
    
    MeshNormalMaterial::MeshNormalMaterial( const MeshNormalMaterial& rhs ):
        Material          ( rhs ),
        shading           ( rhs.shading ),
        wireframe         ( rhs.wireframe ),
        wireframeLinewidth( rhs.wireframeLinewidth ),
        morphTargets      ( rhs.morphTargets )
    {}
    
    MeshNormalMaterial MeshNormalMaterial::clone(){
        return MeshNormalMaterial(*this);
    }
    
    MeshNormalMaterial::~MeshNormalMaterial(){}
}