#include "Circle.h"

#include <stdio.h>

Circle::Circle() : mRadius(1.0f) {}
Circle::Circle(float inX, float inY, float radius) : VirtualShape(inX, inY), mRadius(radius) {}

Circle::~Circle() {}

void Circle::Draw()
{
    printf("Drawing a circle at (%f,%f), radius %f\n",mCenter.x, mCenter.y, mRadius);
}
