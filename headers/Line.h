#include <.\Shape.h>
class Line:public Shape
{
public:
    Line();
    Line(double mX1, double mY1, double mX2, double mY2);
    Line(const Line &other);
    Line(Line &&other);
    Line &operator=(Line &other);
    ~Line();
    double getLengthOfLine();
    double getSlopeOfLine();
    void plot(void *ptr);
private:
    double mX1, mY1;
    double mX2, mY2;
};
