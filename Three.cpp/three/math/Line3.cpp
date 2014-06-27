//
//  Line3.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Line3.h"
#include "Math.h"

namespace three {
    
    Line3::Line3():
        start(glm::vec3(0, 0, 0)),
        end(glm::vec3(0, 0, 0))
    {
    }
    
    Line3::Line3( glm::vec3& param_start, glm::vec3& param_end ):
        start( param_start ),
        end( param_end )
    {
    }
    
    Line3::~Line3(){
        
    }
    
    Line3& Line3::set( glm::vec3& param_start, glm::vec3& param_end ){
        this->start = param_start;
        this->end   = param_end;
        return *this;
    }
    
    Line3& Line3::operator=( const Line3& other ){
        if( this == &other )
            return *this;
        this->start = other.start;
        this->end   = other.end;
        return *this;
    }
    
    glm::vec3 Line3::center() {
        glm::vec3 result = start + end;
        result *= 0.5;
        return result;
    }
    
    glm::vec3 Line3::delta() {
        return this->end - this->start;
    }
    
    
    float Line3::distanceSquared() {
        float distance = glm::distance( this->start, this->end);
        return distance * distance;
    }
    
    float Line3::distance() {
        return glm::distance( this->start, this->end);
    }
    
    glm::vec3 Line3::at( float t ) {
        return delta() * t + start;
    }
    
    
    float Line3::closestPointToPointParameter( glm::vec3& point, bool clamp_to_line ) {
        glm::vec3 start_point= point - start;
        glm::vec3 start_end  = end - start;
        
        float start_end_squared = glm::dot( start_end, start_end );
        float start_end_dot_start_point = glm::dot( start_end, start_point );
        float t = start_end_dot_start_point / start_end_squared;
        
        return clamp_to_line ? three::Math::clamp( t, 0.0, 1.0 ) : t;
    }
    
    glm::vec3 Line3::closestPointToPoint( glm::vec3& point, bool clamp_to_line ) {
        float t = closestPointToPointParameter( point, clamp_to_line );
        return delta() * t + start;
    }
    
    
    Line3& Line3::applyMatrix( glm::mat4x4& mat ) {
        this->start = glm::vec3(glm::vec4(this->start, 1) * mat);
        this->end   = glm::vec3(glm::vec4(this->end,   1) * mat);
        return *this;
    }
    
    bool Line3::equals( Line3& other ) {
        return start == other.start && end == other.end;
    }
    
    Line3 Line3::clone() {
        return Line3( this->start, this->end );
    }
}