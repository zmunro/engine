#ifndef _OCTF_BALL_H_
#define _OCTF_BALL_H_

#include "OctfElements.hpp"
#include "OctfGame.hpp" // remove later

#include "Box2D/Common/b2Settings.h"

class OctfBall : private OctfElementDynamic {
    
public:
    OctfBall(b2World* world, int x, int y, model ballModel);
    ~OctfBall();

    void moveLeft();
    void moveUp();
    void moveRight();
    void moveDown();

protected:
    void moveInDir(b2Vec2 direction) override;


private:
    float32 _moveForceModulus;

    b2Vec2 _LEFT = b2Vec2(-1.0f,0.0f);
    b2Vec2 _UP = b2Vec2(0.0f,1.0f);;
    b2Vec2 _RIGHT = b2Vec2(1.0f,0.0f);;
    b2Vec2 _DOWN = b2Vec2(0.0f,-1.0f);;

    bool _isMovingL;
    bool _isMovingU;
    bool _isMovingR;
    bool _isMovingD;
};

#endif
