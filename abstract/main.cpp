#include<iostream>
//#include "shape.h"
#include "Rectangle.h"
using namespace std;
int main()
{
    //shape *r = new Rectangle();
    Rectangle r;
    int l,b;
    cout <<"Enter length and breadth"<<endl;
    cin>>l>>b;
    r.setData(l,b);
    cout <<"Area :"<<r.area();
}