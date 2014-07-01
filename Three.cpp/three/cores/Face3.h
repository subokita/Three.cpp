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

#include "Color.h"

namespace three {
    class Face3 {
        public:
            Face3();
            Face3( const Face3& rhs );
            Face3( glm::vec3& param_a, glm::vec3& param_b, glm::vec3& param_c, glm::vec3& param_normal, Color& param_color, int material_index );
            ~Face3();
            
            Face3 clone();
        
            glm::vec3 a;
            glm::vec3 b;
            glm::vec3 c;
            glm::vec3 normal;
            Color color;
        
            std::vector<glm::vec3> vertexNormals;
            std::vector<glm::vec3> vertexTangents;
            std::vector<Color> vertexColors;
            int materialIndex;
    };
}

#endif /* defined(__Three_cpp__Face3__) */
