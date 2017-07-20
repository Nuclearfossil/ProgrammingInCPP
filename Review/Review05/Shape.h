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

class Shape
{
public:
    Shape();
    Shape(float inX, float inY);

    virtual ~Shape();

    Point2D mCenter;

    virtual void Draw() = 0;
};