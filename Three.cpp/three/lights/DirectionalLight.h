//
//  DirectionalLight.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__DirectionalLight__
#define __Three_cpp__DirectionalLight__

#include <iostream>
#include <vector>

#include "Light.h"

namespace three {
    class DirectionalLight : public Light {
        public:
        
        
            Object3D target;
            float intensity;
            bool castShadow;
            bool onlyShadow;
            
            float shadowCameraNear;
            float shadowCameraFar;
            float shadowCameraLeft;
            float shadowCameraRight;
            float shadowCameraTop;
            float shadowCameraBottom;
            
            bool shadowCameraVisible;
            
            float shadowBias;
            float shadowDarkness;
            int shadowMapWidth;
            int shadowMapHeight;
            
            bool shadowCascade;
            glm::vec3 shadowCascadeOffset;
            int shadowCascadeCount;
            
            std::vector<float> shadowCascadeBias;
            std::vector<int> shadowCascadeWidth;
            std::vector<int> shadowCascadeHeight;
            
            std::vector<float> shadowCascadeNearZ;
            std::vector<float> shadowCascadeFarZ;
            
            //FIXME: figure out what's the datatype of these
    //        this.shadowMap = null;
    //        this.shadowMapSize = null;
    //        this.shadowCamera = null;
    //        this.shadowMatrix = null;
    };
}

#endif /* defined(__Three_cpp__DirectionalLight__) */
