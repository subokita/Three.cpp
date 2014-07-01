//
//  Triangle.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Triangle.h"
#include "Plane.h"
#include <exception>

using namespace std;

namespace three {
    
    Triangle::Triangle():
        a( glm::vec3( 0, 0, 0 )),
        b( glm::vec3( 0, 0, 0 )),
        c( glm::vec3( 0, 0, 0 ))
    {
    }
    
    Triangle::Triangle( glm::vec3 a, glm::vec3 b, glm::vec3 c ) :
        a( a ),
        b( b ),
        c( c )
    {}
    
    
    Triangle::Triangle(const Triangle& rhs) :
        a( rhs.a ),
        b( rhs.b ),
        c( rhs.c )
    {}
    
    Triangle::~Triangle(){
    }
    
    Triangle& Triangle::set( glm::vec3 a, glm::vec3 b, glm::vec3 c ){
        this->a = a;
        this->b = b;
        this->c = c;
        return *this;
    }
    
    glm::vec3 Triangle::normal( glm::vec3 a, glm::vec3 b, glm::vec3 c ){
        glm::vec3 normal;
        normal = glm::cross(c - b, a - b);
        
        /* FIXME: Shouldn't we just use normalize()? */
        float length = glm::length( normal );
        if (length >  0 )
            normal /= length;
        return normal;
    }
    
    /**
     * Barycentric technique for point in triangle test
     * http://www.blackpawn.com/texts/pointinpoly/default.html
     */
    glm::vec3 Triangle::baryCoordFromPoint( glm::vec3 point, glm::vec3 a, glm::vec3 b, glm::vec3 c ){
        glm::vec3 v0 = c - a;
        glm::vec3 v1 = b - a;
        glm::vec3 v2 = point - a;
        
        float dot_00 = glm::dot( v0, v0 );
        float dot_01 = glm::dot( v0, v1 );
        float dot_02 = glm::dot( v0, v2 );
        float dot_11 = glm::dot( v1, v1 );
        float dot_12 = glm::dot( v1, v2 );
        
        float denom = (dot_00 * dot_11 - dot_01 * dot_01 );
        if( denom == 0.0 )
            throw runtime_error( "Unimplemented case where denominator == 0" );
        
        float u = ( dot_11 * dot_02 - dot_01 * dot_12) / denom;
        float v = ( dot_00 * dot_12 - dot_01 * dot_02) / denom;
        
        return glm::vec3( 1 - u - v, v, u );
    }
    
    bool Triangle::containsPoint( glm::vec3 point, glm::vec3 a, glm::vec3 b, glm::vec3 c ){
        glm::vec3 result = baryCoordFromPoint( point, a, b, c );
        return result.x >= 0 && result.y >= 0 && ((result.x + result.y) <= 1.0);
    }
    
    Triangle& Triangle::setFromPointsAndIndices( vector<glm::vec3>& points, int index_0, int index_1, int index_2 ) {
        this->a = points[index_0];
        this->b = points[index_1];
        this->c = points[index_2];
        return *this;
    }
    
    Triangle& Triangle::operator=( const Triangle& rhs ) {
        if( this == &rhs )
            return *this;
        this->a = rhs.a;
        this->b = rhs.b;
        this->c = rhs.c;
        return *this;
    }
    
    float Triangle::area() {
        return glm::length(glm::cross( c-b, a-b)) * 0.5;
    }
    
    
    glm::vec3 Triangle::midpoint() {
        glm::vec3 result = a + b + c;
        result *= 1.0 / 3.0;
        return result;
    }
    
    glm::vec3 Triangle::normal() {
        return Triangle::normal(a, b, c);
    }
    
    
    Plane Triangle::plane() {
        Plane plane;
        plane.setFromCoplanarPoints( a, b, c );
        return plane;
    }
    
    glm::vec3 Triangle::baryCoordFromPoint( glm::vec3 point ) {
        return Triangle::baryCoordFromPoint( point, a, b, c );
    }
    
    bool Triangle::contains( glm::vec3 point ) {
        return Triangle::containsPoint( point, a, b, c );
    }
    
    bool Triangle::equals( Triangle& rhs ){
        return a == rhs.a && b == rhs.b && c == rhs.c;
    }
    
    Triangle Triangle::clone() {
        return Triangle( *this );
    }
    
}