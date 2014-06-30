//
//  Utils.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Utils__
#define __Three_cpp__Utils__

#include <iostream>
#include <glm/glm.hpp>

namespace three {
    class Utils {
        public:
            static std::string toString( const glm::vec2& vec );
            static std::string toString( const glm::vec3& vec );
            static std::string toString( const glm::vec4& vec );
    };
}

#endif /* defined(__Three_cpp__Utils__) */
