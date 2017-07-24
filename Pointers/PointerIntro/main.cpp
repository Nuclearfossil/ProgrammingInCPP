/// ---------------------------------------------------------------------------------
/// I've decided that for this batch of code, instead of using the C++ shell website
/// I'm going to write console apps. We're going to want to inspect memory a fair
/// bit and the memory view in Dev Studio is one of the better ways of seeing what's
/// going on.
/// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
#include <memory.h>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

void main()
{
    printf("How big is a Shape? %lu\n", sizeof(Shape));

    // A few standard ways of accessing pointers.
    // First, using a basic data type
    int A;
    int* ptrA = &A;                 // Not allocated, do not delete!

    int* ptrAHeap = new int;
    int* ptrBHeap = new int();

    int* arrayA[10];                // No allocations, do not delete!
    int** arrayB = new int*[10];
    int** arrayC = new int*[10]();

    delete ptrAHeap;
    delete ptrBHeap;

    delete[] arrayB;
    delete[] arrayC;

    // Next, using a simple class
    printf("Creating shapeA\n");
    Shape shapeA;

    printf("Creating ptrShapeA\n");
    Shape* ptrShapeA = &shapeA;

    printf("Creating ptrShapeB\n");
    Shape* ptrShapeB = new Shape();
    ptrShapeB->value = 5150;
    Shape* ptrShapeC = ptrShapeB;

    printf("Creating arrayOfShapes01\n");
    Shape* arrayOfShapes01[10];

    printf("Creating arrayOfShapes02\n");
    Shape** arrayOfShapes02 = new Shape*[10];

    printf("Creating arrayOfShapes03\n");
    Shape** arrayOfShapes03 = new Shape*[10]();

    // And now delete everything you've allocated
    printf("Deleting prtShapeB\n");
    delete ptrShapeB;
    memset(ptrShapeB, 0, sizeof(Shape));  // Mimicing someone else re-using the memory that was just freed

    ptrShapeC->Draw();

    printf("Deleting arrayOfShapes02\n");
    delete[] arrayOfShapes02;

    printf("Deleting arrayofShapes03\n");
    delete[] arrayOfShapes03;

    // What was the size of a Shape that contained a Point2D?
    printf("What's the size of a ShapeWithPoint? %lu\n", sizeof(ShapeWithPoint));

    // What do we get when we add only a virtual method to a Shape class
    printf("What's the size of a ShapeWithVirtual? %lu\n", sizeof(ShapeWithVirtual));

    // Let's look at VirtualShape:
    printf("What's the size of a VirtualShape? %lu\n", sizeof(VirtualShape));
    printf("What's the size of a Circle? %lu\n", sizeof(Circle));
    printf("What's the size of a Rectangle? %lu\n", sizeof(Rectangle));

    Shape* shapeNoVirtual = new Shape();

    shapeNoVirtual->Draw();

    VirtualShape* shapeCircleVirtual = new Circle();

    shapeCircleVirtual->Draw();

    VirtualShape* shapeRectangleVirtual = new Rectangle();

    shapeRectangleVirtual->Draw();

    printf("Press any key to continue:");
    _getch();
}