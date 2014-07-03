//
//  RenderableVertex.h
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__RenderableVertex__
#define __Three_cpp__RenderableVertex__

#include <iostream>
#include <glm/glm.hpp>

#include "Utils.h"

namespace three {
    class RenderableVertex {
    public:
        /** Constructors **/
        RenderableVertex();
        RenderableVertex( const RenderableVertex& rhs );
        RenderableVertex clone();
        ~RenderableVertex();
        
        RenderableVertex& operator=( const RenderableVertex& rhs );
        
        glm::vec3 position;
        glm::vec3 positionWorld;
        glm::vec4 positionScreen;
        bool      visible;
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const RenderableVertex& obj ) {
            os << "RenderableVertex {" << std::endl;
            os << "\tposition      : " << Utils::toString( obj.position ) << std::endl;
            os << "\tpositionWorld : " << Utils::toString( obj.positionWorld ) << std::endl;
            os << "\tpositionScreen: " << Utils::toString( obj.positionScreen ) << std::endl;
            os << "\tvisible       : " << obj.visible        << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__RenderableVertex__) */
