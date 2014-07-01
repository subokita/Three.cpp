//
//  Material.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Material__
#define __Three_cpp__Material__

#include <iostream>
#include <string>
#include "Constants.h"
#include "Math.h"
#include "EventDispatcher.h"

using namespace std;


namespace three {
    static int MaterialIDCount = 0;
    
    class Material : public EventDispatcher {
    protected:
        int id;
        string uuid;
        string name;
        
    public:
        Material();
        Material(const Material& other);
        ~Material();
        
        Material clone();
        
        int side;
        float opacity;
        bool transparent;
        int blending;
        int blendSrc;
        int blendDst;
        int blendEquation;
        
        bool depthTest;
        bool depthWrite;
        
        bool polygonOffset;
        float polygonOffsetFactor;
        float polygonOffsetUnits;
        
        float alphaTest;
        float overdraw;
        bool visible;
        bool needsUpdate;
    };
}

#endif /* defined(__Three_cpp__Material__) */
