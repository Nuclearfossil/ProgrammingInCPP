#include "Shape.h"
#include <stdio.h>

Shape::Shape()
{
    printf("  -> Shape Constructor\n");
}

Shape::Shape(float inX, float inY)
{
    printf("  -> Shape Destructort\n");
}

Shape::~Shape() {}

void Shape::Draw()
{
    printf("  -> Drawing a shape\n");
}

ShapeWithPoint::ShapeWithPoint() {}
ShapeWithPoint::~ShapeWithPoint() {}

void ShapeWithPoint::Draw() {}


ShapeWithVirtual::ShapeWithVirtual()
{}

ShapeWithVirtual::~ShapeWithVirtual()
{}

void ShapeWithVirtual::Draw()
{

}



VirtualShape::VirtualShape() : mCenter(0.0f, 0.0f)
{
    printf("  -> Shape Constructor\n");
}

VirtualShape::VirtualShape(float inX, float inY) : mCenter(inX, inY)
{
    printf("  -> Shape Destructort\n");
}


VirtualShape::~VirtualShape() {}

void VirtualShape::Draw()
{
    printf("  -> Drawing a shape\n");
}
