
#include <allegro5/allegro_font.h>

struct Point2D
{
    float x;    // 4 bytes
    float y;    // 4 bytes
};              // 8 bytes total

struct RGB
{
    float r;    // 4 bytes
    float g;    // 4 bytes
    float b;    // 4 bytes
};              // 12 bytes total

struct RGBA
{
    float r;    // 4 bytes
    float g;    // 4 bytes
    float b;    // 4 bytes
    float a;    // 4 bytes
};              // 16 bytes total

struct UV
{
    float u;    // 4 bytes
    float v;    // 4 bytes
};              // 8 bytes total


struct Vertex
{
    Point2D position;   // 8 bytes
    RGB     color;      // 12  bytes
    UV      texCoord;   // 8 bytes
};                      // 28 bytes total

struct VisibleVertex01
{
    bool    visible;    // 1 byte
    Point2D position;   // 8 bytes
    RGB     color;      // 12 bytes
    UV      texCoord;   // 8 bytes
};                      // 29 bytes total

#pragma pack(push)
#pragma pack(1)
struct VisibleVertex02
{
    bool    visible;    // 1 byte
    Point2D position;   // 8 bytes
    RGB     color;      // 12 bytes
    UV      texCoord;   // 8 bytes
};                      // 29 bytes total
#pragma pack(pop)

extern ALLEGRO_FONT* gFont;

void Example02()
{
    Point2D textPos;
    textPos.x = 10.0f;
    textPos.y = 20.0f;

    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of char:            %02d bytes", sizeof(char));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of float:           %02d bytes", sizeof(float));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of bool:            %02d bytes", sizeof(bool));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Point2D:         %02d bytes", sizeof(Point2D));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGB:             %02d bytes", sizeof(RGB));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of RGBA:            %02d bytes", sizeof(RGBA));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of UV:              %02d bytes", sizeof(UV));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of Vertex:          %02d bytes", sizeof(Vertex));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of VisibleVertex01: %02d bytes", sizeof(VisibleVertex01));
    textPos.y += 15;
    al_draw_textf(gFont, al_map_rgb(255, 255, 255), textPos.x, textPos.y, ALLEGRO_ALIGN_LEFT, "Size of VisibleVertex02: %02d bytes", sizeof(VisibleVertex02));
    textPos.y += 15;


    al_flip_display();

    al_rest(5.0);

}