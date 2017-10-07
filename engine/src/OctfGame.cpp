#include "OctfGame.hpp"

#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Dynamics/b2World.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

OctfGame::OctfGame() : fWorld(constructWorld()), fSteps(0) {
}

OctfGame::~OctfGame()
{ }

void OctfGame::advance() {
    fWorld->Step(fInterval /*timeStep*/, 6 /*velocityIterations*/, 2 /*positionIterations*/);
    tick();
}

//this can stay for now until graphical tests
/*
void OctfGame::print() {
    // could iterate over the body list, but just printing the first body is good enough for now
    auto body = fWorld->GetBodyList();
    b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();
    std::cout << std::setprecision(2) << std::fixed
              << "x = " << position.x << " "
              << "y = " << position.y << " " 
              << "a = " << angle << " "
              << "t = " << fSteps*fInterval << "s " << std::endl;
}
*/

void OctfGame::start() {
    std::thread([this]() {
        std::chrono::duration<float32, FrameRate> aStep(1);
        auto x = std::chrono::steady_clock::now() + aStep;
        while (true) {
            advance();
            std::this_thread::sleep_until(x);
            x = std::chrono::steady_clock::now() + aStep;
        }
    }).detach();
}

b2World* OctfGame::constructWorld() {
    auto& world = *(new b2World(_gravity));
    // assign other physics params
    // add map to world from _gameSettings.map
    // add balls

    return &world;
}
