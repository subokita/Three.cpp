//
//  Light.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Light__
#define __Three_cpp__Light__

#include <iostream>

#include "Color.h"
#include "Object3D.h"

namespace three {
    class Light : public Object3D {
    public:
        /** Constructors **/
        Light();
        Light( Color& color );
        Light( const Light& rhs );
        Light clone();
        ~Light();
    
        /* Data members */
        Color color;
        std::shared_ptr<Object3D> target;
    
        // FIXME: Is it Light or Object3D?
        std::vector<std::shared_ptr<Light>> shadowCascadeArray;
    
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const Light& obj ) {
            os << "Light {" << std::endl;
            os << "\tcolor: " << obj.color << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__Light__) */
