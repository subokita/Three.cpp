//
//  MeshBasicMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshBasicMaterial__
#define __Three_cpp__MeshBasicMaterial__

#include <iostream>

#include "Material.h"
#include "Texture.h"

namespace three {
    class MeshBasicMaterial : public Material {
        public:
            /** Constructors **/
            MeshBasicMaterial();
            MeshBasicMaterial( const MeshBasicMaterial& rhs );
            MeshBasicMaterial clone();
            ~MeshBasicMaterial();
        
        
            /* Data members */
            int         combine;
            float       reflectivity;
            float       refractionRatio;
            bool        fog;
            int         shading;
            bool        wireframe;
            int         wireframeLineWidth;
            std::string wireframeLinecap;
            std::string wireframeLinejoin;
            int         vertexColors;
            bool        skinning;
            bool        morphTargets;
            Color       color;
            Texture     map;
            Texture     lightMap;
            Texture     specularMap;
            Texture     envMap;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const MeshBasicMaterial& obj ) {
                os << "MeshBasicMaterial {" << std::endl;
                os << "\tcombine           : " << obj.combine            << std::endl;
                os << "\treflectivity      : " << obj.reflectivity       << std::endl;
                os << "\trefractionRatio   : " << obj.refractionRatio    << std::endl;
                os << "\tfog               : " << obj.fog                << std::endl;
                os << "\tshading           : " << obj.shading            << std::endl;
                os << "\twireframe         : " << obj.wireframe          << std::endl;
                os << "\twireframeLineWidth: " << obj.wireframeLineWidth << std::endl;
                os << "\twireframeLinecap  : " << obj.wireframeLinecap   << std::endl;
                os << "\twireframeLinejoin : " << obj.wireframeLinejoin  << std::endl;
                os << "\tvertexColors      : " << obj.vertexColors       << std::endl;
                os << "\tskinning          : " << obj.skinning           << std::endl;
                os << "\tmorphTargets      : " << obj.morphTargets       << std::endl;
                os << "\tcolor             : " << obj.color              << std::endl;
    //            os << "\tmap               : " << obj.map                << std::endl;
    //            os << "\tlightMap          : " << obj.lightMap           << std::endl;
    //            os << "\tspecularMap       : " << obj.specularMap        << std::endl;
    //            os << "\tenvMap            : " << obj.envMap             << std::endl;
                os << "}";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__MeshBasicMaterial__) */
