//
//  Bone.h
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Bone__
#define __Three_cpp__Bone__

#include <iostream>
#include "Object3D.h"

namespace three {
    class Bone : public Object3D {
    public:
        /** Constructors **/
        Bone();
        Bone( bool belongs_to_skin );
        Bone( const Bone& rhs );
        Bone clone();
        ~Bone();
        
        void update( bool force_update );
        void update( bool force_update, glm::mat4x4& parent_skin_matrix );
        
        /* Data members */
        bool        skin;
        glm::mat4x4 skinMatrix;
        float       accumulatedRotationWeight;
        float       accumulatedPositionWeight;
        float       accumulatedScaleWeight;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const Bone& obj ) {
            os << "Bone {" << std::endl;
            os << "\tskin                     : " << obj.skin                      << std::endl;
            os << "\tskinMatrix               : " << Utils::toString( obj.skinMatrix ) << std::endl;
            os << "\taccumulatedRotationWeight: " << obj.accumulatedRotationWeight << std::endl;
            os << "\taccumulatedPositionWeight: " << obj.accumulatedPositionWeight << std::endl;
            os << "\taccumulatedScaleWeight   : " << obj.accumulatedScaleWeight    << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__Bone__) */
