//
//  Line3.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Line3__
#define __Three_cpp__Line3__

#include <iostream>
#include <glm/glm.hpp>

namespace three {
    class Line3 {
        public:
            Line3();
            Line3( glm::vec3& param_start, glm::vec3& param_end );
            ~Line3();
        
            Line3& set( glm::vec3& param_start, glm::vec3& param_end );
            Line3& operator=( const Line3& other );
            glm::vec3 center();
            glm::vec3 delta();
        
            float distanceSquared();
            float distance();
        
            glm::vec3 at( float t );
            float closestPointToPointParameter( glm::vec3& point, bool clamp_to_line );
            glm::vec3 closestPointToPoint( glm::vec3& point, bool clamp_to_line );
        
            Line3& applyMatrix( glm::mat4x4& mat );
            bool equals( Line3& other );
            Line3 clone();
        
            glm::vec3 start;
            glm::vec3 end;
    };
}

#endif /* defined(__Three_cpp__Line3__) */
