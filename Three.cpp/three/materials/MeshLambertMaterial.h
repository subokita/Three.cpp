//
//  MeshLambertMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__MeshLambertMaterial__
#define __Three_cpp__MeshLambertMaterial__

#include <iostream>
#include <glm/glm.hpp>

#include "Material.h"
#include "Texture.h"
#include "Color.h"
#include "Utils.h"


namespace three {
    class MeshLambertMaterial : public Material {
    public:
        /** Constructors **/
        MeshLambertMaterial();
        MeshLambertMaterial( const MeshLambertMaterial& rhs );
        MeshLambertMaterial clone();
        ~MeshLambertMaterial();
        
        /* Data members */
        Color       color;
        Color       ambient;
        Color       emissive;
        bool        wrapAround;
        glm::vec3   wrapRGB;
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
        
        Texture     map;
        Texture     lightMap;
        Texture     specularMap;
        Texture     envMap;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const MeshLambertMaterial& obj ) {
            os << "MeshLambertMaterial {" << std::endl;
            os << "\tcolor             : " << obj.color              << std::endl;
            os << "\tambient           : " << obj.ambient            << std::endl;
            os << "\temissive          : " << obj.emissive           << std::endl;
            os << "\twrapAround        : " << obj.wrapAround         << std::endl;
            os << "\twrapRGB           : " << Utils::toString( obj.wrapRGB ) << std::endl;
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
//            os << "\tmap               : " << obj.map                << std::endl;
//            os << "\tlightMap          : " << obj.lightMap           << std::endl;
//            os << "\tspecularMap       : " << obj.specularMap        << std::endl;
//            os << "\tenvMap            : " << obj.envMap             << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__MeshLambertMaterial__) */
