//
//  Texture.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Texture__
#define __Three_cpp__Texture__

#include <iostream>
#include <glm/glm.hpp>

#include "EventDispatcher.h"

namespace three {
    static int TextureIDCount = 0;
    
    //FIXME: to be filled in later
    class Texture : public EventDispatcher  {
        protected:
        public:
        
            int id;
            std::string uuid;
            std::string name;
            
            int mapping;
            int wrapS;
            int wrapT;
    };
}

#endif /* defined(__Three_cpp__Texture__) */
