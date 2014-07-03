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
#include <vector>

using namespace std;

namespace three {
    class Event;
    
    class EventDispatcher {
    public:
        void addEventListener( string type, shared_ptr<EventDispatcher> obj );
        bool hasEventListener( string type, shared_ptr<EventDispatcher> obj );
        void removeEventListener( string type, shared_ptr<EventDispatcher> obj );
        void dispatchEvent( Event event );
        void setEventHandler( std::function<void(EventDispatcher&, Event&)> handler );
        
    protected:
        std::function<void(EventDispatcher&, Event&)> eventHandler = [](EventDispatcher&, Event&){};
        map<string, vector<shared_ptr<EventDispatcher> >> listeners;
    };
}

#endif /* defined(__Three_cpp__EventDispatcher__) */
