#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

ALLEGRO_FONT* gFont = nullptr;

void main()
{
    al_init();
    al_init_font_addon();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    gFont = al_create_builtin_font();

    // Shape* shapes[10];
    Shape** shapes = new Shape*[10];

    shapes[0] = new Circle(20.0f, 30.0f, 5.0f);
    shapes[1] = new Circle(40.0f, 60.0f, 10.0f);
    shapes[2] = new Circle(60.0f, 90.0f, 15.0f);
    shapes[3] = new Circle(80.0f, 120.0f, 20.0f);
    shapes[4] = new Circle(100.0f, 150.0f, 30.0f);
    shapes[5] = new Rectangle(200.0f, 300.0f, 5.0f , 5.0f);
    shapes[6] = new Rectangle(220.0f, 330.0f, 10.0f, 10.0f);
    shapes[7] = new Rectangle(240.0f, 360.0f, 15.0f, 15.0f);
    shapes[8] = new Rectangle(260.0f, 390.0f, 20.0f, 20.0f);
    shapes[9] = new Rectangle(280.0f, 420.0f, 25.0f, 25.0f);

    for (int index = 0; index < 10; index++)
    {
        shapes[index]->Draw();
    }

    al_flip_display();
    al_rest(5.0);

    /*
    delete shapes[0];
    delete shapes[1];
    delete shapes[2];
    delete shapes[3];
    delete shapes[4];
    delete shapes[5];
    delete shapes[6];
    delete shapes[7];
    delete shapes[8];
    delete shapes[9];
    */

    delete shapes;

    al_destroy_font(gFont);
    al_destroy_display(display);
}