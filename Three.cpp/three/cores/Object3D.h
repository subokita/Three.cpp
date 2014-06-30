//
//  Object3D.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Object3D__
#define __Three_cpp__Object3D__

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "Euler.h"
#include "Quaternion.h"

using namespace std;

namespace three {
    static int Object3DIDCount = 0;
    
    class Object3D {
        public:
            Object3D();
        
        
            int id;
            string uuid;
            string name;
            
            shared_ptr<Object3D> parent;
            vector<Object3D> children;
            glm::vec3 position;
            Euler rotation;
            Quaternion quaternion;
            glm::vec3 scale;
        
            //FIXME: renderDepth
            bool rotationAutoUpdate;
            glm::mat4x4 matrix;
            glm::mat4x4 matrixWorld;
            bool matrixAutoUpdate;
            bool matrixWorldNeedsUpdate;
            
            bool visible;
            bool castShadow;
            bool receiveShadow;
            bool frustumCulled;
            
    };
}

#endif /* defined(__Three_cpp__Object3D__) */
