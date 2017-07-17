#include "example01.h"
#include "example02.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_FONT* gFont = nullptr;

enum Executables
{
    ex01 = 0,
    ex02,
    endoflist
};

void main()
{
    al_init();
    al_init_font_addon();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    gFont = al_create_builtin_font();

    Executables toRun = ex02;

    switch (toRun)
    {
        case ex01:
        {
            Example01();
            break;
        }

        case ex02:
        {
            Example02();
            break;
        }

        default:
            break;
    }

    al_destroy_font(gFont);
    al_destroy_display(display);

}