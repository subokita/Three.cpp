//
//  Face3.h
//  Three.cpp
//
//  Created by Saburo Okita on 01/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Face3__
#define __Three_cpp__Face3__

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "Utils.h"
#include "Color.h"

namespace three {
    class Face3 {
    public:
        Face3();
        Face3( const Face3& rhs );
        Face3( glm::vec3& a, glm::vec3& b, glm::vec3& c, glm::vec3& normal, Color& color, int material_index );
        ~Face3();
        
        Face3 clone() const;
    
        /* Data members */
        glm::vec3 a;
        glm::vec3 b;
        glm::vec3 c;
        glm::vec3 normal;
        Color     color;
        int       materialIndex;
    
        std::vector<glm::vec3> vertexNormals;
        std::vector<glm::vec3> vertexTangents;
        std::vector<Color> vertexColors;
    
        
        // FIXME: print the normals, tangents and colors too
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const Face3& obj ) {
            os << "Face3 {" << std::endl;
            os << "\ta            : " << Utils::toString( obj.a            ) << std::endl;
            os << "\tb            : " << Utils::toString( obj.b            ) << std::endl;
            os << "\tc            : " << Utils::toString( obj.c            ) << std::endl;
            os << "\tnormal       : " << Utils::toString( obj.normal       ) << std::endl;
            os << "\tcolor        : " << obj.color         << std::endl;
            os << "\tmaterialIndex: " << obj.materialIndex << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__Face3__) */
