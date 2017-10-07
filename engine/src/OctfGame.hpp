#ifndef _OCTF_GAME_H_
#define _OCTF_GAME_H_

#include "Box2D/Dynamics/b2World.h"

#include <memory>
#include <ratio>

class b2World;
class b2Body;

// quick hack fix later
typedef struct {
    float32 radius;
    float32 restitution;
    float32 density;
    float32 linDamping;
} ballModel;

class OctfGame {
using FrameRate = std::ratio<1,60>; // 60 Hz

public:
    OctfGame();
    ~OctfGame();
    void start();

protected:
    void advance();
    inline void tick() {++fSteps;}

private:
    b2World* constructWorld();

    // eventually put settings in class or something
    const b2Vec2 _gravity;

    constexpr static const float32 fInterval = float32(FrameRate::num) / FrameRate::den;
    std::unique_ptr<b2World> fWorld;
    uint32_t fSteps;
};

#endif
