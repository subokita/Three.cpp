//
//  Triangle.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Triangle__
#define __Three_cpp__Triangle__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

namespace three {
    class Plane;
    
    class Triangle {
        public:
            Triangle();
            Triangle( glm::vec3& a, glm::vec3& b, glm::vec3& c );
            ~Triangle();
        
            Triangle& set( glm::vec3& a, glm::vec3& b, glm::vec3& c );
            Triangle& setFromPointsAndIndices( std::vector<glm::vec3>& points, int index_0, int index_1, int index_2 );
            Triangle& operator=( const Triangle& other );
            float area();
            glm::vec3 midpoint();
            glm::vec3 normal();
        
            Plane plane();
            glm::vec3 baryCoordFromPoint( glm::vec3& point );
            bool contains( glm::vec3& point );
            bool equals( Triangle& other );
            Triangle clone();
        
            static glm::vec3 normal( glm::vec3& a, glm::vec3& b, glm::vec3& c );
            static glm::vec3 baryCoordFromPoint( glm::vec3& point, glm::vec3& a, glm::vec3& b, glm::vec3& c );
            static bool containsPoint( glm::vec3& point, glm::vec3& a, glm::vec3& b, glm::vec3& c );
        
            glm::vec3 a;
            glm::vec3 b;
            glm::vec3 c;
    };
}

#endif /* defined(__Three_cpp__Triangle__) */