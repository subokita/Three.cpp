//
//  LineDashedMaterial.h
//  Three.cpp
//
//  Created by Saburo Okita on 02/07/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__LineDashedMaterial__
#define __Three_cpp__LineDashedMaterial__

#include <iostream>
#include "Material.h"


namespace three {
    class LineDashedMaterial : public Material {
    public:
        LineDashedMaterial();
        LineDashedMaterial( const LineDashedMaterial& rhs );
        LineDashedMaterial clone() const;
        ~LineDashedMaterial();
    
        /* Data members */
        int   linewidth;
        float scale;
        int   dashSize;
        int   gapSize;
        bool  vertexColors;
        bool  fog;
        Color color;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const LineDashedMaterial& obj ) {
            os << "LineDashedMaterial {" << std::endl;
            os << "\tlinewidth   : " << obj.linewidth    << std::endl;
            os << "\tscale       : " << obj.scale        << std::endl;
            os << "\tdashSize    : " << obj.dashSize     << std::endl;
            os << "\tgapSize     : " << obj.gapSize      << std::endl;
            os << "\tvertexColors: " << obj.vertexColors << std::endl;
            os << "\tfog         : " << obj.fog          << std::endl;
            os << "\tcolor       : " << obj.color        << std::endl;
            os << "}";
            return os;
        }
    };
}

#endif /* defined(__Three_cpp__LineDashedMaterial__) */
