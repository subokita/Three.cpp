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

using namespace std;

int main(int argc, char **argv) {
    glm::mat4x4 mat = {
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16
    };
    
    cout << mat[0][0] << endl;
    cout << mat[0][1] << endl;
    cout << mat[0][2] << endl;
    cout << mat[1][0] << endl;
    cout << mat[1][1] << endl;
    cout << mat[1][2] << endl;
    cout << mat[2][0] << endl;
    cout << mat[2][1] << endl;
    cout << mat[2][2] << endl;
    
    glm::quat q;
    glm::eulerAngles(q );
    
    return 0;
}
