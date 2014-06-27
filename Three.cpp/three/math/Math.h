//
//  Math.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Math__
#define __Three_cpp__Math__

#include <iostream>
#include <glm/glm.hpp>

namespace three {
    class Math {
    public:
        static float getMaxScaleOnAxis( glm::mat4x4& mat );
    };
}

#endif /* defined(__Three_cpp__Math__) */
