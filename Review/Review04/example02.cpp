
#include <allegro5/allegro_font.h>

struct Point2D
{
    float x;
    float y;
};

struct RGB
{
    float r;
    float g;
    float b;
};

struct RGBA
{
    float r;
    float g;
    float b;
    float a;
};

struct UV
{
    float u;
    float v;
};


struct Vertex
{
    Point2D position;
    RGB     color;
    UV      texCoord;
};

struct VisibleVertex01
{
    bool    visible;
    Point2D position;
    RGB     color;
    UV      texCoord;
};

extern ALLEGRO_FONT* gFont;

void Example02()
{
    Point2D textPos;
    textPos.x = 10.0f;
    textPos.y = 20.0f;

    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of char:            %d bytes", sizeof(char));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of float:           %d bytes", sizeof(float));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of bool:            %d bytes", sizeof(bool));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Point2D:         %d bytes", sizeof(Point2D));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGB:             %d bytes", sizeof(RGB));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGBA:            %d bytes", sizeof(RGBA));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of UV:              %d bytes", sizeof(UV));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Vertex:          %d bytes", sizeof(Vertex));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of VisibleVertex01: %d bytes", sizeof(VisibleVertex01));
    textPos.y += 15;


    al_flip_display();

    al_rest(5.0);

}