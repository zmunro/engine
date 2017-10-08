#include "OctfElements.hpp"

class b2World;
class b2Body;

OctfElement::OctfElement() { }
OctfElement::~OctfElement() { }

void OctfElement::setBody(b2Body* toSet) { _body = toSet; }

OctfElementDynamic::OctfElementDynamic() { }
OctfElementDynamic::~OctfElementDynamic() { }

OctfElementStatic::OctfElementStatic() { }
OctfElementStatic::~OctfElementStatic() { }
