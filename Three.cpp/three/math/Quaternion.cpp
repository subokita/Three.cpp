//
//  Quaternion.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 29/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Quaternion.h"
#include "Euler.h"

using namespace std;

namespace three {
    Quaternion::Quaternion() :
        x(0),
        y(0),
        z(0),
        w(1)
    {
    }
    
    Quaternion::~Quaternion(){}
    
    Quaternion::Quaternion( float param_x, float param_y, float param_z, float param_w ):
        x(param_x),
        y(param_y),
        z(param_z),
        w(param_w)
    {}
    
    
    Quaternion& Quaternion::setX( float x ){
        this->x = x;
        onChangeCallback();
        return *this;
    }
    Quaternion& Quaternion::setY( float y ){
        this->y = y;
        onChangeCallback();
        return *this;
    }
    Quaternion& Quaternion::setZ( float z ){
        this->z = z;
        onChangeCallback();
        return *this;
    }
    Quaternion& Quaternion::setW( float w ){
        this->w = w;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::set( float x, float y, float z, float w ){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
        onChangeCallback();
        return *this;
    }
    
    
    Quaternion& Quaternion::operator=( const Quaternion& other ) {
        if( this == &other )
            return *this;
        
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        this->w = other.w;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::setFrom( Euler& euler, bool update ) {
        float cos_x = cosf( euler.x / 2.0 );
        float cos_y = cosf( euler.y / 2.0 );
        float cos_z = cosf( euler.z / 2.0 );
        float sin_x = sinf( euler.x / 2.0 );
        float sin_y = sinf( euler.y / 2.0 );
        float sin_z = sinf( euler.z / 2.0 );
        
        switch( euler.order ) {
            case RotationOrders::XYZ :
                this->x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::YXZ  :
                this->x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::ZXY  :
                this->x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::ZYX  :
                this->x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::YZX  :
                this->x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::XZY  :
                this->x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
        }
        
        if( update )
            onChangeCallback();
        
        return *this;
    }
    
    Quaternion& Quaternion::setFrom( glm::vec3& axis, float angle ) {
        float half_angle = angle / 2.0;
        float sin_half_angle = sinf( half_angle );
        
        this->x = axis.x * sin_half_angle;
        this->y = axis.y * sin_half_angle;
        this->z = axis.z * sin_half_angle;
        this->w = cosf( half_angle );
        onChangeCallback();
        return *this;
    }
    
    /**
     * From http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
     */
    Quaternion& Quaternion::setFrom( glm::mat4x4& mat ) {
        
        float trace = mat[0][0] + mat[1][1] + mat[2][2];
        float s;
        
		if ( trace > 0 ) {
			s = 0.5 / sqrt( trace + 1.0 );
			this->w = 0.25 / s;
			this->x = ( mat[2][1] - mat[1][2] ) * s;
			this->y = ( mat[0][2] - mat[2][0] ) * s;
			this->z = ( mat[1][0] - mat[0][1] ) * s;
		}
        else if ( mat[0][0] > mat[1][1] && mat[0][0] > mat[2][2] ) {
			s = 2.0 * sqrt( 1.0 + mat[0][0] - mat[1][1] - mat[2][2] );
			this->w = (mat[2][1] - mat[1][2] ) / s;
			this->x = 0.25 * s;
			this->y = (mat[0][1] + mat[1][0] ) / s;
			this->z = (mat[0][2] + mat[2][0] ) / s;
		}
        else if ( mat[1][1] > mat[2][2] ) {
			s = 2.0 * sqrt( 1.0 + mat[1][1] - mat[0][0] - mat[2][2] );
			this->w = (mat[0][2] - mat[2][0] ) / s;
			this->x = (mat[0][1] + mat[1][0] ) / s;
			this->y = 0.25 * s;
			this->z = (mat[1][2] + mat[2][1] ) / s;
		}
        else {
        	s = 2.0 * sqrt( 1.0 + mat[2][2] - mat[0][0] - mat[1][1] );
        	this->w = ( mat[1][0] - mat[0][1] ) / s;
			this->x = ( mat[0][2] + mat[2][0] ) / s;
			this->y = ( mat[1][2] + mat[2][1] ) / s;
			this->z = 0.25 * s;
		}
        
        onChangeCallback();
        
        return *this;
    }
    
    
    Quaternion& Quaternion::setFrom( glm::vec3& v_from, glm::vec3& v_to ) {
        float r = glm::dot( v_from, v_to );
        glm::vec3 vec;
        
        if( r < 0.000001 ) {
            r = 0.0;
            
            if( fabsf( v_from.x ) > fabsf( v_from.z ) )
                vec = glm::vec3( -v_from.y, v_from.x, 0.0 );
            else
                vec = glm::vec3( 0.0, -v_from.z, v_from.y );
        }
        else {
            vec = glm::cross(v_from, v_to);
        }
        
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
        this->w = r;
        
        this->normalize();
        
        return *this;
    }
    
    Quaternion& Quaternion::inverse(){
        this->conjugate().normalize();
        return *this;
    }
    
    Quaternion& Quaternion::conjugate(){
        this->x *= -1.0;
        this->y *= -1.0;
        this->z *= -1.0;
        
        onChangeCallback();
        return *this;
    }
    
    float Quaternion::lengthSquared(){
        return x * x + y * y + z * z + w * w;
    }
    
    float Quaternion::length(){
        return sqrt( x * x + y * y + z * z + w * w );
    }
    
    Quaternion& Quaternion::normalize(){
        float len = length();
        if( len == 0.0 ) {
            this->x = 0.0;
            this->y = 0.0;
            this->z = 0.0;
            this->w = 1.0;
        }
        else {
            len = 1.0 / len;
            this->x = this->x * len;
            this->y = this->y * len;
            this->z = this->z * len;
            this->w = this->w * len;
        }
        
        onChangeCallback();
        return *this;
    }
    
    
    Quaternion Quaternion::multiply(Quaternion& a, Quaternion& b) {
        float x = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y;
        float y = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z;
        float z = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x;
        float w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
        
        return Quaternion( x, y, z, w );
    }
    
    Quaternion& Quaternion::multiply(Quaternion& q) {
        *this = multiply(*this, q);
        onChangeCallback();
        return (*this);
    }
    
    
    Quaternion& Quaternion::slerp( Quaternion& q, float t ) {
        float cos_half_theta = w * q.w + x * q.x + y * q.y + z * q.z;
        
        if( cos_half_theta < 0.0 ) {
            w = -q.w;
            x = -q.x;
            y = -q.y;
            z = -q.z;
            cos_half_theta = -cos_half_theta;
        }
        else {
            *this = q;
        }
        
        if( cos_half_theta >= 1.0 ) {
            *this = q;
            return *this;
        }
        
        float half_theta = acos( cos_half_theta );
        float sin_half_theta = sqrt( 1.0 - cos_half_theta * cos_half_theta );
        
        if( fabsf(sin_half_theta) < 0.001 ) {
            w = 0.5 * ( q.w + w );
            x = 0.5 * ( q.x + x );
            y = 0.5 * ( q.y + y );
            z = 0.5 * ( q.z + z );
            return *this;
        }
        
        float ratio_a = sinf( (1.0 - t) * half_theta ) / sin_half_theta;
        float ratio_b = sinf(        t  * half_theta ) / sin_half_theta;
        
        w = ( q.w * ratio_a + w * ratio_b );
        x = ( q.x * ratio_a + x * ratio_b );
        y = ( q.y * ratio_a + y * ratio_b );
        z = ( q.z * ratio_a + z * ratio_b );
        
        onChangeCallback();
        
        return *this;
    }
    
    
    Quaternion Quaternion::slerp( Quaternion& a, Quaternion& b, float t ) {
        Quaternion temp = a;
        return temp.slerp( b, t );
    }
    
    bool Quaternion::equals( Quaternion& q ) {
        return x == q.x && y == q.y && z == q.z && w == q.w;
    }
    
    Quaternion& Quaternion::fromArray( vector<float>& vec ) {
        x = vec[0];
        y = vec[1];
        z = vec[2];
        w = vec[3];
        return *this;
    }
    
    vector<float> Quaternion::toArray(){
        return vector<float> {
            x, y, z, w
        };
    }
    
    
    Quaternion& Quaternion::onChange( std::function<void()> callback ) {
        onChangeCallback = callback;
        return *this;
    }
    
    Quaternion Quaternion::clone(){
        return Quaternion( x, y, z, w );
    }
}