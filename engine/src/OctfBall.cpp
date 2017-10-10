#include "OctfBall.hpp"
#include "OctfGame.hpp" //remove after undoing typdef hack

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"

float32 CONSTANTS_PI = 3.141592;

OctfBall::OctfBall(b2World* world, int x, int y, model ballModel) 
    : _isMovingL(false), 
      _isMovingU(false),
      _isMovingR(false),
      _isMovingD(false),
      _moveForceModulus(ballModel.accel
                 * ballModel.density
                 * std::pow(ballModel.radius,2)
                 * CONSTANTS_PI)

{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x,y);
    bodyDef.linearDamping = ballModel.linDamping;
    bodyDef.angularDamping = ballModel.angularDamping;

    // test these later:
    /*
    bodyDef.allowSleep = true;
    bodyDef.awake = true;
    bodyDef.bullet = true;
    */
    b2Body* ballBody = world->CreateBody(&bodyDef);

    b2CircleShape ballShape;
    ballShape.m_p.Set(0,0); //position, relative to body
    ballShape.m_radius = ballModel.radius;

    b2FixtureDef ballFixture;
    ballFixture.shape = &ballShape;
    ballFixture.density = ballModel.density;
    ballBody->CreateFixture(&ballFixture);
    this->setBody(ballBody);
}

OctfBall::~OctfBall() { }

void OctfBall::moveInDir(b2Vec2 direction) {
    this->getBody()->ApplyForceToCenter(_moveForceModulus * direction, true);
}

void OctfBall::moveLeft() {
    moveInDir(_LEFT);
}
void OctfBall::moveUp() {
    moveInDir(_UP);
}
void OctfBall::moveRight() {
    moveInDir(_RIGHT);
}
void OctfBall::moveDown() {
    moveInDir(_DOWN);
}
