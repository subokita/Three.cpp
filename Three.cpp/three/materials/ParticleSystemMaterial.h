//
//  ParticleSystemMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__ParticleSystemMaterial__
#define __Three_cpp__ParticleSystemMaterial__

#include <iostream>
#include "Material.h"
#include "Texture.h"

namespace three {
    class ParticleSystemMaterial : public Material {
        public:
            /** Constructors **/
            ParticleSystemMaterial();
            ParticleSystemMaterial( const ParticleSystemMaterial& rhs );
            ParticleSystemMaterial clone();
            ~ParticleSystemMaterial();
        
            /* Data members */
            Color   color;
            Texture map;
            float   size;
            bool    sizeAttenuation;
            bool    vertexColors;
            bool    fog;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const ParticleSystemMaterial& obj ) {
                os << "ParticleSystemMaterial {" << std::endl;
                os << "\tcolor          : " << obj.color           << std::endl;
//                os << "\tmap            : " << obj.map             << std::endl;
                os << "\tsize           : " << obj.size            << std::endl;
                os << "\tsizeAttenuation: " << obj.sizeAttenuation << std::endl;
                os << "\tvertexColors   : " << obj.vertexColors    << std::endl;
                os << "\tfog            : " << obj.fog             << std::endl;
                os << "}";
                return os;
            }
    };
}


#endif /* defined(__Three_cpp__ParticleSystemMaterial__) */
