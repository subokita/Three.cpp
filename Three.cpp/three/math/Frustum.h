//
//  Frustum.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Frustum__
#define __Three_cpp__Frustum__

#include <iostream>
#include "Utils.h"
#include "Plane.h"

#include <glm/glm.hpp>
#include <vector>

namespace three {
    class Sphere;
    class Box3;
    
    class Frustum {
        public:
            Frustum();
            Frustum( Plane& param_p0, Plane& param_p1, Plane& param_p2, Plane& param_p3, Plane& param_p4, Plane& param_p5 );
            ~Frustum();
            
            Frustum& set( Plane& p0, Plane& p1, Plane& p2, Plane& p3, Plane& p4, Plane& p5 );
            Frustum& operator=( const Frustum& other );
            Frustum& setFrom( glm::mat4x4& mat );
        
            //FIXME: intersectsObject
            bool intersects( Sphere& sphere );
            bool intersects( Box3& box );
            bool contains( glm::vec3 point );
            Frustum clone();
        
            std::vector<Plane> planes;
        
        
            friend std::ostream &operator <<( std::ostream& os, const Frustum& frustum ) {
                for( int i = 0; i < 6; i++ )
                    os << frustum.planes[i] << std::endl;
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Frustum__) */
