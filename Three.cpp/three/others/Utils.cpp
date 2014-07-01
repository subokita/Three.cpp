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
    
    std::string Utils::toString( const glm::mat4x4& mat ) {
        char temp[255];
        sprintf( temp, "|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|",
                mat[0][0], mat[0][1], mat[0][2], mat[0][3],
                mat[1][0], mat[1][1], mat[1][2], mat[1][3],
                mat[2][0], mat[2][1], mat[2][2], mat[2][3],
                mat[3][0], mat[3][1], mat[3][2], mat[3][3] );
        return std::string( temp );
    }
}