#include "OctfElements.hpp"

class b2Body;

OctfElement::OctfElement() { }
OctfElement::~OctfElement() { }

void OctfElement::setBody(b2Body* toSet) { _body = toSet; }
b2Body* OctfElement::getBody() { return _body; }

OctfElementDynamic::OctfElementDynamic() { }
OctfElementDynamic::~OctfElementDynamic() { }

OctfElementStatic::OctfElementStatic() { }
OctfElementStatic::~OctfElementStatic() { }
