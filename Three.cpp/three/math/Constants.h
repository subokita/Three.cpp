//
//  Constants.h
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Constants__
#define __Three_cpp__Constants__

#include <iostream>
#include <glm/glm.hpp>
#include <numeric>

static const float MAX_FLOAT = std::numeric_limits<float>::max();
static const float MIN_FLOAT = std::numeric_limits<float>::min();
static const glm::vec3 NULL_VEC3 = glm::vec3( MIN_FLOAT, MIN_FLOAT, MIN_FLOAT );

#endif /* defined(__Three_cpp__Constants__) */
