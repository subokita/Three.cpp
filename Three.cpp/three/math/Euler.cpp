//
//  Euler.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 28/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Euler.h"
#include "Math.h"
#include "Quaternion.h"

using namespace std;

namespace three {
    
    Euler::Euler() :
        x(0.0),
        y(0.0),
        z(0.0),
        order( RotationOrders::XYZ )
    {}
    
    Euler::Euler( float x_val, float y_val, float z_val, RotationOrders rot_order ):
        x(x_val),
        y(y_val),
        z(z_val),
        order( rot_order )
    {}
    
    Euler::~Euler() {}
    
    Euler& Euler::set( float x, float y, float z, RotationOrders order ){
        this->x     = x;
        this->y     = y;
        this->z     = z;
        this->order = order;
        onChangeCallback();
        return *this;
    }
    
    Euler& Euler::operator=( const Euler& other ){
        if( this == &other )
            return *this;
        
        this->x     = other.x;
        this->y     = other.y;
        this->z     = other.z;
        this->order = other.order;
        onChangeCallback();
        return *this;
    }
    
    
    Euler& Euler::setX( float x ) {
        this->x = x;
        onChangeCallback();
        return *this;
    }
    
    Euler& Euler::setY( float y ){
        this->y = y;
        onChangeCallback();
        return *this;
    }
    
    Euler& Euler::setZ( float z ){
        this->z = z;
        onChangeCallback();
        return *this;
    }
    
    Euler& Euler::setRotationOrder( RotationOrders order ){
        this->order = order;
        onChangeCallback();
        return *this;
    }
    
    Euler& Euler::setFrom( glm::mat4x4& mat, RotationOrders order ){
        this->order = order;
        
        switch ( order ) {
                
            case RotationOrders::XYZ:
                this->y = asin( Math::clamp( mat[0][2], -1.0, 1.0) );
                if( fabs(mat[0][2]) < 0.99999 ) {
                    this->x = atan2( -mat[1][2], mat[2][2] );
                    this->z = atan2( -mat[0][1], mat[0][0] );
                }
                else {
                    this->x = atan2( mat[2][1], mat[1][1] );
                    this->z = 0.0;
                }
                break;
                
            case RotationOrders::YXZ:
                this->x = asin( -Math::clamp( mat[1][2], -1.0, 1.0 ) );
                if( fabs( mat[1][2] ) < 0.99999 ) {
                    this->y = atan2( mat[0][2], mat[2][2] );
                    this->z = atan2( mat[1][0], mat[1][1] );
                }
                else {
                    this->y = atan2( -mat[2][0], mat[0][0] );
                    this->z = 0.0;
                }
                break;
                
            case RotationOrders::ZXY:
                this->x = asin( Math::clamp( mat[2][1], -1.0, 1.0) );
                if( fabs( mat[2][1] ) < 0.99999 ) {
                    this->y = atan2( -mat[2][0], mat[2][2] );
                    this->z = atan2( -mat[0][1], mat[1][1] );
                }
                else {
                    this->y = 0.0;
                    this->z = atan2( mat[1][0], mat[0][0] );
                }
                break;
                
            case RotationOrders::ZYX:
                this->z = asin( -Math::clamp( mat[2][0], -1.0, 1.0 ) );
                if( fabs( mat[2][0] ) < 0.99999 ) {
                    this->x = atan2( mat[2][1], mat[2][2] );
                    this->z = atan2( mat[1][0], mat[0][0] );
                }
                else {
                    this->x = 0.0;
                    this->z = atan2( -mat[0][1], mat[1][1] );
                }
                break;
                
            case RotationOrders::YZX:
                this->z = asin( Math::clamp( mat[1][0], -1.0, 1.0) );
                if( fabs(mat[1][0]) < 0.99999 ) {
                    this->x = atan2( -mat[1][2], mat[1][1] );
                    this->y = atan2( -mat[2][0], mat[0][0] );
                }
                else {
                    this->x = 0.0;
                    this->y = atan2( -mat[0][2], mat[2][2] );
                }
                break;
                
            case RotationOrders::XZY:
                this->z = asin( -Math::clamp( mat[0][1], -1.0, 1.0 ) );
                if( fabs( mat[0][1] ) < 0.99999 ) {
                    this->x = atan2( mat[2][1], mat[1][1] );
                    this->y = atan2( mat[0][2], mat[0][0] );
                }
                else {
                    this->x = atan2( -mat[1][2], mat[2][2] );
                    this->y = 0.0;
                }
                break;
        }
        
        onChangeCallback();
        
        return *this;
    }
    
    
    /**
     * From http://www.mathworks.com/matlabcentral/fileexchange/20696-function-to-convert-between-dcm-euler-angles-quaternions-and-euler-vectors/content/SpinCalc.m
     */
    Euler& Euler::setFrom( Quaternion& q, RotationOrders order, bool update ){
        float sqx = q.x * q.x;
        float sqy = q.y * q.y;
        float sqz = q.z * q.z;
        float sqw = q.w * q.w;
        
        this->order = order;
        
        switch( this->order ) {
            case RotationOrders::XYZ:
                this->x = atan2( 2 * ( q.x * q.w - q.y * q.z ), ( sqw - sqx - sqy + sqz ) );
                this->y = asin(  Math::clamp( 2 * ( q.x * q.z + q.y * q.w ), -1.0, 1.0 ) );
                this->z = atan2( 2 * ( q.z * q.w - q.x * q.y ), ( sqw + sqx - sqy - sqz ) );
                break;
                
            case  RotationOrders::YXZ:
                this->x = asin(  Math::clamp( 2 * ( q.x * q.w - q.y * q.z ), -1.0, 1.0 ) );
                this->y = atan2( 2 * ( q.x * q.z + q.y * q.w ), ( sqw - sqx - sqy + sqz ) );
                this->z = atan2( 2 * ( q.x * q.y + q.z * q.w ), ( sqw - sqx + sqy - sqz ) );
                break;
                
            case RotationOrders::ZXY:
                this->x = asin(  Math::clamp( 2 * ( q.x * q.w + q.y * q.z ), -1.0, 1.0 ) );
                this->y = atan2( 2 * ( q.y * q.w - q.z * q.x ), ( sqw - sqx - sqy + sqz ) );
                this->z = atan2( 2 * ( q.z * q.w - q.x * q.y ), ( sqw - sqx + sqy - sqz ) );
                break;
                
            case RotationOrders::ZYX:
                this->x = atan2( 2 * ( q.x * q.w + q.z * q.y ), ( sqw - sqx - sqy + sqz ) );
                this->y = asin(  Math::clamp( 2 * ( q.y * q.w - q.x * q.z ), -1.0, 1.0 ) );
                this->z = atan2( 2 * ( q.x * q.y + q.z * q.w ), ( sqw + sqx - sqy - sqz ) );
                break;
                
            case RotationOrders::YZX:
                this->x = atan2( 2 * ( q.x * q.w - q.z * q.y ), ( sqw - sqx + sqy - sqz ) );
                this->y = atan2( 2 * ( q.y * q.w - q.x * q.z ), ( sqw + sqx - sqy - sqz ) );
                this->z = asin(  Math::clamp( 2 * ( q.x * q.y + q.z * q.w ), -1.0, 1.0 ) );
                break;
                
            case RotationOrders::XZY:
                this->x = atan2( 2 * ( q.x * q.w + q.y * q.z ), ( sqw - sqx + sqy - sqz ) );
                this->y = atan2( 2 * ( q.x * q.z + q.y * q.w ), ( sqw + sqx - sqy - sqz ) );
                this->z = asin(  Math::clamp( 2 * ( q.z * q.w - q.x * q.y ), -1.0, 1.0 ) );
                break;
        }
        
        if( update )
            onChangeCallback();
        return *this;
    }
    
    
    void Euler::reorder( RotationOrders new_order ){
        Quaternion q;
        q.setFrom( *this, false );
        this->setFrom( q, new_order, false );
    }
    
    bool Euler::equals( Euler& other ){
        return (x == other.x) && (y == other.y) && (z == other.z) && (order == other.order);
    }
    
    Euler& Euler::fromArray( std::vector<float>& array ){
        this->x = array[0];
        this->y = array[1];
        this->z = array[2];

        if( array.size() > 3 ) {
            this->order = RotationOrders::XYZ;
            
            if( array[3] == 0 )
                this->order = RotationOrders::XYZ;
            else if( array[3] == 1 )
                this->order = RotationOrders::YZX;
            else if( array[3] == 2 )
                this->order = RotationOrders::ZXY;
            else if( array[3] == 3 )
                this->order = RotationOrders::XZY;
            else if( array[3] == 4 )
                this->order = RotationOrders::YXZ;
            else if( array[3] == 5 )
                this->order = RotationOrders::ZYX;
        }
        
        onChangeCallback();
        
        return *this;
    }
    
    std::vector<float> Euler::toArray(){
        vector<float> array(4);
        array[0] = this->x;
        array[1] = this->y;
        array[2] = this->z;
        
        switch( this->order ){
            case RotationOrders::XYZ: array[3] = 0; break;
            case RotationOrders::YZX: array[3] = 1; break;
            case RotationOrders::ZXY: array[3] = 2; break;
            case RotationOrders::XZY: array[3] = 3; break;
            case RotationOrders::YXZ: array[3] = 4; break;
            case RotationOrders::ZYX: array[3] = 5; break;
        }
        
        return array;
    }
 
    
    Euler& Euler::onChange( std::function<void()> callback ) {
        onChangeCallback = callback;
        return *this;
    }
    
    Euler Euler::clone(){
        return Euler( this->x, this->y, this->z, this->order );
    }

}