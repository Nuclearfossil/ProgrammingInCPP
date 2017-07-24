#pragma once

#include "Shape.h"

class Circle : public VirtualShape
{
public:
    Circle();
    Circle(float inX, float inY, float radius);

    virtual ~Circle();

    virtual void Draw() override;

    float mRadius;
};