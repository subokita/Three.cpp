//
//  Renderer.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Renderer__
#define __Three_cpp__Renderer__

#include <iostream>
#include <opengl/gl3.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace three {
    struct RendererParams {
        string precision            = "highp";
        bool alpha                  = false;
        bool depth                  = true;
        bool stencil                = true;
        bool antiAlias              = false;
        bool preMultipliedAlpha     = true;
        bool preserveDrawingBuffer  = false;
        bool logarithmicDepthBufer  = false;
        float devicePixelRatio      = 1.0f;
    };
    
    class Renderer {
        private:
            RendererParams params;
    };
}


#endif /* defined(__Three_cpp__Renderer__) */
