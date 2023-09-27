#ifndef SQUARE_H
#define SQUARE_H

#include "Assn2.h"
#include "ShapeTwoD.h"
using namespace std;

class Square:public ShapeTwoD
{
    private:
        struct Coords 
        {
            int x;
            int y;
        };
        Coords *node;
    public:
        Square();
        Square (string name, bool containsWarpSpace, struct Coords * node);

        void addCoords() override;
        double computeArea() override;
        bool isPointInShape(int x, int y) override;
        bool isPointOnShape(int x, int y) override;
        string toString() override;
        ~Square()
        {
            delete []node;
        }
};

#endif