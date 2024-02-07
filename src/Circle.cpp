#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <..\headers\Circle.h>
using namespace std;
typedef struct Node
{
    int radius;
} Node;

Circle::Circle()
{
    this->mRadius = 0;
}
Circle::Circle(double radius)
{
    this->mRadius = radius;
}
Circle::Circle(const Circle &other)
{
    this->mRadius = other.mRadius;
}
Circle::Circle(Circle &&other)
{
    this->mRadius = other.mRadius;
    other.mRadius = double(NULL);
}
Circle &Circle::operator=(Circle &other)
{
    this->mRadius = other.mRadius;
    return *this;
}
Circle::~Circle()
{
    // cout<<"***Memory for the Circle released***"<<endl;
}
double Circle::getAreaOfCircle()
{
    return M_PI * (this->mRadius) * (this->mRadius);
}
double Circle::getCircumferenceOfCircle()
{
    return 2 * M_PI * (this->mRadius);
}
void Circle::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    //This is generate the GNU_PLOT file in the current directory only where the application is running
    ofstream scriptFile("Circle.gp");
    if (!scriptFile.is_open()) 
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    scriptFile << "set parametric" << endl;
    scriptFile << "set size ratio 1" << endl;
    scriptFile << "set xrange [-8:" << 8 << "]" << endl;  
    scriptFile << "set yrange [-8:" << 8 << "]" << endl; 
    scriptFile << "plot " << nodePtr->radius << " * cos(t), " << nodePtr->radius << " * sin(t) with lines title 'Circle'" << endl;

    scriptFile.close();

    if (system("Circle.gp") == -1) {
        cerr << "Error executing Gnuplot." << endl;
        return ;
    }
}