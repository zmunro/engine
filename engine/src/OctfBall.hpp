#ifndef _OCTF_BALL_H_
#define _OCTF_BALL_H_

#include "OctfElements.hpp"
#include "OctfGame.hpp" // remove later

#include "Box2D/Common/b2Settings.h"

class OctfBall : private OctfElementDynamic {
    
public:
    OctfBall(b2World* world, b2BodyDef ballBodyDef, float32 radius);
    ~OctfBall() final;
};

#endif
