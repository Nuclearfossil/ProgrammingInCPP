
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

class VirtualShape
{
public:
    VirtualShape();
    VirtualShape(float inX, float inY);

    virtual ~VirtualShape();

    Point2D mCenter;

    virtual void Draw() = 0;
};


void main()
{
    VirtualShape** shapes = new VirtualShape*[10];
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