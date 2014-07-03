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
#include <vector>
#include <glm/glm.hpp>

namespace three {
    class Utils {
    public:
    
        static std::string toString( const std::vector<int>& vec );
        static std::string toString( const std::vector<float>& vec );
        
        static std::string toString( const std::vector<glm::vec2>& vec );
        static std::string toString( const std::vector<glm::vec3>& vec );
        
        static std::string toString( const glm::vec2& vec );
        static std::string toString( const glm::vec3& vec );
        static std::string toString( const glm::vec4& vec );
        static std::string toString( const glm::quat& vec );
        static std::string toString( const glm::mat4x4& mat );
    };
}

#endif /* defined(__Three_cpp__Utils__) */
