//
//  AmbientLight.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__AmbientLight__
#define __Three_cpp__AmbientLight__

#include <iostream>
#include "Light.h"

namespace three {
    class AmbientLight: public Light {
    public:
        /** Constructors **/
        AmbientLight();
        AmbientLight(Color& color);
        AmbientLight( const AmbientLight& rhs );
        AmbientLight clone() const;
        ~AmbientLight();
    };
}

#endif /* defined(__Three_cpp__AmbientLight__) */
