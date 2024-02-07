#include <.\Shape.h>
class Ellipse:public Shape
{
public:
    Ellipse();
    Ellipse(double mMajorAxis, double mMinorAxis);
    Ellipse(const Ellipse &other);
    Ellipse(Ellipse &&other);
    Ellipse &operator=(Ellipse &other);
    ~Ellipse();
    std::pair<double, double> getCenterOfEllipse();
    double getEccentricityOfEllipse();
    double getFocalLengthOfEllipse();
    double getAreaOfEllipse();
    void plot(void *ptr);
private:
    double mMajorAxis, mMinorAxis;

};