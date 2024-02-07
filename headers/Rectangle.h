#include <.\Shape.h>
class Rectangle:public Shape
{
public:
    Rectangle();
    Rectangle(double mLength, double mBreadth);
    Rectangle(const Rectangle &other);      // copy constructor
    Rectangle(Rectangle &&other);           // move constructor
    Rectangle &operator=(Rectangle &other); // operator =
    ~Rectangle();
    double getAreaOfRectangle();
    double getPerimeterOfRectangle();
    double getDiagonalOfRectangle();
    void plot(void *ptr);
private:
    double mLength, mBreadth;
};
