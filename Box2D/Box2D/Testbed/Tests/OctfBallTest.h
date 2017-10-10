#ifndef _OCTF_BALL_TEST_H
#define _OCTF_BALL_TEST_H

#include "OctfGame.hpp"

class OctfBallTest : public Test {

public:
    OctfBallTest() //m_world is protected of Test
    {
        model defaultBall = {1.0f,1.0f,1.0f,0.5f,0.5f};

        /* keeping gravity until we have motion
         * commands so that we can see stuff
         * happening
         */
        b2Vec2 defaultGrav(0.0f,-10.0f);
        constexpr std::pair<int,int> defaultFR(std::make_pair(1,60));

        OctfGame* Game(new OctfGame((gameSettings){defaultFR,defaultGrav,defaultBall}));

        m_world = Game->getWorld(); //m_world is protected of Test and is what gets drawn

        Game->createBallAtPos(0.0f,0.0f);
    }

    /* We won't pass settings
     * because they are baked into
     * the testbed main and modifiable
     * in the GUI
     */
    void Step(Settings* settings) {
        //run the default physics and rendering
        Test::Step(settings); 

        //show some text in the main screen
        m_textLine += 15;
    }

    static Test* Create() {
        return new OctfBallTest;
    }

private:
    OctfGame* _m_game;
    Settings* _m_settings;
};

#endif
