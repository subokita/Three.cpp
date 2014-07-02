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
#include <map>

namespace three {
    class Event;
    
    class EventDispatcher {
    public:
        void addEventListener();
        bool hasEventListener();
        void removeEventListener();
        void dispatchEvent( Event event );
        
    protected:
        std::map<std::string, std::shared_ptr<EventDispatcher>> listeners;
    };
}

#endif /* defined(__Three_cpp__EventDispatcher__) */
