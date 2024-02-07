#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <..\headers\Line.h>
using namespace std;
typedef struct Node
{
    int x1, y1;
    int x2, y2;
} Node;
Node node;
Line::Line()
{
    this->mX1 = 0.0;
    this->mY1 = 0.0;
    this->mX2 = 0.0;
    this->mY2 = 0.0;
}
Line::Line(double x1, double y1, double x2, double y2)
{
    this->mX1 = x1;
    this->mY1 = y1;
    this->mX2 = x2;
    this->mY2 = y2;
}
Line::Line(const Line &other)
{
    this->mX1 = other.mX1;
    this->mY1 = other.mY1;
    this->mX2 = other.mX2;
    this->mY2 = other.mY2;
}
Line::Line(Line &&other)
{
    this->mX1 = other.mX1;
    this->mY1 = other.mY1;
    this->mX2 = other.mX2;
    this->mY2 = other.mY2;
    other.mX1 = double(NULL);
    other.mX2 = double(NULL);
    other.mY1 = double(NULL);
    other.mY2 = double(NULL);
}
Line &Line::operator=(Line &other)
{
    this->mX1 = other.mX1;
    this->mY1 = other.mY1;
    this->mX2 = other.mX2;
    this->mY2 = other.mY2;
    return *this;
}
Line::~Line()
{
    // cout<<"***Memory for the Line released***"<<endl;
}
double Line::getLengthOfLine()
{
    return sqrt(pow(this->mX2 - this->mX1, 2) + pow(this->mY2 - this->mY1, 2));
}
double Line::getSlopeOfLine()
{
    if (this->mX2 - this->mX1 == 0)
    {
        cout << "--- The line is vertical, and the slope is undefined ---" << endl;
        return 0;
    }
    return (this->mY2 - this->mY1) / (this->mX2 - this->mX1);
}
void Line::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    ofstream scriptFile("Line.gp");
    if (!scriptFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    scriptFile << "x1 = " << nodePtr->x1 << endl;
    scriptFile << "y1 = " << nodePtr->y1 << endl;
    scriptFile << "x2 = " << nodePtr->x2 << endl;
    scriptFile << "y2 = " << nodePtr->y2 << endl;
    scriptFile << "plot [" << nodePtr->x1 << ":" << nodePtr->x2<<"]" << " [" << nodePtr->y1 << ":" << nodePtr->y2 << "]" <<"'-'"<<" with lines title 'Line'"<<endl;
    scriptFile<<nodePtr->x1<<" "<<nodePtr->y1<<endl;
    scriptFile<<nodePtr->x2<<" "<<nodePtr->y2<<endl;
    scriptFile.close();

    if (system("Line.gp") == -1)
    {
        cerr << "Error executing Gnuplot." << endl;
        return;
    }
}
