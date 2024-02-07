#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <..\headers\Ellipse.h>
using namespace std;
typedef struct Node
{
    int majorAxis;
    int minorAxis;
} Node;
Ellipse::Ellipse()
{
    this->mMajorAxis = 0;
    this->mMinorAxis = 0;
}
Ellipse::Ellipse(double majorAxis, double minorAxis)
{
    this->mMajorAxis = majorAxis;
    this->mMinorAxis = minorAxis;
}
Ellipse::Ellipse(const Ellipse &other)
{
    this->mMajorAxis = other.mMajorAxis;
    this->mMinorAxis = other.mMinorAxis;
}
Ellipse::Ellipse(Ellipse &&other)
{
    this->mMajorAxis = other.mMajorAxis;
    this->mMinorAxis = other.mMinorAxis;
    other.mMajorAxis = double(NULL);
    other.mMinorAxis = (double)NULL;
}
Ellipse &Ellipse::operator=(Ellipse &other)
{
    this->mMajorAxis = other.mMajorAxis;
    this->mMinorAxis = other.mMinorAxis;
    return *this;
}
Ellipse::~Ellipse()
{
    // cout<<"***Memory for the Ellipse released***"<<endl;
}
pair<double, double> Ellipse::getCenterOfEllipse()
{
    return make_pair(this->mMajorAxis / 2, this->mMinorAxis / 2);
}
double Ellipse::getEccentricityOfEllipse()
{
    return sqrt(1 - pow(this->mMinorAxis / this->mMajorAxis, 2));
}
double Ellipse::getFocalLengthOfEllipse()
{
    return sqrt(pow(this->mMajorAxis, 2) - pow(this->mMinorAxis, 2)) / 2;
}
double Ellipse::getAreaOfEllipse()
{
    return M_PI * this->mMajorAxis * this->mMinorAxis / 4;
}
void Ellipse::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    ofstream scriptFile("Ellipse.gp");
    if (!scriptFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    scriptFile << "set parametric" << endl;
    scriptFile << "set size ratio -1" << endl;
    scriptFile << "set xrange [-" << (nodePtr->majorAxis) * 2 << ":" << (nodePtr->majorAxis) * 2 << "]" << endl;
    scriptFile << "set yrange [-" << (nodePtr->minorAxis) * 2 << ":" << (nodePtr->minorAxis) * 2 << "]" << endl;
    scriptFile << "plot " << (nodePtr->majorAxis) << " * cos(t), " << (nodePtr->minorAxis) << " * sin(t) with lines title 'Ellipse'" << endl;

    scriptFile.close();

    if (system("Ellipse.gp") == -1)
    {
        cerr << "Error executing Gnuplot." << endl;
        return;
    }
}
