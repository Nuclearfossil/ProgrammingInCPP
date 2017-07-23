#include "Shape.h"

VirtualShape::VirtualShape() : mCenter(0.0f, 0.0f)
{}

VirtualShape::VirtualShape(float inX, float inY) : mCenter(inX, inY)
{}


VirtualShape::~VirtualShape() {}