#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <../headers/Rectangle.h>
using namespace std;
typedef struct Node
{
    int length;
    int breadth;
} Node;
Rectangle::Rectangle()
{
    this->mLength= 0;
    this->mBreadth = 0;
}
Rectangle::Rectangle(double length, double breadth)
{
    this->mLength = length;
    this->mBreadth = breadth;
}
Rectangle::Rectangle(const Rectangle &other)
{
    this->mLength = other.mLength;
    this->mBreadth = other.mBreadth;
}
Rectangle::Rectangle(Rectangle &&other)
{
    this->mLength = other.mLength;
    this->mBreadth = other.mBreadth;
    other.mLength = double(NULL);
    other.mBreadth = double(NULL);
}
Rectangle &Rectangle::operator=(Rectangle &other)
{
    this->mLength = other.mLength;
    this->mBreadth = other.mBreadth;
    return *this;
}
Rectangle::~Rectangle()
{
    // cout<<"***Rectangle Memory got released***"<<endl;
}
double Rectangle::getAreaOfRectangle()
{
    return (this->mLength) * (this->mBreadth);
}
double Rectangle::getPerimeterOfRectangle()
{
    return 2 * (this->mLength + this->mBreadth);
}
double Rectangle::getDiagonalOfRectangle()
{
    return sqrt(pow(mLength, 2) + pow(mBreadth, 2));
}
void Rectangle::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    ofstream scriptFile("Rectangle.gp");
    if (!scriptFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    scriptFile << "set xrange [0:16]" << endl;
    scriptFile << "set xrange [0:16]" << endl;

    scriptFile << "L = " << nodePtr->length << endl;
    scriptFile << "B = " << nodePtr->breadth << endl;

    scriptFile << "x1 = 0" << endl;
    scriptFile << "y1 = 0 " << endl;

    scriptFile << "x2 = " << "0 + " <<nodePtr->length <<endl;
    scriptFile << "y2 = " << "0 + " <<nodePtr->breadth <<endl;
    
    scriptFile << "set object 1 rectangle from x1, y1 to x2, y2 fc rgb 2" << endl;
    scriptFile<< "plot x"<<endl;
    scriptFile.close();

    if (system("Rectangle.gp") == -1)
    {
        cerr << "Error executing Gnuplot." << endl;
        return;
    }
}
