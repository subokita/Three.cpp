//
//  Box3.h
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Box3__
#define __Three_cpp__Box3__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Utils.h"

namespace three {
    class Sphere;
    
    class Box3 {
        public:
            Box3();
            Box3( glm::vec3 min_vec, glm::vec3 max_vec );
            Box3( const Box3& rhs );
            
            ~Box3();
        
            Box3& addPoint( glm::vec3 point );
            Box3& set( glm::vec3 min_vec, glm::vec3 max_vec );
            Box3& setFrom( std::vector<glm::vec4>& points );
            Box3& setFrom( std::vector<glm::vec3>& points );
            Box3& setFrom( glm::vec3 center, glm::vec3 size );
        
            // FIXME: Implement Object3D first
            Box3& setFromObject();
            Box3& makeEmpty();
            
            glm::vec3 center();
            glm::vec3 size();
            
            Box3& expandByPoint( glm::vec3 point );
            Box3& expandByVector( glm::vec3 vector );
            Box3& expandByScalar( float scalar );
            
            bool contains( glm::vec3 point );
            bool contains( Box3& box );
            glm::vec3 getParameter( glm::vec3 point );
            bool doesIntersect( Box3& box );
            glm::vec3 clamp( glm::vec3 point );
            float distanceTo( glm::vec3 point );
        
            Sphere getBoundingSphere();
        
            Box3& intersects( Box3& box );
            Box3& unions( Box3& box );
        
            Box3& applyMatrix(glm::mat4x4& mat);
            Box3& translate( glm::vec3 offset );
            bool equals( Box3& box );
            Box3 clone();
            
            bool empty();
            Box3& operator=( const Box3& rhs );
        
            glm::vec3 min;
            glm::vec3 max;
            
            friend std::ostream &operator <<( std::ostream& os, const Box3& box ) {
                os << Utils::toString( box.min ) << " to " << Utils::toString( box.max );
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Box3__) */
