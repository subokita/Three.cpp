//
//  MeshDepthMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshDepthMaterial__
#define __Three_cpp__MeshDepthMaterial__

#include <iostream>
#include "Material.h"

namespace three {
    class MeshDepthMaterial: public Material {
        public:
            /** Constructors **/
            MeshDepthMaterial();
            MeshDepthMaterial( const MeshDepthMaterial& rhs );
            MeshDepthMaterial clone();
            ~MeshDepthMaterial();
        
            /* Data members */
            bool morphTargets;
            bool wireframe;
            int  wireframeLinewidth;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const MeshDepthMaterial& obj ) {
                os << "MeshDepthMaterial {" << std::endl;
                os << "\tmorphTargets      : " << obj.morphTargets       << std::endl;
                os << "\twireframe         : " << obj.wireframe          << std::endl;
                os << "\twireframeLinewidth: " << obj.wireframeLinewidth << std::endl;
                os << "}";
                return os;
            }

    };
}

#endif /* defined(__Three_cpp__MeshDepthMaterial__) */
