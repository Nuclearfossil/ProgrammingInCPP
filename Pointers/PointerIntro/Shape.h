#pragma once

struct Point2D
{
    float x;
    float y;

    Point2D() : x(0.0f), y(0.0f) {}
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

    ~Shape();

    void Draw();

    int value;
};

#pragma pack(push)
#pragma pack(1)
class ShapeWithPoint
{
public:
    ShapeWithPoint();
    ~ShapeWithPoint();

    void Draw();

    // Point2D mCenter;
    int value;
};

class ShapeWithVirtual
{
public:
    ShapeWithVirtual();
    virtual ~ShapeWithVirtual();

    void Draw();

    // Point2D mCenter;
    int value;
};
#pragma pack(pop)

class VirtualShape
{
public:
    VirtualShape();
    VirtualShape(float inX, float inY);

    virtual ~VirtualShape();

    Point2D mCenter;

    virtual void Draw();
};