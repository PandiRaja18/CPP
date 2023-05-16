#ifndef SHAPE_H
#define SHAPE_H
class shape
{
    private :
        int length,breadth;
    public:
        void setData(int x,int y);
        int getLength();
        int getBreadth();
        virtual int area() = 0;
};

#endif