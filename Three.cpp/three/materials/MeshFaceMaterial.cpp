//
//  MeshFaceMaterial.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "MeshFaceMaterial.h"


namespace three {
    
    /** Constructors **/
    MeshFaceMaterial::MeshFaceMaterial(){
    }
    
    MeshFaceMaterial::MeshFaceMaterial( const MeshFaceMaterial& rhs ){
        std::copy( rhs.materials.begin(), rhs.materials.end(), std::back_inserter(this->materials) );
    }
    
    MeshFaceMaterial MeshFaceMaterial::clone(){
        return MeshFaceMaterial(*this);
    }
    
    MeshFaceMaterial::~MeshFaceMaterial(){}
}