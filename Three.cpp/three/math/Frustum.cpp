//
//  Frustum.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Frustum.h"
#include "Sphere.h"
#include "Box3.h"

using namespace std;

namespace three {
    
    Frustum::Frustum() :
        planes(vector<Plane>(6))
    {}
    
    Frustum::Frustum( Plane& param_p0, Plane& param_p1, Plane& param_p2,
                      Plane& param_p3, Plane& param_p4, Plane& param_p5 )
    
    {
        planes = vector<Plane>(6);
        planes[0] = param_p0;
        planes[1] = param_p1;
        planes[2] = param_p2;
        planes[3] = param_p3;
        planes[4] = param_p4;
        planes[5] = param_p5;
    }
    
    Frustum::~Frustum(){}
    
    Frustum& Frustum::set( Plane& p0, Plane& p1, Plane& p2, Plane& p3, Plane& p4, Plane& p5 ){
        planes[0] = p0;
        planes[1] = p1;
        planes[2] = p2;
        planes[3] = p3;
        planes[4] = p4;
        planes[5] = p5;
        return *this;
    }
    
    Frustum& Frustum::operator=( const Frustum& other ){
        for( int i = 0; i < 6; i++ )
            planes[i] = other.planes[i];
        return *this;
    }
    
    Frustum& Frustum::setFrom( glm::mat4x4& m ){
        
        planes[0].set( m[3][0] - m[0][0], m[3][1] - m[0][1], m[3][2] - m[0][2], m[3][3] - m[0][3]).normalize();
        planes[1].set( m[3][0] + m[0][0], m[3][1] + m[0][1], m[3][2] + m[0][2], m[3][3] + m[0][3]).normalize();
        
        planes[2].set( m[3][0] + m[1][0], m[3][1] + m[1][1], m[3][2] + m[1][2], m[3][3] + m[1][3]).normalize();
        planes[3].set( m[3][0] - m[1][0], m[3][1] - m[1][1], m[3][2] - m[1][2], m[3][3] - m[1][3]).normalize();

        planes[4].set( m[3][0] + m[2][0], m[3][1] + m[2][1], m[3][2] + m[2][2], m[3][3] + m[2][3]).normalize();
        planes[5].set( m[3][0] - m[2][0], m[3][1] - m[2][1], m[3][2] - m[2][2], m[3][3] - m[2][3]).normalize();
        
        return *this;
    }
    
    //FIXME: intersectsObject
    
    bool Frustum::intersects( Sphere& sphere ){
        for( int i = 0; i < 6; i++ ) {
            float distance = planes[i].distanceTo( sphere.center );
            if( distance < -sphere.radius )
                return false;
        }
        return true;
    }
    
    bool Frustum::intersects( Box3& box ){
        glm::vec3 p1, p2;
        
        for( int i = 0; i < 6; i++ ) {
            p1.x = planes[i].normal.x > 0 ? box.min.x : box.max.x;
            p2.x = planes[i].normal.x > 0 ? box.max.x : box.min.x;
            
            p1.y = planes[i].normal.y > 0 ? box.min.y : box.max.y;
            p2.y = planes[i].normal.y > 0 ? box.max.y : box.min.y;
            
            p1.z = planes[i].normal.z > 0 ? box.min.z : box.max.z;
            p2.z = planes[i].normal.z > 0 ? box.max.z : box.min.z;
            
            float d1 = planes[i].distanceTo( p1 );
            float d2 = planes[i].distanceTo( p2 );
            
            if( d1 < 0.0 && d2 < 0.0 )
                return false;
        }
        
        return true;
    }
    
    
    bool Frustum::contains( glm::vec3 point ){
        for( int i = 0; i < 6; i++ ) {
            if( planes[i].distanceTo( point ) < 0.0 )
                return false;
        }
        return true;
    }
    
    
    Frustum Frustum::clone(){
        Frustum result = *this;
        return result;
    }
}