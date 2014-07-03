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
#include "Fog.h"
#include "EventDispatcher.h"
#include "Event.h"

#include <memory>

using namespace std;
using namespace three;

int main(int argc, char **argv) {
    glm::mat4x4 mat(
        1, 5, 9, 13,
        2, 6, 10, 14,
        3, 7, 11, 15,
        4, 8, 12, 16
    );
    
    Object3D a;
    Scene b;
    Object3D c;
    
    b.setEventHandler( [&]( EventDispatcher& obj, Event& event ) {
        cout << Utils::toString(mat) << endl;
        
        shared_ptr<Scene> scene_ptr = dynamic_pointer_cast<Scene>( event.scene );
        cout << scene_ptr->autoUpdate << endl;
    });
    
    c.setEventHandler([&]( EventDispatcher& obj, Event& event ) {
        cout << "Does nothing" << endl;
    });
    
    shared_ptr<EventDispatcher> ptr_to_b = make_shared<EventDispatcher>(b);
    

    a.addEventListener( "test", ptr_to_b );
    a.addEventListener( "test", make_shared<EventDispatcher>(c) );
    a.addEventListener( "test", ptr_to_b );

    Scene scene;
    scene.autoUpdate = false;
    
    shared_ptr<Scene> ptr_to_scene = make_shared<Scene>( scene );
    
    a.dispatchEvent( Event{"test", nullptr, ptr_to_scene} );
    
    return 0;
}
