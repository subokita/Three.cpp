//
//  MeshPhongMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshPhongMaterial__
#define __Three_cpp__MeshPhongMaterial__

#include <iostream>
#include "Material.h"
#include "Texture.h"
#include "Utils.h"

namespace three {
    class MeshPhongMaterial: public Material {
        public:
            /** Constructors **/
            MeshPhongMaterial();
            MeshPhongMaterial( const MeshPhongMaterial& rhs );
            MeshPhongMaterial clone();
            ~MeshPhongMaterial();

            /* Data members */
            Color       color;
            Color       ambient;
            Color       emissive;
            Color       specular;
            float       shininess;
            bool        metal;
            bool        wrapAround;
            glm::vec3   wrapRGB;
            Texture     map;
            Texture     lightMap;
            Texture     bumpMap;
            float       bumpScale;
            Texture     normalMap;
            glm::vec2   normalScale;
            Texture     specularMap;
            Texture     envMap;
            int         combine;
            float       reflectivity;
            float       refractionRatio;
            bool        fog;
            int         shading;
            bool        wireframe;
            int         wireframeLinewidth;
            std::string wireframeLinecap;
            std::string wireframeLinejoin;
            int         vertexColors;
            bool        skinning;
            bool        morphTargets;
            bool        morphNormals;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const MeshPhongMaterial& obj ) {
                os << "MeshPhongMaterial {" << std::endl;
                os << "\tcolor             : " << obj.color              << std::endl;
                os << "\tambient           : " << obj.ambient            << std::endl;
                os << "\temissive          : " << obj.emissive           << std::endl;
                os << "\tspecular          : " << obj.specular           << std::endl;
                os << "\tshininess         : " << obj.shininess          << std::endl;
                os << "\tmetal             : " << obj.metal              << std::endl;
                os << "\twrapAround        : " << obj.wrapAround         << std::endl;
                os << "\twrapRGB           : " << Utils::toString( obj.wrapRGB ) << std::endl;
    //            os << "\tmap               : " << obj.map                << std::endl;
    //            os << "\tlightMap          : " << obj.lightMap           << std::endl;
    //            os << "\tbumpMap           : " << obj.bumpMap            << std::endl;
                os << "\tbumpScale         : " << obj.bumpScale          << std::endl;
    //            os << "\tnormalMap         : " << obj.normalMap          << std::endl;
                os << "\tnormalScale       : " << Utils::toString( obj.normalScale ) << std::endl;
    //            os << "\tspecularMap       : " << obj.specularMap        << std::endl;
    //            os << "\tenvMap            : " << obj.envMap             << std::endl;
                os << "\tcombine           : " << obj.combine            << std::endl;
                os << "\treflectivity      : " << obj.reflectivity       << std::endl;
                os << "\trefractionRatio   : " << obj.refractionRatio    << std::endl;
                os << "\tfog               : " << obj.fog                << std::endl;
                os << "\tshading           : " << obj.shading            << std::endl;
                os << "\twireframe         : " << obj.wireframe          << std::endl;
                os << "\twireframeLinewidth: " << obj.wireframeLinewidth << std::endl;
                os << "\twireframeLinecap  : " << obj.wireframeLinecap   << std::endl;
                os << "\twireframeLinejoin : " << obj.wireframeLinejoin  << std::endl;
                os << "\tvertexColors      : " << obj.vertexColors       << std::endl;
                os << "\tskinning          : " << obj.skinning           << std::endl;
                os << "\tmorphTargets      : " << obj.morphTargets       << std::endl;
                os << "\tmorphNormals      : " << obj.morphNormals       << std::endl;
                os << "}";
                return os;
        }
    };
}

#endif /* defined(__Three_cpp__MeshPhongMaterial__) */
