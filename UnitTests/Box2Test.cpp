//
//  Box2_tests.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Box2Test.h"

using namespace std;

void Box2Test::SetUp() {
    center  = glm::vec2(0.5, 0.5);
    size    = glm::vec2(2.0, 2.0);
}


void Box2Test::TearDown() {
    
}

TEST_F(Box2Test, constructors ) {
    EXPECT_EQ(MAX_FLOAT, box.min.x );
    EXPECT_EQ(MAX_FLOAT, box.min.y );
    EXPECT_EQ(MIN_FLOAT, box.max.x );
    EXPECT_EQ(MIN_FLOAT, box.max.y );
    
    glm::vec2 min(1, 2);
    glm::vec2 max(3, 4);
    box = three::Box2( min, max );
    EXPECT_EQ( 1.0, box.min.x );
    EXPECT_EQ( 2.0, box.min.y );
    EXPECT_EQ( 3.0, box.max.x );
    EXPECT_EQ( 4.0, box.max.y );
}

TEST_F(Box2Test, setters ) {
    glm::vec2 min(1, 2);
    glm::vec2 max(3, 4);
    box.set( min, max );
    
    EXPECT_EQ( min, box.min );
    EXPECT_EQ( max, box.max );
    
    vector<glm::vec2> points = {
        glm::vec2(1, 2),
        glm::vec2(3, 4),
        glm::vec2(-1, -2),
        glm::vec2(-3, 4),
        glm::vec2(5, 6)
    };
    
    box.setFrom( points );
    EXPECT_EQ( glm::vec2(-3, -2), box.min );
    EXPECT_EQ( glm::vec2(5, 6), box.max );
    
    box.setFrom( center, size );
    EXPECT_EQ( glm::vec2(-0.5, -0.5), box.min );
    EXPECT_EQ( glm::vec2(1.5, 1.5), box.max );
    
    EXPECT_EQ( center, box.center() );
    EXPECT_EQ( size, box.size() );
    
    box.makeEmpty();
    EXPECT_EQ(MAX_FLOAT, box.min.x );
    EXPECT_EQ(MAX_FLOAT, box.min.y );
    EXPECT_EQ(MIN_FLOAT, box.max.x );
    EXPECT_EQ(MIN_FLOAT, box.max.y );
}

TEST_F(Box2Test, expansions ) {
    box.setFrom( center, size );
    
    glm::vec2 point(-1.0, -1.0);
    box.expandByPoint( point );
    
    point = glm::vec2(10.0, 0.0);
    box.expandByPoint( point );
    
    EXPECT_EQ( glm::vec2(-1.0, -1.0), box.min );
    EXPECT_EQ( glm::vec2(10.0, 1.5), box.max );
    
    
    glm::vec2 vector(5.0, 6.5);
    box.expandByVector( vector );
    EXPECT_EQ( glm::vec2(-6.0, -7.5), box.min );
    EXPECT_EQ( glm::vec2(15.0,  8.0), box.max );
    
    box.expandByScalar( 0.5 );
    EXPECT_EQ( glm::vec2(-6.5, -8.0), box.min );
    EXPECT_EQ( glm::vec2(15.5,  8.5), box.max );
}

TEST_F( Box2Test, functions_1 ) {
    box.setFrom( center, size );
    box.expandByScalar( 5.0 );
    
    vector<glm::vec2> points_inside = {
        glm::vec2(0.0, 0.0),
        glm::vec2(-5.5, -5.5),
        glm::vec2(6.5, 6.5),
        glm::vec2(2.0, 4.03),
        glm::vec2(-5.5, 6.5),
    };
    
    for( glm::vec2 point: points_inside )
        EXPECT_TRUE( box.contains( point ) );
    
    
    vector<glm::vec2> points_outside = {
        glm::vec2(50.0, -50.0),
        glm::vec2(-5.6, -5.6),
        glm::vec2(6.6, 6.6),
        glm::vec2(-6.0, 0.0),
        glm::vec2(-7.2, 6.5),
    };
    
    for( glm::vec2 point: points_outside )
        EXPECT_FALSE( box.contains( point ) );
    
    glm::vec2 center_param(0.5, 0.5);
    EXPECT_EQ( glm::vec2(0.5, 0.5), box.getParameter(center_param));
    
    center_param = glm::vec2( 9.0 - 5.5, 3.0 - 5.5 );
    EXPECT_EQ( glm::vec2(0.75, 0.25), box.getParameter(center_param));
    
    center_param = glm::vec2( -5.5, -5.5 );
    EXPECT_EQ( glm::vec2(0, 0), box.getParameter(center_param));
    
    center_param = glm::vec2( 6.5, 6.5 );
    EXPECT_EQ( glm::vec2(1, 1), box.getParameter(center_param));

    three::Box2 box_2;
    {
        glm::vec2 min_1( 0.0, 0.0 );
        glm::vec2 max_1( 10.5, 10.5 );
        box_2.set( min_1, max_1 );
        EXPECT_TRUE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( -15.5, -15.5 );
        glm::vec2 max_1( -5.5, -5.5 );
        box_2.set( min_1, max_1 );
        EXPECT_TRUE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( -5.5, -5.5 );
        glm::vec2 max_1( 6.5, 6.5 );
        box_2.set( min_1, max_1 );
        EXPECT_TRUE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( -5.5, -5.5 );
        glm::vec2 max_1( 6.5, 6.5 );
        box_2.set( min_1, max_1 );
        EXPECT_TRUE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( -6.0, -6.0 );
        glm::vec2 max_1( 7.0, 7.0 );
        box_2.set( min_1, max_1 );
        EXPECT_TRUE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( -8.0, -8.0 );
        glm::vec2 max_1( -6.0, -6.0 );
        box_2.set( min_1, max_1 );
        EXPECT_FALSE( box.doesIntersect(box_2));
    }
    {
        glm::vec2 min_1( 6.0, 8.0 );
        glm::vec2 max_1( 8.0, 6.0 );
        box_2.set( min_1, max_1 );
        EXPECT_FALSE( box.doesIntersect(box_2));
    }
    
    
}

TEST_F( Box2Test, functions_2 ) {
    glm::vec2 min_vec(-2.0, -2.0);
    glm::vec2 max_vec( 2.0,  2.0);
    box.set( min_vec, max_vec );
    
    vector<glm::vec2> points = {
        glm::vec2( -3.0, -3.0 ),
        glm::vec2( 3.0, 3.0 ),
        glm::vec2( 1.0, 1.0 ),
        glm::vec2( -3.0, 3.0 ),
        glm::vec2( 3.0, -3.0 ),
        
        glm::vec2( -3.0, 1.0 ),
        glm::vec2( -1.0, 3.0 ),
    };
    
    EXPECT_EQ( glm::vec2( box.min ), box.clamp( points[0] ) );
    EXPECT_EQ( glm::vec2( box.max ), box.clamp( points[1] ) );
    EXPECT_EQ( glm::vec2( 1.0, 1.0 ), box.clamp( points[2] ) );
    EXPECT_EQ( glm::vec2( box.min.x, box.max.y ), box.clamp( points[3] ) );
    EXPECT_EQ( glm::vec2( box.max.x, box.min.y ), box.clamp( points[4] ) );
    EXPECT_EQ( glm::vec2( box.min.x, 1.0 ), box.clamp( points[5] ) );
    EXPECT_EQ( glm::vec2( -1.0, box.max.y ), box.clamp( points[6] ) );
    

    EXPECT_FLOAT_EQ( sqrt(2.0), box.distanceTo(points[0] ));
    EXPECT_FLOAT_EQ( sqrt(2.0), box.distanceTo(points[1] ));
    EXPECT_FLOAT_EQ( 0.0, box.distanceTo(points[2] ));
    EXPECT_FLOAT_EQ( sqrt(2.0), box.distanceTo(points[3] ));
    EXPECT_FLOAT_EQ( sqrt(2.0), box.distanceTo(points[4] ));
    EXPECT_FLOAT_EQ( sqrt(1.0), box.distanceTo(points[5] ));
    EXPECT_FLOAT_EQ( sqrt(1.0), box.distanceTo(points[6] ));
    
    
    three::Box2 box_2;
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( 0.0, 0.0 );
        glm::vec2 max_1( 2.5, 2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.intersects( box_2 );
        EXPECT_EQ( glm::vec2(0.0, 0.0), box_3.min );
        EXPECT_EQ( glm::vec2(2.0, 2.0), box_3.max );
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -2.5, -2.5 );
        glm::vec2 max_1( 0.0, 0.0 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.intersects( box_2 );
        EXPECT_EQ( glm::vec2(-2.0, -2.0), box_3.min );
        EXPECT_EQ( glm::vec2( 0.0,  0.0), box_3.max );
    }
    
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -2.5, -2.5 );
        glm::vec2 max_1( 2.5, 2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.intersects( box_2 );
        EXPECT_EQ( min_vec, box_3.min );
        EXPECT_EQ( max_vec, box_3.max );
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( 2.5, 2.5 );
        glm::vec2 max_1( -2.5, -2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.intersects( box_2 );

        EXPECT_EQ( min_1, box_3.min );
        EXPECT_EQ( max_1, box_3.max );
        EXPECT_TRUE(box_3.empty());
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -1.5, -1.5 );
        glm::vec2 max_1( 1.5, 1.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.intersects( box_2 );
        EXPECT_EQ( box_2.min, box_3.min );
        EXPECT_EQ( box_2.max, box_3.max );
    }
    
    /* Unions */
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( 0.0, 0.0 );
        glm::vec2 max_1( 2.5, 2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.unions( box_2 );
        EXPECT_EQ( min_vec, box_3.min );
        EXPECT_EQ( box_2.max, box_3.max );
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -2.5, -2.5 );
        glm::vec2 max_1( 0.0, 0.0 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.unions( box_2 );
        EXPECT_EQ( box_2.min, box_3.min );
        EXPECT_EQ( max_vec, box_3.max );
    }
    
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -2.5, -2.5 );
        glm::vec2 max_1( 2.5, 2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.unions( box_2 );
        EXPECT_EQ( box_2.min, box_3.min );
        EXPECT_EQ( box_2.max, box_3.max );
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( 2.5, 2.5 );
        glm::vec2 max_1( -2.5, -2.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.unions( box_2 );
        EXPECT_EQ( min_vec, box_3.min );
        EXPECT_EQ( max_vec, box_3.max );
    }
    
    {
        box.set( min_vec, max_vec );
        glm::vec2 min_1( -1.5, -1.5 );
        glm::vec2 max_1( 1.5, 1.5 );
        box_2.set( min_1, max_1 );
        three::Box2 box_3 = box.unions( box_2 );
        EXPECT_EQ( min_vec, box_3.min );
        EXPECT_EQ( max_vec, box_3.max );
    }
    
    
    vector<glm::vec2> offsets = {
        glm::vec2( 0.0, 0.0 ),
        glm::vec2( 1.0, 2.0 ),
        glm::vec2( -2.0, 1.0 ),
        glm::vec2( -3.0, -3.0 ),
        glm::vec2( 3.0, 3.0 ),
    };
    
    box.set( min_vec, max_vec );
    box.translate( offsets[0] );
    EXPECT_EQ( min_vec, box.min );
    EXPECT_EQ( max_vec, box.max );
    
    box.set( min_vec, max_vec );
    box.translate( offsets[1] );
    EXPECT_EQ( glm::vec2(-1.0, 0.0), box.min );
    EXPECT_EQ( glm::vec2(3.0, 4.0), box.max );
    
    box.set( min_vec, max_vec );
    box.translate( offsets[1] );
    EXPECT_EQ( glm::vec2(-1.0, 0.0), box.min );
    EXPECT_EQ( glm::vec2(3.0, 4.0), box.max );
    
    box.set( min_vec, max_vec );
    box.translate( offsets[2] );
    EXPECT_EQ( glm::vec2(-4.0, -1.0), box.min );
    EXPECT_EQ( glm::vec2( 0.0, 3.0), box.max );
    
    box.set( min_vec, max_vec );
    box.translate( offsets[3] );
    EXPECT_EQ( glm::vec2(-5.0, -5.0), box.min );
    EXPECT_EQ( glm::vec2(-1.0, -1.0), box.max );
    
    box.set( min_vec, max_vec );
    box.translate( offsets[4] );
    EXPECT_EQ( glm::vec2( 1.0, 1.0), box.min );
    EXPECT_EQ( glm::vec2( 5.0, 5.0), box.max );
    
    box.set( min_vec, max_vec );
    box_2 = three::Box2( min_vec, max_vec );
    
    EXPECT_TRUE( box.equals(box_2 ));
    EXPECT_TRUE( box.equals(box ));
    box_2.expandByScalar(1.0);
    EXPECT_FALSE( box.equals(box_2 ));
    
    box = box_2.clone();
    EXPECT_TRUE( box.equals(box_2 ));
    
    EXPECT_FALSE( box.empty() );
    box.set( max_vec, min_vec );
    EXPECT_TRUE( box.empty() );
    box = three::Box2();
    EXPECT_TRUE( box.empty() );

    box = box_2;
    EXPECT_TRUE( box.equals( box_2 ) );
    box_2.expandByScalar(5.0);
    EXPECT_FALSE( box.equals( box_2 ) );
    box = box_2;
    EXPECT_TRUE( box.equals( box_2 ) );
}