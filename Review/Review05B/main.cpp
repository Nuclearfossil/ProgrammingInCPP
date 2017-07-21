
struct Point2D
{
    float x;
    float y;

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

    virtual ~Shape();

    Point2D mCenter;

    virtual void Draw() = 0;
};


void main()
{
    Shape** shapes = new Shape*[10];
    int* valueA = new int;
    int* valueB = new int();

    for (int index = 0; index < 10; index++)
    {
        shapes[index]->Draw();
        (*valueA)++;
        (*valueB)++;
    }

    delete[] shapes;
}