// Review03.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>

const int maxiterations = 50;

void DrawFrame(int width, int height);

int main(int argc, char* argv[])
{
    al_init();
    al_init_font_addon();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_EVENT_QUEUE* eventQueue = nullptr;

    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(display));

    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(font,
                al_map_rgb(255, 255, 255),
                400, 300,
                ALLEGRO_ALIGN_CENTER,
                "Welcome to Review03");

    while (true)
    {
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.06);

        bool get_event = al_wait_for_event_until(eventQueue, &event, &timeout);

        if (get_event && (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
        {
            break;
        }

        DrawFrame(800, 600);

        al_flip_display();
    }

    al_destroy_font(font);
    al_destroy_display(display);

    return 0;
}

void DrawFrame(int width, int height)
{
    // Drawing individual pixels in this manner is incredibly slow. This is only for illustration
    // on the C syntax.
    for (int index = 0; index < maxiterations; index++)
    {
        al_put_pixel(rand() % width, rand() % height, al_map_rgb(rand()%255, rand()%255, rand()%255));
    }
}
