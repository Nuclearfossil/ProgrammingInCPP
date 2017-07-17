/// =====================================================================================
/// In this example, we look at defining new data types using the `struct` keyword
/// =====================================================================================

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

extern ALLEGRO_FONT* gFont;

/// standard C++ definition of a struct
struct Vertex
{
    float x;
    float y;
};

/// definition of a struct with an instance of the struct (a variable,
/// in this case, called `gGlobalPoint`)
struct Point3D
{
    float x;
    float y;
    float z;
} gGlobalPoint;

/// The more C friendly version
extern "C"
{
    typedef struct Point2D
    {
        float x;
        float y;
    } Point2D;
}

const float width = 800.0f;
const float height = 600.0f;

void Example01()
{
    struct Vertex point1; // This is valid (and very c like)
    Vertex point2;  // This is valid, and C++

    gGlobalPoint.x = 0.5f * width;
    gGlobalPoint.y = 0.25f * height;

    point1.x = 0.0f;
    point1.y = 0.0f;

    point2.x = 1.0f * width;
    point2.y = 1.0f * height;

    /// An anonymous struct
    struct 
    {
        float x;
        float y;
    } point3;
    point3.x = .75f * width;
    point3.y = .5f * height;

    Point2D point4; // This is C like
    point4.x = .25f * width;
    point4.y = .4f * height;

    // Initialization of the new variable `textPos`
    Vertex textPos =
    {
        500.0f,  // x field of Vertex
        20.0f    // y field of Vertex
    };

    al_draw_textf(gFont, 
        al_map_rgb(255, 255, 255), 
        textPos.x, textPos.y, 
        ALLEGRO_ALIGN_LEFT, 
        "Point1 (%f, %f)", point1.x, point1.y);
    textPos.y += 15;

    al_draw_textf(gFont, 
        al_map_rgb(255, 255, 255), 
        textPos.x, textPos.y, 
        ALLEGRO_ALIGN_LEFT, 
        "Point2 (%f, %f)", point2.x, point2.y);
    textPos.y += 15;

    al_draw_textf(gFont, 
        al_map_rgb(255, 255, 255), 
        textPos.x, textPos.y, 
        ALLEGRO_ALIGN_LEFT, 
        "Point3 (%f, %f)", point3.x, point3.y);
    textPos.y += 15;

    al_draw_textf(gFont, 
        al_map_rgb(255, 255, 255), 
        textPos.x, textPos.y, 
        ALLEGRO_ALIGN_LEFT, 
        "Point4 (%f, %f)", point4.x, point4.y);
    textPos.y += 15;

    al_draw_textf(gFont, 
        al_map_rgb(255, 255, 255), 
        textPos.x, textPos.y, 
        ALLEGRO_ALIGN_LEFT, 
        "gGlobalPoint (%f, %f)", gGlobalPoint.x, gGlobalPoint.y);
    textPos.y += 15;

    al_draw_line(point1.x, point1.y, point2.x, point2.y, al_map_rgb(255, 255, 255), 1);
    al_draw_line(point2.x, point2.y, point3.x, point3.y, al_map_rgb(255, 0, 0), 1);
    al_draw_line(point3.x, point3.y, point4.x, point4.y, al_map_rgb(0, 255, 0), 1);
    al_draw_line(point4.x, point4.y, gGlobalPoint.x, gGlobalPoint.y, al_map_rgb(255, 0, 255), 1);
    al_draw_line(gGlobalPoint.x, gGlobalPoint.y, point1.x, point1.y, al_map_rgb(255, 255, 0), 1);

    al_flip_display();
    al_rest(5.0);
};