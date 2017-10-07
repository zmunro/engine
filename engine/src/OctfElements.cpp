#include "OctfElements.hpp"

class b2World;
class b2Body;

OctfElement::OctfElement() { }
OctfElement::OctfElement(b2World* aWorld) : _gameWorld(aWorld) { }
OctfElement::~OctfElement() { }

void OctfElement::setBody(b2Body* toSet) { _body = toSet; }

OctfElementDynamic::OctfElementDynamic() { }
OctfElementDynamic::~OctfElementDynamic() { }

OctfElementStatic::OctfElementStatic() { }
OctfElementStatic::~OctfElementStatic() { }
