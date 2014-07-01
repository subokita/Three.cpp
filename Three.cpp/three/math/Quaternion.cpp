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
        rep(0, 0, 0, 1)
    {
    }
    
    Quaternion::~Quaternion(){}
    
    Quaternion::Quaternion( float x, float y, float z, float w ):
        rep(x, y, z, w)
    {}
    
    
    Quaternion& Quaternion::setX( float x ){
        this->rep.x = x;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::setY( float y ){
        this->rep.y = y;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::setZ( float z ){
        this->rep.z = z;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::setW( float w ){
        this->rep.w = w;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::set( float x, float y, float z, float w ){
        this->rep.x = x;
        this->rep.y = y;
        this->rep.z = z;
        this->rep.w = w;
        onChangeCallback();
        return *this;
    }
    
    Quaternion& Quaternion::operator=( const glm::quat& other ) {
        this->rep = other;
        return *this;
    }
    
    
    Quaternion& Quaternion::operator=( const Quaternion& other ) {
        if( this == &other )
            return *this;
        
        this->rep = other.rep;
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
                this->rep.x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::YXZ  :
                this->rep.x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::ZXY  :
                this->rep.x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::ZYX  :
                this->rep.x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::YZX  :
                this->rep.x = sin_x * cos_y * cos_z + cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z + sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z - sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z - sin_x * sin_y * sin_z;
                break;
                
            case RotationOrders::XZY  :
                this->rep.x = sin_x * cos_y * cos_z - cos_x * sin_y * sin_z;
                this->rep.y = cos_x * sin_y * cos_z - sin_x * cos_y * sin_z;
                this->rep.z = cos_x * cos_y * sin_z + sin_x * sin_y * cos_z;
                this->rep.w = cos_x * cos_y * cos_z + sin_x * sin_y * sin_z;
                break;
        }
        
        if( update )
            onChangeCallback();
        
        return *this;
    }
    
    Quaternion& Quaternion::setFrom( glm::vec3& axis, float angle ) {
        float half_angle = angle / 2.0;
        float sin_half_angle = sinf( half_angle );
        
        this->rep.x = axis.x * sin_half_angle;
        this->rep.y = axis.y * sin_half_angle;
        this->rep.z = axis.z * sin_half_angle;
        this->rep.w = cosf( half_angle );
        onChangeCallback();
        return *this;
    }
    
    /**
     * From http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
     */
    Quaternion& Quaternion::setFrom( glm::mat4x4& mat ) {
        
        /* Conjugated because the original one has opposite sign for x, y, and z */
        this->rep = glm::conjugate(glm::quat_cast( mat ));
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
        
        this->rep.x = vec.x;
        this->rep.y = vec.y;
        this->rep.z = vec.z;
        this->rep.w = r;
        
        this->normalize();
        
        return *this;
    }
    
    Quaternion& Quaternion::inverse(){
        this->conjugate().normalize();
        return *this;
    }
    
    Quaternion& Quaternion::conjugate(){
        this->rep = glm::conjugate( rep );
        onChangeCallback();
        return *this;
    }
    
    float Quaternion::lengthSquared(){
        return rep.x * rep.x + rep.y * rep.y + rep.z * rep.z + rep.w * rep.w;
    }
    
    float Quaternion::length(){
        return glm::length( rep );
    }
    
    Quaternion& Quaternion::normalize(){
        rep = glm::normalize( rep );
        onChangeCallback();
        return *this;
    }
    
    
    Quaternion Quaternion::multiply(Quaternion& a, Quaternion& b) {
        glm::quat res = a.rep * b.rep;
        return Quaternion( res.x, res.y, res.z, res.w );
    }
    
    Quaternion& Quaternion::multiply(Quaternion& q) {
        this->rep = this->rep  * q.rep;
        onChangeCallback();
        return (*this);
    }
    
    
    Quaternion& Quaternion::slerp( Quaternion& q, float t ) {
        this->rep = glm::slerp( this->rep, q.rep, t );
        onChangeCallback();
        return *this;
    }
    
    
    Quaternion Quaternion::slerp( Quaternion& a, Quaternion& b, float t ) {
        Quaternion result;
        result = glm::slerp( a.rep, b.rep, t );
        return result;
    }
    
    bool Quaternion::equals( Quaternion& q ) {
        return rep.x == q.rep.x && rep.y == q.rep.y && rep.z == q.rep.z && rep.w == q.rep.w;
    }
    
    Quaternion& Quaternion::fromArray( vector<float>& vec ) {
        rep.x = vec[0];
        rep.y = vec[1];
        rep.z = vec[2];
        rep.w = vec[3];
        return *this;
    }
    
    vector<float> Quaternion::toArray(){
        return vector<float> {
            rep.x, rep.y, rep.z, rep.w
        };
    }
    
    
    Quaternion& Quaternion::onChange( std::function<void()> callback ) {
        onChangeCallback = callback;
        return *this;
    }
    
    Quaternion Quaternion::clone(){
        return Quaternion( rep.x, rep.y, rep.z, rep.w );
    }
}