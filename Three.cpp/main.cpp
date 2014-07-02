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
#include <json-c/json.h>

#include "three/three.h"
#include "LineBasicMaterial.h"


using namespace std;
using namespace three;


int main(int argc, char **argv) {
    glm::mat4x4 mat(
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16
    );
    
    shared_ptr<LineBasicMaterial> m = make_shared<LineBasicMaterial>();
    cout << *m << endl;
    
    
    return 0;
}
