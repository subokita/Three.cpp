//
//  Box3Test.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 28/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Box3Test.h"

using namespace std;

void Box3Test::SetUp() {
    center  = glm::vec3(0.5, 0.5, 0.5);
    size    = glm::vec3(2.0, 2.0, 2.0);
}


void Box3Test::TearDown() {
    
}

TEST_F(Box3Test, constructors ) {
    
}