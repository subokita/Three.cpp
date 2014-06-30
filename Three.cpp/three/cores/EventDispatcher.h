//
//  EventDispatcher.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__EventDispatcher__
#define __Three_cpp__EventDispatcher__

#include <iostream>

namespace three {
    class EventDispatcher {
    public:
        void addEventListener();
        bool hasEventListener();
        void removeEventListener();
        void dispatchEvent();
    };
}

#endif /* defined(__Three_cpp__EventDispatcher__) */
