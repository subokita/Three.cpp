//
//  BaseFog.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__BaseFog__
#define __Three_cpp__BaseFog__

#include <iostream>
#include "Color.h"

namespace three {
    class BaseFog {
    public:
        /** Constructors **/
        BaseFog();
        BaseFog( Color& color );
        BaseFog( const BaseFog& rhs );
        BaseFog clone() const;
        ~BaseFog();
        
        /* Data members */
        Color color;

        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const BaseFog& obj ) {
            os << "BaseFog {" << std::endl;
            os << "\tcolor: " << obj.color << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__BaseFog__) */
