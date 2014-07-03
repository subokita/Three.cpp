//
//  RenderableFace.h
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__RenderableFace__
#define __Three_cpp__RenderableFace__

#include <iostream>
#include "RenderableVertex.h"
#include "Color.h"
#include "Material.h"
#include "Utils.h"

namespace  three  {
    class RenderableFace {
    public:
        /** Constructors **/
        RenderableFace();
        RenderableFace( const RenderableFace& rhs );
        RenderableFace clone();
        ~RenderableFace();
        
        RenderableFace& operator=( const RenderableFace& rhs );

        
        /* Data members */
        int                    id;
        RenderableVertex       v1;
        RenderableVertex       v2;
        RenderableVertex       v3;
        glm::vec3              normalModel;
        std::vector<glm::vec3> vertexNormalsModel;
        int                    vertexNormalsLength;
        Color                  color;
        Material               material;
        std::vector<glm::vec2> uvs;
        float                  z;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const RenderableFace& obj ) {
            os << "RenderableFace {" << std::endl;
            os << "\tid                 : " << obj.id                  << std::endl;
            os << "\tv1                 : " << obj.v1                  << std::endl;
            os << "\tv2                 : " << obj.v2                  << std::endl;
            os << "\tv3                 : " << obj.v3                  << std::endl;
            os << "\tnormalModel        : " << Utils::toString( obj.normalModel ) << std::endl;
            os << "\tvertexNormalsModel : " << Utils::toString(obj.vertexNormalsModel)  << std::endl;
            os << "\tvertexNormalsLength: " << obj.vertexNormalsLength << std::endl;
            os << "\tcolor              : " << obj.color               << std::endl;
            os << "\tmaterial           : " << obj.material            << std::endl;
            os << "\tuvs                : " << Utils::toString(obj.uvs) << std::endl;
            os << "\tz                  : " << obj.z                   << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__RenderableFace__) */
