#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <..\headers\Triangle.h>
using namespace std;
typedef struct Node
{
    int sideA;
    int sideB;
    int sideC;
} Node;
Triangle::Triangle()
{
    this->mSideA = 0;
    this->mSideB = 0;
    this->mSideC = 0;
}
Triangle::Triangle(double sideA, double sideB, double sideC)
{
    this->mSideA = sideA;
    this->mSideB = sideB;
    this->mSideC = sideC;
}
Triangle::Triangle(const Triangle &other)
{
    this->mSideA = other.mSideA;
    this->mSideB = other.mSideB;
    this->mSideC = other.mSideC;
}
Triangle::Triangle(Triangle &&other)
{
    this->mSideA = other.mSideA;
    this->mSideB = other.mSideB;
    this->mSideC = other.mSideC;
    other.mSideA = double(NULL);
    other.mSideB = double(NULL);
    other.mSideC = double(NULL);
}
Triangle &Triangle::operator=(Triangle &other)
{
    this->mSideA = other.mSideA;
    this->mSideB = other.mSideB;
    this->mSideC = other.mSideC;
    return *this;
}
Triangle::~Triangle()
{
    // cout<<"*** Triangle Memory got released ***"<<endl;
}
double Triangle::getAreaOfTriangle()
{
    double s = getSemiPerimeterOfTriangle();
    return sqrt(s * (s - this->mSideA) * (s - this->mSideB) * (s - this->mSideC));
}
double Triangle::getPerimeterOfTriangle()
{
    return this->mSideA + this->mSideB + this->mSideC;
}
double Triangle::getSemiPerimeterOfTriangle()
{
    return getPerimeterOfTriangle() / 2.0;
}
double Triangle::getInRadiusOfTraingle()
{
    return getAreaOfTriangle() / getSemiPerimeterOfTriangle();
}
double Triangle::getCircumRadiusOfTraingle()
{
    return (this->mSideA * this->mSideB * this->mSideC) / (4 * getAreaOfTriangle());
}
void Triangle::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    ofstream scriptFile("Triangle.gp");
    if (!scriptFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    scriptFile << "set xrange [0:16]" << endl;
    scriptFile << "set xrange [0:16]" << endl;

    scriptFile << "sideA = " << nodePtr->sideA << endl;
    scriptFile << "sideB = " << nodePtr->sideB << endl;
    scriptFile << "sideC = " << nodePtr->sideC << endl;

    scriptFile << "x1 = 2" << endl;
    scriptFile << "y1 = 2 " << endl;
    scriptFile << "x2 = x1 + " << nodePtr->sideA << endl;
    scriptFile << "y2 = y1" << endl;

    scriptFile << "x3 = ("
               << "x1^2 + " << nodePtr->sideB << "^2 - " << nodePtr->sideC << "^2) / (2 * " << nodePtr->sideA << ")" << endl;
    scriptFile << "y3 = "
               << "y1 + sqrt(" << nodePtr->sideB << "^2 - ("
               << "x3 - x1)^2)" << endl;

    scriptFile << "set object 1 polygon from x1, y1 to x2, y2 to x3, y3 to x1, y1 fc rgb 'orange'" << endl;
    scriptFile << "plot x" << endl;

    if (system("Triangle.gp") == -1)
    {
        cerr << "Error executing Gnuplot." << endl;
        return;
    }
}
