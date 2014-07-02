//
//  MeshNormalMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshNormalMaterial__
#define __Three_cpp__MeshNormalMaterial__

#include <iostream>
#include "Material.h"

namespace three {
    class MeshNormalMaterial : public Material {
        public:
            /** Constructors **/
            MeshNormalMaterial();
            MeshNormalMaterial( const MeshNormalMaterial& rhs );
            MeshNormalMaterial clone();
            ~MeshNormalMaterial();
            
            /* Data members */
            int  shading;
            bool wireframe;
            int  wireframeLinewidth;
            bool morphTargets;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const MeshNormalMaterial& obj ) {
                os << "MeshNormalMaterial {" << std::endl;
                os << "\tshading           : " << obj.shading            << std::endl;
                os << "\twireframe         : " << obj.wireframe          << std::endl;
                os << "\twireframeLinewidth: " << obj.wireframeLinewidth << std::endl;
                os << "\tmorphTargets      : " << obj.morphTargets       << std::endl;
                os << "}";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__MeshNormalMaterial__) */
