//
//  Box3Test.h
//  Three.cpp
//
//  Created by Saburo Okita on 28/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Box3Test__
#define __Three_cpp__Box3Test__

#include <iostream>
#include "Box3.h"
#include "Constants.h"
#include <gtest/gtest.h>

class Box3Test : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    
    glm::vec3 center;
    glm::vec3 size;
    three::Box3 box;
};


#endif /* defined(__Three_cpp__Box3Test__) */
