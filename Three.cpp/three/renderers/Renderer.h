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
#include "three.h"
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
        public:
            RendererParams params;
        
            /* Clearing scene */
            Color clearColor      = Color(0, 0, 0);
            float clearAlpha      = 0.0;
            bool autoClear        = true;
            bool autoClearColor   = true;
            bool autoClearDepth   = true;
            bool autoClearStencil = true;
            
            /* Scene graph */
            bool sortObjects       = true;
            bool autoUpdateObjects = true;
            
            /* Physically based shading */
            bool gammaInput          = false;
            bool gammaOutput         = false;
            bool shadowMapEnabled    = true;
            bool shadowMapAutoUpdate = false;
            int shadowMapType        = three::PCFShadowMap;
            int shadowMapCullFace    = three::CullFaceFront;
            bool shadowMapDebug      = false;
            bool shadowMapCascade    = false;

            /* Morphs */
            int maxMorphTargets = 8;
            int maxMorphNormals = 4;
            
            /* Flags */
            int autoScaleCubemaps = true;
    };
}


#endif /* defined(__Three_cpp__Renderer__) */
