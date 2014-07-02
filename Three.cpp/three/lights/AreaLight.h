//
//  AreaLight.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__AreaLight__
#define __Three_cpp__AreaLight__

#include <iostream>
#include "Light.h"

namespace three {
    class AreaLight : public Light {
        public:
            /** Constructors **/
            AreaLight();
            AreaLight( Color& color, float intensity );
            AreaLight( const AreaLight& rhs );
            AreaLight clone();
            ~AreaLight();
        
            /* Data members */
            glm::vec3 normal;
            glm::vec3 right;
            float     intensity;
            float     width;
            float     height;
            float     constantAttenuation;
            float     linearAttenuation;
            float     quadraticAttenuation;
            
            
            /** Output stream overloading */
            friend std::ostream &operator <<( std::ostream& os, const AreaLight& obj ) {
                os << "AreaLight {" << std::endl;
                os << "\tnormal              : " << Utils::toString( obj.normal ) << std::endl;
                os << "\tright               : " << Utils::toString( obj.right ) << std::endl;
                os << "\tintensity           : " << obj.intensity            << std::endl;
                os << "\twidth               : " << obj.width                << std::endl;
                os << "\theight              : " << obj.height               << std::endl;
                os << "\tconstantAttenuation : " << obj.constantAttenuation  << std::endl;
                os << "\tlinearAttenuation   : " << obj.linearAttenuation    << std::endl;
                os << "\tquadraticAttenuation: " << obj.quadraticAttenuation << std::endl;
                os << "}";
                return os;
            }

    };
}

#endif /* defined(__Three_cpp__AreaLight__) */
