//
//  Ray.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Ray__
#define __Three_cpp__Ray__

#include <iostream>
#include <glm/glm.hpp>
#include "Utils.h"
#include "Plane.h"

namespace three {
    class Plane;
    class Box3;
    class Sphere;
    class Triangle;
    
    class Ray{
        public:
            Ray();
            Ray( glm::vec3 param_origin, glm::vec3 param_direction );
            ~Ray();
        
            Ray& set( glm::vec3 origin, glm::vec3 direction );
            Ray& operator=(const Ray& other );
            glm::vec3 at( float t );
            Ray& recast( float t );
            glm::vec3 closestPointTo( glm::vec3 point );
            float distanceTo( glm::vec3 point );
        
            float distanceSquaredToSegment( glm::vec3 v0, glm::vec3 v1, glm::vec3 point_to_ray, glm::vec3 point_to_segment );
        
            bool doesIntersect(Sphere& sphere);
            bool doesIntersect(Plane& plane);
            bool doesIntersect( Box3& box );
            float distanceTo( Plane& plane );
            glm::vec3 intersects( Plane& plane );
            glm::vec3 intersects( Box3& box );
            glm::vec3 intersects(Triangle& triangle, bool cull_backface );
        
            Ray& applyMatrix( glm::mat4x4& mat );
            bool equals(Ray& other);
            Ray clone();
        
            glm::vec3 origin;
            glm::vec3 direction;
        
            friend std::ostream &operator <<( std::ostream& os, const Ray& ray ) {
                os  << "origin: " << Utils::toString( ray.origin )
                    << " direction: " << Utils::toString( ray.direction );
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Ray__) */
