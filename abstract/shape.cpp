#include "shape.h"
void shape::setData(int x,int y)
{
    length=x;
    breadth=y;
} 
int shape::getLength()
{
    return length;
} 
int shape::getBreadth()
{
    return breadth;
}