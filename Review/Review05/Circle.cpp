#include "Circle.h"

#include <allegro5/allegro_primitives.h>

Circle::Circle() : mRadius(1.0f)
{
}

Circle::Circle(float inX, float inY, float radius) : Shape(inX, inY), mRadius(radius)
{}

Circle::~Circle() {}

void Circle::Draw()
{
    al_draw_circle(mCenter.x, mCenter.y, mRadius, al_map_rgb(255, 255, 255), 1.0f);
}
