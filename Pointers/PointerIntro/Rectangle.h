#pragma once
#include "Shape.h"

class Rectangle : public VirtualShape
{
public:
    Rectangle();
    Rectangle(float inX, float inY, float width, float height);

    virtual ~Rectangle();

    virtual void Draw() override;

    float mWidth;
    float mHeight;
};
