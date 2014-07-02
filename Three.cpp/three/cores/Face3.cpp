//
//  Face3.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 01/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Face3.h"

using namespace std;

namespace  three {
    
    Face3::Face3() :
        materialIndex( 0 )
    {}
    
    Face3::Face3( glm::vec3& a, glm::vec3& b, glm::vec3& c, glm::vec3& normal,
                 Color& color, int material_index ):
        a            ( a ),
        b            ( b ),
        c            ( c ),
        normal       ( normal ),
        color        ( color ),
        materialIndex( material_index )
    {}
    
    Face3::~Face3(){}
    
    
    Face3::Face3( const Face3& rhs ) :
        a            ( rhs.a ),
        b            ( rhs.b ),
        c            ( rhs.c ),
        normal       ( rhs.normal ),
        color        ( rhs.color ),
        materialIndex( rhs.materialIndex )
    {
        copy( rhs.vertexNormals.begin(), rhs.vertexNormals.end(), back_inserter( vertexNormals ));
        copy( rhs.vertexColors.begin(), rhs.vertexColors.end(), back_inserter( vertexColors ));
        copy( rhs.vertexTangents.begin(), rhs.vertexTangents.end(), back_inserter( vertexTangents ));
    }
    
    Face3 Face3::clone() const{
        return Face3(*this);
    }
}