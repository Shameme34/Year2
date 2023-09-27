#ifndef POINT2D
#define POINT2D

#include "shameem.h"

using namespace std;

class Point2D
{
    /* Overloading of insertion operator to give the desired output */
    friend ostream& operator<<(ostream& os, Point2D &p2d);
    friend double operator- (Point2D &p2d4,Point2D &p2d);
    friend bool operator== (Point2D &p2d4,Point2D &p2d);
    protected:
        int x;
        int y;
        virtual void setDistFrOrigin();
        double distFrOrigin;

    public:
        Point2D();
        Point2D(int x, int y);
        int getX();
        int getY();
        double getScalarValue();

        void setX(int x);
        void setY(int y);
        virtual string toString();
        ~Point2D(){};
};
#endif