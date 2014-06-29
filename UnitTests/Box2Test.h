//
//  Box2Test.h
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Box2Test__
#define __Three_cpp__Box2Test__

#include <iostream>
#include "Box2.h"
#include "Constants.h"
#include <gtest/gtest.h>

class Box2Test : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    
    glm::vec2 center;
    glm::vec2 size;
    three::Box2 box;
};

#endif /* defined(__Three_cpp__Box2Test__) */
