//
//  main.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 26/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <GLFW/glfw3.h>
#include "three/three.h"


using namespace std;

int main(int argc, char **argv) {
    glm::mat4x4 mat(
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16
    );
    
    glm::vec3 position, scale;
    three::Quaternion quaternion(0.0, 0.0, 0.0, 0.0);
    three::Math::decomposeMatrix( mat, position, quaternion, scale );
    
    cout << three::Utils::toString( position ) << endl;
    cout << quaternion << endl;
    cout << three::Utils::toString( scale ) << endl;
    
    return 0;
}
