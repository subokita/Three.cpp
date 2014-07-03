//
//  LineBasicMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 01/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__LineBasicMaterial__
#define __Three_cpp__LineBasicMaterial__

#include <iostream>
#include "Material.h"

namespace three {
    class LineBasicMaterial : public Material {
    public:
        LineBasicMaterial();
        LineBasicMaterial( const LineBasicMaterial& rhs );
        LineBasicMaterial clone() const;
        ~LineBasicMaterial();
    
        /* Data members */
        int         linewidth;
        std::string linecap;
        std::string linejoin;
        bool        vertexColors;
        bool        fog;
        Color       color;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const LineBasicMaterial& obj ) {
            os << "LineBasicMaterial {" << std::endl;
            os << "\tlinewidth   : " << obj.linewidth    << std::endl;
            os << "\tlinecap     : " << obj.linecap      << std::endl;
            os << "\tlinejoin    : " << obj.linejoin     << std::endl;
            os << "\tvertexColors: " << obj.vertexColors << std::endl;
            os << "\tfog         : " << obj.fog          << std::endl;
            os << "\tcolor       : " << obj.color        << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__LineBasicMaterial__) */
