#pragma once

struct Point2D
{
    float x;
    float y;

    Point2D(float inX, float inY)
    {
        x = inX;
        y = inY;
    }
};

class VirtualShape
{
public:
    VirtualShape();
    VirtualShape(float inX, float inY);

    virtual ~VirtualShape();

    Point2D mCenter;

    virtual void Draw() = 0;
};