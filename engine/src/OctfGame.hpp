#ifndef _OCTF_GAME_H_
#define _OCTF_GAME_H_

#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Common/b2Math.h"
#include "Box2D/Dynamics/b2World.h"

#include <utility>

class b2World;
class b2Body;
class OctfBall;

/*   ==== Units ==== 
 *
 *      Length: m
 *      Mass:   Kg
 *      Time:   s
 *
 */

extern float32 CONSTANTS_PI;

typedef struct {
    float32 radius;
    float32 restitution;
    float32 density;
    float32 linDamping;
    float32 angularDamping;
    float32 accel;
} model;

typedef struct {
    std::pair<int,int> framerate;
    b2Vec2 gravity;
    model ballModel;
} gameSettings;

class OctfGame {

public:
    OctfGame(gameSettings settings);
    ~OctfGame();
    void start();
    void print();
    void advance();
    b2World* getWorld();

    const gameSettings getSettings();
    OctfBall* createBallAtPos(int x, int y);
    inline bool isDone() {return fSteps > 3 * 60;} 


protected:
    /* hard coded run sim for 3 seconds.
     * eventually be team won or 12 min
     */

    inline void tick() {++fSteps;}

private:
    b2World* constructWorld();

    const gameSettings _m_gameSettings;
    const float32 _m_f32framerate;

    b2World* fWorld;
    uint32_t fSteps;
};

#endif
