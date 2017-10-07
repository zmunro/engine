#ifndef _OCTF_ELEMENTS_H_
#define _OCTF_ELEMENTS_H_

class b2World;
class b2Body;

/* Base class for all things on the map,
 * useful for common methods like logging.
 * Probably the most useful thing it will
 * do is register all collision pairs
 * so a controller can decide what to do.
 */
class OctfElement {

public:
    OctfElement();
    OctfElement(b2World* aWorld);
    ~OctfElement();

// find a better way to do this
protected:
    b2World* _gameWorld;
    void setBody(b2Body* toSet);
    
private:
    b2Body* _body;
};

/* Things that can move. for now just balls
 * but there's no harm in abstracting
 */
class OctfElementDynamic : public OctfElement {

public:
    //maybe assert _body is dynamic
    OctfElementDynamic();
    ~OctfElementDynamic();
    

// self explanatory
/*
    void kill();
    void respawn();
    void remove();

private:
    bool _isDead;
    bool _isRespawning;
    bool _isRemoved;
*/
};

/* Things that can't move: walls, spikes etc.
 * Each one will cover one tile.
 */

class OctfElementStatic : public OctfElement {

public:
    OctfElementStatic();
    ~OctfElementStatic();
};

#endif
