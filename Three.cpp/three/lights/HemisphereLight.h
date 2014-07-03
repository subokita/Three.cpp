//
//  HemisphereLight.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__HemisphereLight__
#define __Three_cpp__HemisphereLight__

#include <iostream>
#include "Light.h"

namespace three {
    class HemisphereLight : public Light {
    public:
        /** Constructors **/
        HemisphereLight();
        HemisphereLight( Color& sky_color, Color& ground_color, float intensity );
        HemisphereLight( const HemisphereLight& rhs );
        HemisphereLight clone();
        ~HemisphereLight();
    
        /* Data members */
        Color groundColor;
        float intensity;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const HemisphereLight& obj ) {
            os << "HemisphereLight {" << std::endl;
            os << "\tgroundColor: " << obj.groundColor << std::endl;
            os << "\tintensity  : " << obj.intensity   << std::endl;
            os << "}";
            return os;
        }
            
    };
}

#endif /* defined(__Three_cpp__HemisphereLight__) */
