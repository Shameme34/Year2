#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Assn2.h"
#include "ShapeTwoD.h"
using namespace std;

class Rectangle:public ShapeTwoD
{
    private:
        struct Coords 
        {
            int x;
            int y;
        };
        Coords *node;
    public:
        Rectangle();
        Rectangle(string name, bool containsWarpSpace, struct Coords * node);

        void addCoords() override;
        double computeArea() override;
        bool isPointInShape(int x, int y) override;
        bool isPointOnShape(int x, int y) override;
        string toString() override;
        ~Rectangle()
        {
            delete []node;
        }
};

#endif