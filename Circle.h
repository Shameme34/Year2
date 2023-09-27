#ifndef CIRCLE_H
#define CIRCLE_H

#include "Assn2.h"
#include "ShapeTwoD.h"
using namespace std;

class Circle:public ShapeTwoD
{
    private:
        struct Coords 
        {
            int x;
            int y;
        };
        Coords *node;
        int radius;
    public:
        Circle();
        Circle(string name, bool containsWarpSpace, struct Coords * node, int radius);

        int getRadius(int radius);
        void setRadius(int radius);
        void addCoords() override;
        double computeArea() override;
        bool isPointInShape(int x, int y) override;
        bool isPointOnShape(int x, int y) override;
        string toString() override;
        ~Circle()
        {
            delete []node;
        }
};

#endif