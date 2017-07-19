#include "Rectangle.h"
#include <allegro5/allegro_primitives.h>


Rectangle::Rectangle() : Shape()
{
}

Rectangle::Rectangle(float inX, float inY, float width, float height) : Shape(inX, inY), mWidth(width), mHeight(height)
{}


Rectangle::~Rectangle() {}

void Rectangle::Draw()
{
    al_draw_rectangle(
        mCenter.x - (mWidth / 2.0f), mCenter.y - (mHeight / 2.0f),
        mCenter.x + (mWidth / 2.0f), mCenter.y + (mHeight / 2.0f),
        al_map_rgb(255, 255, 255),
        1.0f);
}
