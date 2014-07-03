//
//  Bone.cpp
//  Three.cpp
//
//  Created by Saburo Okita on 03/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#include "Bone.h"


namespace three {
    Bone::Bone() :
        accumulatedRotationWeight( 0.0 ),
        accumulatedPositionWeight( 0.0 ),
        accumulatedScaleWeight   ( 0.0 )
    {}
    
    Bone::Bone( bool belongs_to_skin ):
        skin                     ( belongs_to_skin ),
        accumulatedRotationWeight( 0.0 ),
        accumulatedPositionWeight( 0.0 ),
        accumulatedScaleWeight   ( 0.0 )
    {}
    
    Bone::Bone( const Bone& rhs ):
        Object3D                 ( rhs ),
        skin                     ( rhs.skin ),
        skinMatrix               ( rhs.skinMatrix ),
        accumulatedRotationWeight( rhs.accumulatedRotationWeight ),
        accumulatedPositionWeight( rhs.accumulatedPositionWeight ),
        accumulatedScaleWeight   ( rhs.accumulatedScaleWeight )
    {}
    
    Bone Bone::clone(){
        return Bone(*this);
    }
    
    Bone::~Bone(){}
    
    
    void Bone::update( bool force_update ) {
        
        //FIXME: updateMatrix() doesn't return anything in the original javascript code
        if( this->matrixAutoUpdate ) {
            this->updateMatrix();
        }

        if( force_update || this->matrixWorldNeedsUpdate ) {
            skinMatrix = this->matrix;
            
            matrixWorldNeedsUpdate    = false;
            force_update              = true;
            
            accumulatedRotationWeight = 0.0;
            accumulatedPositionWeight = 0.0;
            accumulatedScaleWeight    = 0.0;
        }


        for( auto entry: children ) {
            std::shared_ptr<Bone> bone = dynamic_pointer_cast<Bone>(entry.second);
            if( bone != nullptr )
                bone->update( force_update );
        }
    }

    void Bone::update( bool force_update, glm::mat4x4& parent_skin_matrix ){
        
        //FIXME: updateMatrix() doesn't return anything in the original javascript code
        if( this->matrixAutoUpdate ) {
            this->updateMatrix();
        }
        
        if( force_update || this->matrixWorldNeedsUpdate ) {
            skinMatrix *= parent_skin_matrix;
            
            matrixWorldNeedsUpdate    = false;
            force_update              = true;
            
            accumulatedRotationWeight = 0.0;
            accumulatedPositionWeight = 0.0;
            accumulatedScaleWeight    = 0.0;
        }


        for( auto entry: children ) {
            std::shared_ptr<Bone> bone = dynamic_pointer_cast<Bone>(entry.second);
            if( bone != nullptr )
                bone->update( force_update, parent_skin_matrix );
        }
    }
}