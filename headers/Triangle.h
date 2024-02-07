#include <.\Shape.h>
class Triangle:public Shape
{
public:
    Triangle();
    Triangle(double mSideA, double mSideB, double mSideC);
    Triangle(const Triangle &other);
    Triangle(Triangle &&other);
    Triangle &operator=(Triangle &other);
    ~Triangle();
    double getAreaOfTriangle();
    double getPerimeterOfTriangle();
    double getSemiPerimeterOfTriangle();
    double getInRadiusOfTraingle();
    double getCircumRadiusOfTraingle();
    void plot(void *ptr);
private:
    double mSideA, mSideB, mSideC;
};