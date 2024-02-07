#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <..\headers\Square.h>
using namespace std;
typedef struct Node
{
    int side;
} Node;
Square::Square()
{
    this->mSide = 0;
}
Square::Square(double side)
{
    this->mSide = side;
}
Square::Square(const Square &other)
{
    this->mSide = other.mSide;
}
Square::Square(Square &&other)
{
    this->mSide = other.mSide;
    other.mSide = double(NULL);
}
Square &Square::operator=(Square &other)
{
    this->mSide = other.mSide;
    return *this;
}
Square::~Square()
{
    // cout<<"***Square Memory got released***"<<endl;
}
double Square::getAreaOfSquare()
{
    return this->mSide * this->mSide;
}
double Square::getPerimeterOfSquare()
{
    return 4 * this->mSide;
}
double Square::getDiagonalOfSquare()
{
    return this->mSide * sqrt(2);
}
void Square::plot(void *ptr)
{
    Node *nodePtr = static_cast<Node *>(ptr);
    ofstream scriptFile("Square.gp");
    if (!scriptFile.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    scriptFile << "set xrange [0:16]" << endl;
    scriptFile << "set xrange [0:16]" << endl;

    scriptFile << "L = " << nodePtr->side << endl;

    scriptFile << "x1 = 0" << endl;
    scriptFile << "y1 = 0 " << endl;

    scriptFile << "x2 = "
               << "0 + " << nodePtr->side << endl;
    scriptFile << "y2 = "
               << "0 + " << nodePtr->side << endl;

    scriptFile << "set object 1 rectangle from x1, y1 to x2, y2 fc rgb 'green'" << endl;
    scriptFile << "plot x" << endl;
    scriptFile.close();

    if (system("Square.gp") == -1)
    {
        cerr << "Error executing Gnuplot." << endl;
        return;
    }
}
