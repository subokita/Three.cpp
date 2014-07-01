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


three::Object3D obj;

void test() {
    
    three::Object3D obj2, obj3;
    
    obj.add( obj2 );
    obj.add( obj3 );
}

int main(int argc, char **argv) {
    glm::mat4x4 mat(
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16
    );
    
    glm::vec3 position ( 10.0, 20.0, 30.0 );
    three::Quaternion quat( 3.0, 4.0, 5.0, 2.0 );
    glm::vec3 scale( 2.0, 3.0, 4.0 );
    
    mat = three::Math::composeMatrix( position, quat, scale );
    
    cout << three::Utils::toString( mat ) << endl;
    
//    var position = new THREE.Vector3(10.0, 20.0, 30.0);
//    var quaternion = new THREE.Quaternion( 3.0, 4.0, 5.0, 2.0 );
//    var scale = new THREE.Vector3( 2.0, 3.0, 4.0 );
//    mat.compose( position, quaternion, scale );
    
    return 0;
}
