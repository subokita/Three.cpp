//
//  Utils.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Utils.h"
#include <sstream>
#include <glm/gtc/quaternion.hpp>

using namespace std;

namespace three {
    
    
    string Utils::toString( const vector<int>& vec ) {
        stringstream ss;
        ss << "[";
        for( int i = 0; i < vec.size() - 1; i++ )
            ss << i << ", ";
        ss << vec[vec.size()-1] << "]";
        return ss.str();
    }
    
    string Utils::toString( const vector<float>& vec ) {
        stringstream ss;
        ss << "[";
        for( int i = 0; i < vec.size() - 1; i++ )
            ss << i << ", ";
        ss << vec[vec.size()-1] << "]";
        return ss.str();
    }
    
    
    string Utils::toString( const vector<glm::vec2>& vec ) {
        stringstream ss;
        ss << "[";
        for( int i = 0; i < vec.size() - 1; i++ )
            ss << Utils::toString( vec[i] ) << ", ";
        ss << Utils::toString(vec[vec.size()-1]) << "]";
        return ss.str();
    }
    
    string Utils::toString( const vector<glm::vec3>& vec ) {
        stringstream ss;
        ss << "[";
        for( int i = 0; i < vec.size() - 1; i++ )
            ss << Utils::toString( vec[i] ) << ", ";
        ss << Utils::toString(vec[vec.size()-1]) << "]";
        return ss.str();
    }
    
    string Utils::toString( const glm::vec2& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f)", vec.x, vec.y );
        return string( temp );
    }
    
    string Utils::toString( const glm::vec3& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f, %.2f)", vec.x, vec.y, vec.z );
        return string( temp );
    }
    
    string Utils::toString( const glm::vec4& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f, %.2f, %.2f)", vec.x, vec.y, vec.z, vec.w );
        return string( temp );
    }
    
    string Utils::toString( const glm::quat& vec ) {
        char temp[100];
        sprintf( temp, "(%.2f, %.2f, %.2f, %.2f)", vec.x, vec.y, vec.z, vec.w );
        return string( temp );
    }
    
    string Utils::toString( const glm::mat4x4& mat ) {
        char temp[255];
        sprintf( temp, "|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|\n|%6.2f %6.2f %6.2f %6.2f|",
                mat[0][0], mat[0][1], mat[0][2], mat[0][3],
                mat[1][0], mat[1][1], mat[1][2], mat[1][3],
                mat[2][0], mat[2][1], mat[2][2], mat[2][3],
                mat[3][0], mat[3][1], mat[3][2], mat[3][3] );
        return string( temp );
    }
}