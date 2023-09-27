#ifndef MYTEMPLATES
#define MYTEMPLATES

#include "shameem.h"
using namespace std;

template <typename T>
double scalar_difference (T param1, T param2)
{
    double value = param1 - param2;
    if(value < 0)
    {
        value = value*(-1);
    }

    return value;
}

template <typename T>
bool equals (T param1, T param2)
{
    if(param1 == param2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif