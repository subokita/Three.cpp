//
//  Spline.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Spline__
#define __Three_cpp__Spline__

#include <iostream>
#include <glm/glm.hpp>
#include <vector>

namespace three {
    class Spline {
        public:
            void initFromArray( std::vector<std::vector<float>>& a );
            glm::vec3 getPoint( float k );
            std::vector<glm::vec3> getControlPoints();
            float interpolate( float p0, float p1, float p2, float p3, float t, float t2, float t3 );
        
            std::vector<glm::vec3> points;
            std::vector<int> c;
        
            glm::vec3 v3;
            float point;
            float intPoint;
            float weight;
            float weightSquared;
            float weightCubed;
            glm::vec3 pointA;
            glm::vec3 pointB;
            glm::vec3 pointC;
            glm::vec3 pointD;
        
    };
}

#endif /* defined(__Three_cpp__Spline__) */
