#include "OctfBall.hpp"
#include "OctfGame.hpp" //remove after undoing typdef hack

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"

OctfBall::OctfBall(b2World* world, b2BodyDef ballBodyDef, float32 radius) {
    b2Body* ballBody = world->CreateBody(&ballBodyDef);

    b2CircleShape ballShape;
    ballShape.m_p.Set(0,0); //position, relative to body
    ballShape.m_radius = radius;

    b2FixtureDef ballFixture;
    ballFixture.shape = &ballShape;
    ballBody->CreateFixture(&ballFixture);
    this->setBody(ballBody);
}

OctfBall::~OctfBall() { }
