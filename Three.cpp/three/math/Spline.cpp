//
//  Spline.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Spline.h"

using namespace std;

namespace three {
    
    void Spline::initFromArray( vector<vector<float>>& a ) {
        points.clear();
        
        for(int i = 0; i < a.size(); i++ )
            points[i] = glm::vec3( a[i][0], a[i][1], a[i][2] );
    }
    
    glm::vec3 Spline::getPoint(float k){
        point = (points.size() - 1) * k;
        intPoint = floor( point );
        weight = point - intPoint;
        
        c[0] = intPoint == 0.0 ? intPoint : intPoint - 1;
        c[1] = intPoint;
        c[2] = intPoint > points.size() - 2 ? static_cast<int>(points.size()) - 1 : intPoint + 1;
        c[3] = intPoint > points.size() - 3 ? static_cast<int>(points.size()) - 1 : intPoint + 2;
        
        pointA = points[c[0]];
        pointB = points[c[1]];
        pointC = points[c[2]];
        pointD = points[c[3]];
        
        weightSquared = weight * weight;
        weightCubed = weightSquared * weight;
        
        glm::vec3 vec;
        vec.x = interpolate( pointA.x, pointB.x, pointC.x, pointD.x, weight, weightSquared, weightCubed );
        vec.y = interpolate( pointA.y, pointB.y, pointC.y, pointD.y, weight, weightSquared, weightCubed );
        vec.z = interpolate( pointA.z, pointB.z, pointC.z, pointD.z, weight, weightSquared, weightCubed );
        return vec;
    }
    
    
    vector<glm::vec3> Spline::getControlPoints() {
        vector<glm::vec3> coords;
        std::copy( points.begin(), points.end(), back_inserter(coords));
        return coords;
    }
    
    float Spline::interpolate( float p0, float p1, float p2, float p3, float t, float t2, float t3 ) {
        float v0 = (p2 - p0) * 0.5;
        float v1 = (p3 - p1) * 0.5;
		return ( 2 * ( p1 - p2 ) + v0 + v1 ) * t3 + ( - 3 * ( p1 - p2 ) - 2 * v0 - v1 ) * t2 + v0 * t + p1;
    }
}