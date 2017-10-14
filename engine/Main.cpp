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
    constexpr int defaultFR(60);
    int defaultVelIter = 6;
    int defaultPosIter = 2;
    int defaultDur = 12 * 60;

    OctfGame* Game(new OctfGame((gameSettings){defaultFR,
                                               defaultGrav,
                                               defaultVelIter,
                                               defaultPosIter,
                                               defaultDur,
                                               defaultBall}));

    using rate = std::ratio<1,defaultFR>;
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
