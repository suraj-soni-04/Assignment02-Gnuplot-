#include <iostream>
#include <..\headers\Circle.h>
#include <..\headers\Ellipse.h>
#include <..\headers\Square.h>
#include <..\headers\Line.h>
#include <..\headers\Triangle.h>
#include <..\headers\Rectangle.h>
using namespace std;
int main()
{
    int ch;
    cout << "**** WELCOME  ****" << endl;
    while (1)
    {
        cout << " -->LIST OF SHAPES<-- " << endl;
        cout << "1. Circle " << endl;
        cout << "2. Ellipse " << endl;
        cout << "3. Line " << endl;
        cout << "4. Rectangle " << endl;
        cout << "5. Square " << endl;
        cout << "6. Triangle " << endl;
        cout << "7. EXIT" << endl;
        cout << "Enter your choice (to perform geometic operations)! : ";
        cin >> ch;
        if (ch == 1)
        {
            double radius;
            cout << "Enter the radius of the Circle : ";
            cin >> radius;
            if (radius < 0)
                radius = radius * (-1);
            Circle circle(radius);
            cout << "AREA of the Circle with radius " << radius << " is " << circle.getAreaOfCircle() << endl;
            cout << "CIRCUMFERENCE of the Circle with radius " << radius << " is " << circle.getCircumferenceOfCircle() << endl;

            typedef struct Node
            {
                int radius;
            } Node;
            Node node;
            node.radius = radius;
            circle.plot(&node);

            cout << "\n";
        }
        else if (ch == 2)
        {
            double majorAxis, minorAxis;
            cout << "Enter the Major Axis of the Ellipse : ";
            cin >> majorAxis;
            cout << "Enter the Minor Axis of the Ellipse : ";
            cin >> minorAxis;
            Ellipse ellipse(majorAxis, minorAxis);
            auto p = ellipse.getCenterOfEllipse();
            cout << "Center of the Ellipse : "
                 << "(" << p.first << "," << p.second << ")" << endl;
            cout << "Eccentricity of Ellipse is : " << ellipse.getEccentricityOfEllipse() << endl;
            cout << "Focal Length of Ellipse is : " << ellipse.getFocalLengthOfEllipse() << endl;
            cout << "Area of Ellipse is : " << ellipse.getAreaOfEllipse() << " sq. mtr" << endl;

            typedef struct Node
            {
                int majorAxis;
                int minorAxis;
            } Node;
            Node node;
            node.majorAxis = majorAxis;
            node.minorAxis = minorAxis;
            ellipse.plot(&node);

            cout << "\n";
        }
        else if (ch == 3)
        {
            double x1, x2, y1, y2;
            cout << "Enter x1 co-ordinate : ";
            cin >> x1;
            cout << "Enter y1 co-ordinate : ";
            cin >> y1;
            cout << "Enter x2 co-ordinate : ";
            cin >> x2;
            cout << "Enter y2 co-ordinate : ";
            cin >> y2;
            Line line(x1, y1, x2, y2);
            cout << "Length of the Line is " << line.getLengthOfLine() << endl;
            cout << "Slope of the Line is " << line.getSlopeOfLine() << endl;

            typedef struct Node
            {
                int x1, y1;
                int x2, y2;
            } Node;
            Node node;
            node.x1 = x1;
            node.y1 = y1;
            node.x2 = x2;
            node.y2 = y2;

            line.plot(&node);

            cout << "\n";
        }
        else if (ch == 4)
        {
            double length, breadth;
            cout << "Enter the Length of Rectangle : ";
            cin >> length;
            cout << "Enter the Breadth of Rectangle : ";
            cin >> breadth;
            Rectangle rectangle(length, breadth);
            cout << "Area of Rectangle is : " << rectangle.getAreaOfRectangle() << endl;
            cout << "Perimeter of Rectangle is : " << rectangle.getPerimeterOfRectangle() << endl;
            cout << "Diagonal of Rectangle is : " << rectangle.getDiagonalOfRectangle() << endl;

            typedef struct Node
            {
                int length;
                int breadth;
            } Node;

            Node node;
            node.length = length;
            node.breadth = breadth;
            rectangle.plot(&node);

            cout << "\n";
        }
        else if (ch == 5)
        {
            double side;
            cout << "Enter the Side of Square : ";
            cin >> side;
            Square square(side);
            cout << "Area of Square is : " << square.getAreaOfSquare() << endl;
            cout << "Perimeter of Square is : " << square.getPerimeterOfSquare() << endl;
            cout << "Diagonal of Square is : " << square.getDiagonalOfSquare() << endl;
            
            typedef struct Node
            {
                int side;
            } Node;

            Node node;
            node.side = side;
            square.plot(&node);
            
            cout << "\n";
        }
        else if (ch == 6)
        {
            double sideA, sideB, sideC;
            cout << "Enter side-1 of Triangle : ";
            cin >> sideA;
            cout << "Enter side-2 of Triangle : ";
            cin >> sideB;
            cout << "Enter side-3 of Triangle : ";
            cin >> sideC;
            Triangle triangle(sideA, sideB, sideC);
            cout << "Area of Triangle is : " << triangle.getAreaOfTriangle() << endl;
            cout << "Perimeter of Triangle is : " << triangle.getPerimeterOfTriangle() << endl;
            cout << "SemiPerimeter of Triangle is : " << triangle.getSemiPerimeterOfTriangle() << endl;
            cout << "InRadius of Triangle is : " << triangle.getInRadiusOfTraingle() << endl;
            cout << "Circumradius of Triangle is : " << triangle.getCircumRadiusOfTraingle() << endl;

            typedef struct Node
            {
                int sideA;
                int sideB;
                int sideC;
            } Node;

            Node node;
            node.sideA = sideA;
            node.sideB = sideB;
            node.sideC = sideC;
            
            triangle.plot(&node);

            cout << "\n";
        }
        else if (ch == 7)
            break;
        else
        {
            cout << "--xx-- INVALID CHOICE --xx--" << endl
                 << endl;
        }
    }
    return 0;
}