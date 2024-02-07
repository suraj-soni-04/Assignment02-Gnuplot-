#include<.\Shape.h>
class Circle:public Shape
{
    public:
        Circle();
        Circle(double mRadius);
        Circle(const Circle &other);
        Circle(Circle &&other);
        Circle& operator=(Circle &other);
        ~Circle();
        double getAreaOfCircle();
        double getCircumferenceOfCircle();
        void plot(void *ptr);
    private:
        double mRadius;

};