#include "Rectangle.h"
#include <stdio.h>


Rectangle::Rectangle() : VirtualShape() {}
Rectangle::Rectangle(float inX, float inY, float width, float height) : VirtualShape(inX, inY), mWidth(width), mHeight(height) {}


Rectangle::~Rectangle() {}

void Rectangle::Draw()
{
    printf( "Drawing a rectangle at (%f, %f, %f, %f)\n",
        mCenter.x - (mWidth / 2.0f), mCenter.y - (mHeight / 2.0f),
        mCenter.x + (mWidth / 2.0f), mCenter.y + (mHeight / 2.0f));
}
