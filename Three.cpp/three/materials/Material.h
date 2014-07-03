//
//  Material.h
//  Three.cpp
//
//  Created by Saburo Okita on 30/06/14.
//  Copyright (c) 2014 Saburo Okita. All rights reserved.
//

#ifndef __Three_cpp__Material__
#define __Three_cpp__Material__

#include <iostream>
#include <string>
#include "Constants.h"
#include "Math.h"
#include "EventDispatcher.h"
#include "Color.h"

using namespace std;


namespace three {
    static int MaterialIDCount = 0;
    
    class Material : public EventDispatcher {
    protected:
        int id;
        string uuid;
        string name;
        
    public:
        Material();
        Material(const Material& other);
        virtual ~Material();
        
        Material clone() const;
        
        /* Data members */
        int   side;
        float opacity;
        bool  transparent;
        int   blending;
        int   blendSrc;
        int   blendDst;
        int   blendEquation;
        bool  depthTest;
        bool  depthWrite;
        bool  polygonOffset;
        float polygonOffsetFactor;
        float polygonOffsetUnits;
        float alphaTest;
        float overdraw;
        bool  visible;
        bool  needsUpdate;
        
        
        /** Output stream overloading */
        friend std::ostream &operator <<( std::ostream& os, const Material& obj ) {
            os << "Material {" << std::endl;
            os << "\tside               : " << obj.side                << std::endl;
            os << "\topacity            : " << obj.opacity             << std::endl;
            os << "\ttransparent        : " << obj.transparent         << std::endl;
            os << "\tblending           : " << obj.blending            << std::endl;
            os << "\tblendSrc           : " << obj.blendSrc            << std::endl;
            os << "\tblendDst           : " << obj.blendDst            << std::endl;
            os << "\tblendEquation      : " << obj.blendEquation       << std::endl;
            os << "\tdepthTest          : " << obj.depthTest           << std::endl;
            os << "\tdepthWrite         : " << obj.depthWrite          << std::endl;
            os << "\tpolygonOffset      : " << obj.polygonOffset       << std::endl;
            os << "\tpolygonOffsetFactor: " << obj.polygonOffsetFactor << std::endl;
            os << "\tpolygonOffsetUnits : " << obj.polygonOffsetUnits  << std::endl;
            os << "\talphaTest          : " << obj.alphaTest           << std::endl;
            os << "\toverdraw           : " << obj.overdraw            << std::endl;
            os << "\tvisible            : " << obj.visible             << std::endl;
            os << "\tneedsUpdate        : " << obj.needsUpdate         << std::endl;
            os << "}";
            return os;
        }

    };
}

#endif /* defined(__Three_cpp__Material__) */
