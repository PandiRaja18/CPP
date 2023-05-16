#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include <iostream>
using namespace std;
class Rectangle : public shape{
    public:
        //Rectangle();
        //~Rectangle();
        int area() override;
};
#endif