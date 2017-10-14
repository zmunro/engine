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
    int framerate; //fps
    b2Vec2 gravity;
    int velIter;
    int posIter;
    int gDuration; //in seconds
    model ballModel;
} gameSettings;

class OctfGame {

public:
    OctfGame(gameSettings settings);
    ~OctfGame();
    void start();
    void advance();
    b2World* getWorld();

    const gameSettings getSettings();
    OctfBall* createBallAtPos(int x, int y);
    inline bool isDone() {return _cFrames > _m_gameSettings.gDuration * _m_gameSettings.framerate;} 


protected:
    /* hard coded run sim for 3 seconds.
     * eventually be team won or 12 min
     */

private:
    b2World* constructWorld();
    inline void tick() {++_cFrames;}

    const gameSettings _m_gameSettings;
    const float32 _invFramerate;

    b2World* _m_world;
    uint32_t _cFrames; //cumulative frames elapsed
};

#endif
