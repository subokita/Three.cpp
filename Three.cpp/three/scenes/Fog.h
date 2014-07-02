//
//  Fog.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Fog__
#define __Three_cpp__Fog__

#include <iostream>
#include "Color.h"

namespace three {
    class Fog {
        public:
            /** Constructors **/
            Fog();
            Fog( Color& color, float near, float far );
            Fog( const Fog& rhs );
            Fog clone();
            ~Fog();
        
            /* Data members */
            Color color;
            float near;
            float far;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const Fog& obj ) {
                os << "Fog {" << std::endl;
                os << "\tcolor: " << obj.color << std::endl;
                os << "\tnear : " << obj.near  << std::endl;
                os << "\tfar  : " << obj.far   << std::endl;
                os << "}";
                return os;
            }
    };
}

#endif /* defined(__Three_cpp__Fog__) */
