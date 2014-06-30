//
//  Object3D.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Object3D.h"


namespace three {
    Object3D::Object3D() {
        rotation.onChange([&]() {
            quaternion.setFrom( rotation, false );
        });
        
        quaternion.onChange([&]() {
            rotation.setFrom( quaternion, rotation.order, false );
        });
    }
}