//
//  Plane.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Plane__
#define __Three_cpp__Plane__

#include <iostream>
#include <glm/glm.hpp>
#include "Utils.h"

namespace three {
    class Sphere;
    class Line3;
    
    class Plane {
        public:
            Plane();
            Plane( glm::vec3 param_normal, float param_constant );
            ~Plane();
        
            Plane& set( glm::vec3 normal, float constant );
            Plane& set( float x, float y, float z, float w );
            Plane& setFromNormalAndCoplanarPoint( glm::vec3 normal, glm::vec3 point );
            Plane& setFromCoplanarPoints( glm::vec3 a, glm::vec3 b, glm::vec3 c );
            Plane& operator=( const Plane& other );
            Plane& normalize();
            Plane& negate();
            float distanceTo( glm::vec3 point );
            float distanceTo( Sphere& sphere );
        
            glm::vec3 orthoPoint( glm::vec3 point );
            glm::vec3 projectPoint( glm::vec3 point );
            bool intersects(Line3& line);
            glm::vec3 intersectLine(Line3& line);
            glm::vec3 coplanarPoint();
            Plane& applyMatrix( glm::mat4x4& mat );
        
            Plane& translate(glm::vec3 offset);
            bool equals(Plane& other );
        
            Plane clone();
        
            glm::vec3 normal;
            float constant;
        
        
            friend std::ostream &operator <<( std::ostream& os, const Plane& plane ) {
                os << Utils::toString( plane.normal ) << " constant: " << plane.constant;
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Plane__) */
