#include <.\Shape.h>
class Square:public Shape
{
public:
    Square();
    Square(double mSide);
    Square(const Square &other);
    Square(Square &&other);
    Square &operator=(Square &other);
    ~Square();
    double getAreaOfSquare();
    double getPerimeterOfSquare();
    double getDiagonalOfSquare();
    void plot(void *ptr);
private:
    double mSide;
};