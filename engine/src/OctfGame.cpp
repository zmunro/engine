#include "OctfGame.hpp"
#include "OctfBall.hpp"

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Dynamics/b2World.h"

OctfGame::OctfGame(gameSettings settings)
    : _m_gameSettings(settings),
      _invFramerate((float32) 1 / settings.framerate),
      _m_world(constructWorld()),
      _cFrames(0)
{ }

OctfGame::~OctfGame()
{ }

OctfBall* OctfGame::createBallAtPos(int x, int y) {
    auto& ball = *(new OctfBall(_m_world, x, y, _m_gameSettings.ballModel));
    return &ball;
}

void OctfGame::advance() {
    _m_world->Step(_invFramerate, _m_gameSettings.velIter, _m_gameSettings.posIter);
    tick();
}

b2World* OctfGame::getWorld() { return _m_world; }

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
