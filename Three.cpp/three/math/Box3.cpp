//
//  Box3.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Box3.h"
#include "Constants.h"
#include "Sphere.h"
#include <numeric>

using namespace std;

namespace three {
    
    Box3::Box3() :
        min(glm::vec3( MAX_FLOAT, MAX_FLOAT, MAX_FLOAT )),
        max(glm::vec3( MIN_FLOAT, MIN_FLOAT, MIN_FLOAT ))
    { }
    
    
    Box3::Box3( glm::vec3 min_vec, glm::vec3 max_vec ) :
        min( min_vec ),
        max( max_vec )
    {}
    
    Box3::~Box3() {
    }
    
    Box3::Box3( const Box3& rhs ) :
        min(rhs.min),
        max(rhs.max)
    {}
    
    
    Box3& Box3::set( glm::vec3 min_vec, glm::vec3 max_vec ) {
        this->min = min_vec;
        this->max = max_vec;
        return *this;
    }
    
    
    Box3& Box3::addPoint( glm::vec3 point ) {
        if( point.x < min.x )
            min.x = point.x;
        else if( point.x > max.x )
            max.x = point.x;
        
        if( point.y < min.y )
            min.y = point.y;
        else if( point.y > max.y )
            max.y = point.y;
        
        if( point.z < min.z )
            min.z = point.z;
        else if( point.z > max.z )
            max.z = point.z;
        
        return *this;
    }
    
    Box3& Box3::setFrom( vector<glm::vec4>& points ) {
        if( points.empty() ) {
            this->makeEmpty();
        }
        else {
            this->min = glm::vec3(points[0]);
            this->max = glm::vec3(points[0]);
            
            for( size_t i = 1; i < points.size(); i++ ) {
                if( points[i].x < min.x )
                    min.x = points[i].x;
                else if( points[i].x > max.x )
                    max.x = points[i].x;
                
                if( points[i].y < min.y )
                    min.y = points[i].y;
                else if( points[i].y > max.y )
                    max.y = points[i].y;
                
                if( points[i].z < min.z )
                    min.z = points[i].z;
                else if( points[i].z > max.z )
                    max.z = points[i].z;
            }
        }
        return * this;
    }
    
    Box3& Box3::setFrom( vector<glm::vec3>& points ) {
        if( points.empty() ) {
            this->makeEmpty();
        }
        else {
            this->min = points[0];
            this->max = points[0];
            
            for( size_t i = 1; i < points.size(); i++ )
                addPoint( points[i] );
        }
        return * this;
    }
    
    
    Box3& Box3::setFrom( glm::vec3 center, glm::vec3 size ) {
        glm::vec3 half_size = size;
        half_size /= 2.0;
        
        this->min = center - half_size;
        this->max = center + half_size;
        
        return *this;
    }
    
    // FIXME: implement this for Object3D object
    Box3& Box3::setFromObject() {
        throw runtime_error("Not implemented");
    }
    
    
    Box3& Box3::operator=( const Box3& rhs ) {
        if( this == &rhs )
            return *this;
        this->min = rhs.min;
        this->max = rhs.max;
        return *this;
    }
    
    bool Box3::empty() {
        return this->max.x < this->min.x || this->max.y < this->min.y|| this->max.z < this->min.z ;
    }
    
    
    glm::vec3 Box3::center() {
        glm::vec3 result = this->min + this->max;
        result *= 0.5;
        return result;
    }
    
    glm::vec3 Box3::size() {
        return this->max - this->min;
    }
    
    Box3& Box3::expandByPoint(glm::vec3 point) {
        this->min = glm::min( this->min, point );
        this->max = glm::max( this->max, point );
        return *this;
    }
    
    
    Box3& Box3::expandByVector( glm::vec3 vector ) {
        this->min -= vector;
        this->max += vector;
        return *this;
    }
    
    Box3& Box3::expandByScalar( float scalar ) {
        this->min -= scalar;
        this->max += scalar;
        return *this;
    }
    
    bool Box3::contains( glm::vec3 point ) {
        if( point.x < min.x || point.y < min.y || point.z < min.z ||
            point.x > max.x || point.y > max.y || point.z > max.z )
            return false;
        return true;
    }
    
    bool Box3::contains( Box3& box ) {
        if ( (min.x <= box.min.x) && (min.y <= box.min.y) && (min.z <= box.min.z)  &&
             (box.max.x <= max.x) && (box.max.y <= max.y) && (box.max.z <= max.z) )
            return true;
        return false;
    }
    
    
    Box3& Box3::makeEmpty() {
        min = glm::vec3( MAX_FLOAT, MAX_FLOAT, MAX_FLOAT );
        max = glm::vec3( MIN_FLOAT, MIN_FLOAT, MIN_FLOAT );
        return *this;
    }
    
    
    glm::vec3 Box3::getParameter( glm::vec3 point ) {
        return glm::vec3 ( (point.x - min.x) / (max.x - min.x),
                           (point.y - min.y) / (max.y - min.y),
                           (point.z - min.z) / (max.z - min.z) );
    }
    
    bool Box3::doesIntersect( Box3& box ) {
        if( box.max.x < min.x || box.min.x > max.x ||
            box.max.y < min.y || box.min.y > max.y ||
            box.max.z < min.z || box.min.z > max.z )
            return false;
        return true;
    }
    
    glm::vec3 Box3::clamp( glm::vec3 point ) {
        glm::vec3 result = point;
        result = glm::clamp( result, min, max );
        return result;
    }
    
    float Box3::distanceTo( glm::vec3 point ) {
        glm::vec3 v1 = glm::clamp( point, min, max );
        return glm::length( v1 - point );
    }
    
    
    Sphere Box3::getBoundingSphere() {
        Sphere result;
        result.center = this->center();
        result.radius = glm::length(this->size()) * 0.5;
        return result;
    }
    
    // FIXME: Test
    Box3& Box3::applyMatrix( glm::mat4x4& mat ) {
        vector<glm::vec4> points {
            glm::vec4(min.x, min.y, min.z, 1),
            glm::vec4(min.x, min.y, max.z, 1),
            glm::vec4(min.x, max.y, min.z, 1),
            glm::vec4(min.x, max.y, max.z, 1),
            glm::vec4(max.x, min.y, min.z, 1),
            glm::vec4(max.x, min.y, max.z, 1),
            glm::vec4(max.x, max.y, min.z, 1),
            glm::vec4(max.x, max.y, max.z, 1),
        };

        for( int i = 0; i < 8; i++ )
            points[i]  = points[i] * mat;
        
        this->makeEmpty();
        this->setFrom( points );

        return *this;
    }
    
    Box3& Box3::intersects( Box3& box ) {
        this->min = glm::max(this->min, box.min);
        this->max = glm::min(this->max, box.max);
        return *this;
    }
    
    Box3& Box3::unions( Box3& box ) {
        this->min = glm::min( this->min, box.min );
        this->max = glm::max( this->max, box.max );
        return *this;
    }
    
    Box3& Box3::translate( glm::vec3 offset ) {
        min += offset;
        max += offset;
        return *this;
    }
    
    bool Box3::equals( Box3& box ) {
        return box.min == min && box.max == max;
    }
    
    Box3 Box3::clone() {
        return Box3(*this);
    }
    
}

