/* Including all Files neccessary */
#include "Assn2.h"
#include "ShapeTwoD.h"
using namespace std;

/* Defining variables for empty constructor*/
ShapeTwoD::ShapeTwoD()
{
    name ="";
    containsWarpSpace = true;
}

ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
    name = name;
    containsWarpSpace = containsWarpSpace;
}

string ShapeTwoD::getName()
{
    return (name);
} 

bool ShapeTwoD::getContainsWarpSpace()
{
    return (containsWarpSpace);
}

void ShapeTwoD::setName (string name)
{
    ShapeTwoD::name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    ShapeTwoD::containsWarpSpace = containsWarpSpace;
}

string ShapeTwoD::toString()
{
    ostringstream oss;
    oss<<"name: "<<name<<endl;
    oss<<"contains: "<<containsWarpSpace<<endl;
    return(oss.str());
}

double ShapeTwoD::computeArea()
{
    return 0.0;
}

void ShapeTwoD::addCoords()
{

}

bool ShapeTwoD::isPointInShape(int x, int y)
{
    return true;
}

bool ShapeTwoD::isPointOnShape(int x, int y)
{
    return true;
}