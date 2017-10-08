#include "OctfGame.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <ratio>
#include <sstream>
#include <thread>
#include <utility>


int main(int argc, char** argv) {

    /* TODO:
     * 1. find the good values from tp
     * 2. configure to read from disk
     */
    model defaultBall = {1.0f,1.0f,1.0f,0.5f,0.5f};

    /* keeping gravity until we have motion
     * commands so that we can see stuff
     * happening
     */
    b2Vec2 defaultGrav(0.0f,-10.0f);
    constexpr std::pair<int,int> defaultFR(std::make_pair(1,60));

    OctfGame* Game(new OctfGame((gameSettings){defaultFR,defaultGrav,defaultBall}));

    Game->createBallAtPos(10.0f,20.0f);

    using rate = std::ratio<defaultFR.first,defaultFR.second>;
    std::thread([Game]() {
        std::chrono::duration<float32, rate> aStep(1);
        auto x = std::chrono::steady_clock::now() + aStep;
        while (!Game->isDone()) {
            Game->advance();
            std::this_thread::sleep_until(x);
            x = std::chrono::steady_clock::now() + aStep;
        }
    }).join();

    return 0;
}
