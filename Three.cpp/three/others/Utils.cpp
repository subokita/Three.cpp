//
//  Utils.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Utils.h"


namespace three {
    
    std::string Utils::toString( const glm::vec2& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f)", vec.x, vec.y );
        return std::string( temp );
    }
    
    std::string Utils::toString( const glm::vec3& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f, %.2f)", vec.x, vec.y, vec.z );
        return std::string( temp );
    }
    
    std::string Utils::toString( const glm::vec4& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f, %.2f, %.2f)", vec.x, vec.y, vec.z, vec.w );
        return std::string( temp );
    }
}