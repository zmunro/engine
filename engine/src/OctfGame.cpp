#include "OctfGame.hpp"
#include "OctfBall.hpp"

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Dynamics/b2World.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include <utility>

OctfGame::OctfGame(gameSettings settings)
    : _m_gameSettings(settings),
      _m_f32framerate((float32) settings.framerate.first / settings.framerate.second),
      fWorld(constructWorld()),
      fSteps(0)
{ }

OctfGame::~OctfGame()
{ }

OctfBall* OctfGame::createBallAtPos(int x, int y) {
    auto& ball = *(new OctfBall(fWorld, x, y, _m_gameSettings.ballModel));
    return &ball;
}

void OctfGame::advance() {
    fWorld->Step(_m_f32framerate /*timeStep*/, 6 /*velocityIterations*/, 2 /*positionIterations*/);
    print();
    tick();
}

//this can stay for now until graphical tests
void OctfGame::print() {
  auto body = fWorld->GetBodyList();
  b2Vec2 position = body->GetPosition();
  float32 angle = body->GetAngle();
  std::cout << std::setprecision(2) << std::fixed
	    << "x = " << position.x << " "
	    << "y = " << position.y << " " 
	    << "a = " << angle << " "
	    << "t = " << fSteps*_m_f32framerate << "s " << std::endl;
}

const gameSettings OctfGame::getSettings() {
    return _m_gameSettings;
}

b2World* OctfGame::constructWorld() {
    auto& world = *(new b2World(_m_gameSettings.gravity));
    // assign other physics params
    // add map to world from _gameSettings.map
    // add balls

    return &world;
}
