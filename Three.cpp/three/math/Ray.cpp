//
//  Ray.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Ray.h"
#include "Constants.h"
#include "Sphere.h"
#include "Plane.h"
#include "Box3.h"
#include "Triangle.h"

namespace three {
    Ray::Ray() :
        origin   ( glm::vec3(0, 0, 0) ),
        direction( glm::vec3(0, 0, 0) )
    { }
    
    Ray::Ray( glm::vec3 origin, glm::vec3 direction ):
        origin   ( origin ),
        direction( direction )
    {}
    
    
    Ray::Ray( const Ray& rhs ) :
        origin   ( rhs.origin ),
        direction( rhs.direction )
    {
        
    }
    
    Ray::~Ray() {
    }
    
    Ray& Ray::set( glm::vec3 origin, glm::vec3 direction ){
        this->origin    = origin;
        this->direction = direction;
        return *this;
    }
    
    Ray& Ray::operator=(const Ray& rhs ){
        if( this == &rhs )
            return *this;
        
        this->direction = rhs.direction;
        this->origin    = rhs.origin;
        return *this;
    }
    
    glm::vec3 Ray::at( float t ){
        return (direction * t) + origin;
    }
    
    Ray& Ray::recast( float t ){
        this->origin = this->at(t);
        return *this;
    }
    
    glm::vec3 Ray::closestPointTo( glm::vec3 point ){
        float direction_distance = glm::dot( point - origin, direction );
        
        if( direction_distance < 0.0 )
            return this->origin;
        
        return (this->direction * direction_distance) + origin;
    }
    
    float Ray::distanceTo( glm::vec3 point ){
        float direction_distance = glm::dot( point - origin, direction );
        if( direction_distance < 0.0 )
            return glm::distance( origin, point );
        
        glm::vec3 result = (direction * direction_distance) + origin;
        return glm::distance( result, point );
    }
    
    /**
     * from http://www.geometrictools.com/LibMathematics/Distance/Wm5DistRay3Segment3.cpp
     * It returns the min distance between the ray and the segment
     * defined by v0 and v1
     * It also sets:
     * - The closest point to ray
     * - The closes point to segment
     */
    
    float Ray::distanceSquaredToSegment( glm::vec3 v0, glm::vec3 v1, glm::vec3 point_to_ray, glm::vec3 point_to_segment ) {
        glm::vec3 segment_center = (v0 + v1);
        segment_center *= 0.5;
        
        glm::vec3 segment_direction = glm::normalize(v1 - v0);
        float segment_extent = glm::distance(v0, v1) * 0.5;
        
        glm::vec3 diff = origin - segment_center;
        
        float a01   = -glm::dot( direction, segment_direction );
        float b0    = glm::dot( diff, direction );
        float b1    = - glm::dot( diff, segment_direction );
        float c     = glm::length( diff ) * glm::length( diff );
        float det   = fabsf( 1 - a01 * a01 );
        
        float s0, s1, squared_dist, ext_det;
        
        if( det >= 0.0 ) {
			// The ray and segment are not parallel.
            
            s0 = a01 * b1 - b0;
            s1 = a01 * b0 - b1;
            ext_det = segment_extent * det;
            
            if( s0 >= 0 ) {
                if( s1 >= -ext_det ) {
                    if( s1 <= ext_det ) {
						// region 0
						// Minimum at interior points of ray and segment.
                        
                        float inv_det = 1.0 / det;
                        s0 *= inv_det;
                        s1 *= inv_det;
                        squared_dist = s0 * ( s0 + a01 * s1 + 2 * b0 ) + s1 * ( a01 * s0 + s1 + 2 * b1 ) + c;
                    }
                    else {
                        // region 1
                        s1 = segment_extent;
                        s0 = std::max( 0.0f, -( a01 * s1 + b0) );
                        squared_dist = - s0 * s0 + s1 * ( s1 + 2 * b1 ) + c;
                    }
                }
                else {
                    // region 5
                    s1 = -segment_extent;
                    s0 = std::max( 0.0f, -( a01 * s1 + b0) );
                    squared_dist = - s0 * s0 + s1 * ( s1 + 2 * b1 ) + c;
                }
            }
            else {
                if ( s1 <= -ext_det ) {
                    // region 4
                    s0 = std::max( 0.0f, -(-a01 * segment_extent + b0) );
                    s1 = (s0 > 0.0) ? -segment_extent : std::min( std::max(-segment_extent, -b1), segment_extent );
                    squared_dist = - s0 * s0 + s1 * ( s1 + 2 * b1 ) + c;
                }
                else if (s1 <= ext_det ) {
                    // region 3
                    s0 = 0.0;
                    s1 = std::min( std::max( -segment_extent, -b1 ), segment_extent );
                    squared_dist = s1 * ( s1 + 2 * b1 ) + c;
                }
                else {
                    // region 2
                    s0 = std::max( 0.0f, -(a01 * segment_extent + b0) );
                    s1 = (s0 > 0 ) ? segment_extent : std::min( std::max(-segment_extent, -b1), segment_extent );
                    squared_dist = - s0 * s0 + s1 * ( s1 + 2 * b1 ) + c;
                }
            }
        }
        else {
			// Ray and segment are parallel.
            
            s1 = (a01 > 0 ) ? -segment_extent : segment_extent;
            s0 = std::max( 0.0f, -(a01 * s1 + b0) );
            squared_dist = - s0 * s0 + s1 * ( s1 + 2 * b1 ) + c;
        }
        
        point_to_ray = direction;
        point_to_ray *= s0;
        point_to_ray += origin;
        
        
        point_to_segment = segment_direction;
        point_to_segment *= s1;
        point_to_segment += segment_center;
        
        return squared_dist;
    }
    
    bool Ray::doesIntersect(Sphere& sphere){
        return distanceTo( sphere.center ) <= sphere.radius;
    }
    
    bool Ray::doesIntersect(Plane& plane){
        float dist_to_point = plane.distanceTo( origin );
        
        /* If ray lies on plane */
        if( dist_to_point == 0.0 )
            return true;
        
        float denominator = glm::dot(plane.normal, direction);
        if( denominator * dist_to_point < 0.0 )
            return true;
        
        return false;
    }
    
    bool Ray::doesIntersect( Box3& box ){
        return false;
    }
    
    float Ray::distanceTo( Plane& plane ){
        float denominator = glm::dot( plane.normal, direction );
        if( denominator == 0.0 ) {
            if( plane.distanceTo( origin) == 0.0 )
                return 0.0f;
            
            /* Can't return null, make do with MIN_FLOAT */
            return std::numeric_limits<float>::min();
        }
        
        float t = -( glm::dot(origin, plane.normal) + plane.constant ) / denominator;
        return t >= 0.0 ? t : std::numeric_limits<float>::min();
    }
    
    glm::vec3 Ray::intersects( Plane& plane ){
        float t = distanceTo( plane );
        return at( t );
    }
    
    /**
     * Get the point of intersection between ray and a box
     * http://www.scratchapixel.com/lessons/3d-basic-lessons/lesson-7-intersecting-simple-shapes/ray-box-intersection/
     */
    glm::vec3 Ray::intersects( Box3& box ){
        
        float inverse_direction_x = 1.0 / direction.x,
              inverse_direction_y = 1.0 / direction.y,
              inverse_direction_z = 1.0 / direction.z;
        
        float tx_min, tx_max, ty_min, ty_max, tz_min, tz_max;
        
        if( inverse_direction_x >= 0 ) {
            tx_min = (box.min.x - origin.x) * inverse_direction_x;
            tx_max = (box.max.x - origin.x) * inverse_direction_x;
        }
        else {
            tx_min = (box.max.x - origin.x) * inverse_direction_x;
            tx_max = (box.min.x - origin.x) * inverse_direction_x;
        }
        
        if( inverse_direction_y >= 0 ){
            ty_min = (box.min.y - origin.y) * inverse_direction_y;
            ty_max = (box.max.y - origin.y) * inverse_direction_y;
        }
        else {
            ty_min = (box.max.y - origin.y) * inverse_direction_y;
            ty_max = (box.min.y - origin.y) * inverse_direction_y;
        }

        if (( tx_min > ty_max ) || (ty_min > tx_max) )
            return NULL_VEC3;
        
        if ((ty_min > tx_min || tx_min == NAN ))
            tx_min = ty_min;
        
        if ((ty_max < tx_max || tx_max == NAN ))
            tx_max = ty_max;
        
        if( inverse_direction_z >= 0 ) {
            tz_min = (box.min.z - origin.z) * inverse_direction_z;
            tz_max = (box.max.z - origin.z) * inverse_direction_z;
        }
        else {
            tz_min = (box.max.z - origin.z) * inverse_direction_z;
            tz_max = (box.min.z - origin.z) * inverse_direction_z;
        }

        if (( tx_min > tz_max ) || (tz_min > tx_max) )
            return NULL_VEC3;
        
        if ( tz_min > tx_min || tx_min == NAN )
            tx_min = tz_min;
        
        if ( tz_max < tx_max || tx_max == NAN )
            tx_max = tz_max;

        if ( tx_max < 0.0 )
            return NULL_VEC3;
        
        return at( tx_min >= 0 ? tx_min : tx_max );
    }
    
    // FIXME: Fill this in
    /**
     * http://www.geometrictools.com/LibMathematics/Intersection/Wm5IntrRay3Triangle3.cpp
     */
    glm::vec3 Ray::intersects(Triangle& triangle, bool cull_backface ){

        
        // Solve Q + t*D = b1*E1 + b2*E2 (Q = kDiff, D = ray direction,
        // E1 = kEdge1, E2 = kEdge2, N = Cross(E1,E2)) by
        //   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
        //   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
        //   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
        
        glm::vec3 edge_1 = triangle.b - triangle.a;
        glm::vec3 edge_2 = triangle.c - triangle.a;
        glm::vec3 normal = glm::cross( edge_1, edge_2 );
        
        float dir_dot_normal = glm::dot( direction, normal );
        float sign;
        
        if( dir_dot_normal > 0.0 ) {
            if( cull_backface )
                return NULL_VEC3;
            sign =  1.0;
        }
        else if( dir_dot_normal < 0.0 ) {
            sign = -1.0;
            dir_dot_normal = -dir_dot_normal;
        }
        else {
            return NULL_VEC3;
        }
        
        glm::vec3 diff = origin - triangle.a;
        float b1 = sign * glm::dot( direction, glm::cross(diff, edge_2) );
        if( b1 < 0.0 )
            return NULL_VEC3;
        
        
        float b2 = sign * glm::dot( direction, glm::cross(diff, edge_1) );
        if( b2 < 0.0 )
            return NULL_VEC3;
        
        if( b1 + b2 > dir_dot_normal )
            return NULL_VEC3;
        
        float t = -sign * glm::dot( diff, normal );
        if( t < 0.0 )
            return NULL_VEC3;
        return at( t / dir_dot_normal );
        return glm::vec3(0.0, 0.0, 0.0);
    }
    
    Ray& Ray::applyMatrix( glm::mat4x4& mat ) {
        direction = direction + origin;
        origin = glm::vec3( glm::vec4( origin, 1 ) * mat );
        direction = glm::normalize(direction - origin);
        return *this;
    }
    
    bool Ray::equals(Ray& rhs){
        return origin == rhs.origin && direction == rhs.direction;
    }
    
    Ray Ray::clone() {
        return Ray( *this );
    }
}