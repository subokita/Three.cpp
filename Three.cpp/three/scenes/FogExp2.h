//
//  FogExp2.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__FogExp2__
#define __Three_cpp__FogExp2__

#include <iostream>
#include "BaseFog.h"

namespace three {
    class FogExp2 : public BaseFog {
    public:
        /** Constructors **/
        FogExp2();
        FogExp2( Color& color, float distance );
        FogExp2( const FogExp2& rhs );
        FogExp2 clone();
        ~FogExp2();
    
        /* Data members */
        float distance;
    
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const FogExp2& obj ) {
            os << "FogExp2 {" << std::endl;
            os << "\tdistance: " << obj.distance << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__FogExp2__) */
