//
//  Scene.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Scene__
#define __Three_cpp__Scene__

#include <iostream>
#include "Object3D.h"
#include "BaseFog.h"
#include "Material.h"
#include "Light.h"

namespace three {
    class Scene : public Object3D {
    public:
        /** Constructors **/
        Scene();
        Scene( const Scene& rhs );
        Scene clone();
        ~Scene();
    
        void addObject( std::shared_ptr<Object3D> object );
        void removeObject( std::shared_ptr<Object3D> object );
    
        /* Data members */
        std::shared_ptr<BaseFog>                 fog;
        std::shared_ptr<Material>                overrideMaterial;
        bool                                     autoUpdate;
        std::map<int, std::shared_ptr<Light>>    lights;
        std::map<int, std::shared_ptr<Object3D>> objectsAdded;
        std::map<int, std::shared_ptr<Object3D>> objectsRemoved;
    };
}

#endif /* defined(__Three_cpp__Scene__) */
