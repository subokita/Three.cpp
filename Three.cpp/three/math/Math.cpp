//
//  Math.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 27/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Math.h"
#include <algorithm>
#include <glm/gtc/matrix_access.hpp>

namespace three {
    float Math::getMaxScaleOnAxis(glm::mat4x4 &mat) {
        float scale_x = mat[0][0] * mat[0][0] + mat[1][0] * mat[1][0] + mat[2][0] * mat[2][0];
        float scale_y = mat[0][1] * mat[0][1] + mat[1][1] * mat[1][1] + mat[2][1] * mat[2][1];
        float scale_z = mat[0][2] * mat[0][2] + mat[1][2] * mat[1][2] + mat[2][2] * mat[2][2];
        
        return sqrtf(std::max( scale_x, std::max( scale_y, scale_z ) ));
    }
}