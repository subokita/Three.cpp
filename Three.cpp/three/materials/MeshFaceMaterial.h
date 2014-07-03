//
//  MeshFaceMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshFaceMaterial__
#define __Three_cpp__MeshFaceMaterial__

#include <iostream>
#include "Material.h"

namespace three {
    class MeshFaceMaterial {
    public:
        /** Constructors **/
        MeshFaceMaterial();
        MeshFaceMaterial( const MeshFaceMaterial& rhs );
        MeshFaceMaterial clone();
        ~MeshFaceMaterial();
        
        std::vector<Material> materials;
    };
}

#endif /* defined(__Three_cpp__MeshFaceMaterial__) */
