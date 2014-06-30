//
//  Box2.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Box2.h"
#include "Constants.h"
#include <numeric>

using namespace std;

namespace three {
    
    Box2::Box2() :
        min(glm::vec2( MAX_FLOAT, MAX_FLOAT )),
        max(glm::vec2( MIN_FLOAT, MIN_FLOAT ))
    { }
    
    Box2::Box2( glm::vec2 min_vec, glm::vec2 max_vec ) :
        min( min_vec ),
        max( max_vec )
    {}
    
    Box2::~Box2() {
    }
 
    Box2& Box2::set( glm::vec2 min_vec, glm::vec2 max_vec ) {
        this->min = min_vec;
        this->max = max_vec;
        return *this;
    }
    
    Box2& Box2::setFrom( vector<glm::vec2>& points ) {
        if( points.empty() ) {
            this->makeEmpty();
        }
        else {
            this->min = points[0];
            this->max = points[0];
            
            for( size_t i = 1; i < points.size(); i++ ) {
                if( points[i].x < min.x )
                    min.x = points[i].x;
                else if( points[i].x > max.x )
                    max.x = points[i].x;
                
                if( points[i].y < min.y )
                    min.y = points[i].y;
                else if( points[i].y > max.y )
                    max.y = points[i].y;
            }
        }
        return * this;
    }
    
    
    Box2& Box2::setFrom( glm::vec2 center, glm::vec2 size ) {
        glm::vec2 half_size = size;
        half_size /= 2.0;
        
        this->min = center - half_size;
        this->max = center + half_size;
        
        return *this;
    }
    
    
    Box2& Box2::operator=( const Box2& others ) {
        if( this == &others )
            return *this;
        
        this->min = others.min;
        this->max = others.max;
        return *this;
    }

    bool Box2::empty() {
        return this->max.x < this->min.x || this->max.y < this->min.y ;
    }

    
    glm::vec2 Box2::center() {
        glm::vec2 result = this->min + this->max;
        result *= 0.5;
        return result;
    }

    glm::vec2 Box2::size() {
        return this->max - this->min;
    }
    
    Box2& Box2::expandByPoint(glm::vec2 point) {
        this->min = glm::min( this->min, point );
        this->max = glm::max( this->max, point );
        return *this;
    }
    
    
    Box2& Box2::expandByVector( glm::vec2 vector ) {
        this->min -= vector;
        this->max += vector;
        return *this;
    }
    
    Box2& Box2::expandByScalar( float scalar ) {
        this->min -= scalar;
        this->max += scalar;
        return *this;
    }
    
    bool Box2::contains( glm::vec2 point ) {
        if( point.x < min.x || point.y < min.y || point.x > max.x || point.y > max.y )
            return false;
        return true;
    }
    
    bool Box2::contains( Box2& box ) {
        if (( min.x <= box.min.x ) && (min.y <= box.min.y) && (box.max.x <= max.x) && (box.max.y <= max.y) )
            return true;
        return false;
    }
    
    
    Box2& Box2::makeEmpty() {
        min = glm::vec2( MAX_FLOAT, MAX_FLOAT );
        max = glm::vec2( MIN_FLOAT, MIN_FLOAT );
        return *this;
    }
    
    
    glm::vec2 Box2::getParameter( glm::vec2 point ) {
        return glm::vec2 ( (point.x - min.x) / (max.x - min.x), (point.y - min.y) / (max.y - min.y) );
    }
    
    bool Box2::doesIntersect( Box2& box ) {
        if( box.max.x < min.x || box.min.x > max.x || box.max.y < min.y || box.min.y > max.y )
            return false;
        return true;
    }
    
    glm::vec2 Box2::clamp( glm::vec2 point ) {
        glm::vec2 result = point;
        result = glm::clamp( result, min, max );
        return result;
    }
    
    float Box2::distanceTo( glm::vec2 point ) {
        glm::vec2 v1 = glm::clamp( point, min, max );
        return glm::length(v1 - point);
    }
    
    Box2& Box2::intersects( Box2& box ) {
        this->min = glm::max(this->min, box.min);
        this->max = glm::min(this->max, box.max);
        return *this;
    }
    
    Box2& Box2::unions( Box2& box ) {
        this->min = glm::min( this->min, box.min );
        this->max = glm::max( this->max, box.max );
        return *this;
    }
    
    Box2& Box2::translate( glm::vec2 offset ) {
        min += offset;
        max += offset;
        return *this;
    }
    
    bool Box2::equals( Box2& box ) {
        return box.min == min && box.max == max;
    }
    
    Box2 Box2::clone() {
        return Box2( this->min, this->max );
    }
    
}

