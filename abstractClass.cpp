#include<iostream>
using namespace std;

class Abstract
{
int x;
public:
	virtual void fun() = 0; //An abstract class must contain atleast one virtual function
	int getX() 
	{ 
		return x;
	}
};

class Derived: public Abstract
{
	int y;
	public:   //Derived class of an abstract must over ride atleast one of the virtual member function if not then it also be consider as abstract.
		void fun() { 
		cout << "fun() method overide here"; 
	} 
};

int main(void)
{
	Abstract *d = new Derived();
	d->fun();
	return 0;
}
