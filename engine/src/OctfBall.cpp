#include "OctfBall.hpp"
#include "OctfGame.hpp" //remove after undoing typdef hack

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"

OctfBall::OctfBall(ballModel defaultModel, int x, int y) {
    // maybe just pass the b2BodyDef
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(x,y);
    ballBodyDef.linearDamping = defaultModel.linDamping;

    // test these later:
    /*
    ballBodyDef.allowSleep = true;
    ballBodyDef.awake = true;
    ballBodyDef.bullet = true;
    */

    b2Body* ballBody = _gameWorld->CreateBody(&ballBodyDef);

    b2CircleShape ballShape;
    ballShape.m_p.Set(0,0); //position, relative to body
    ballShape.m_radius = defaultModel.radius;

    b2FixtureDef ballFixture;
    ballFixture.shape = &ballShape;
    ballBody->CreateFixture(&ballFixture);
    this->setBody(ballBody);
}

OctfBall::~OctfBall() { }
