#include<iostream>
using namespace std;
int main()
{
	int a;
	int b;
	int *c = &b;
	a=5;
	b=10;
	cout << "a: "<<a<< "\tb: "<<b<< "\tc: "<<*c;
	cout<<"\nAfter changing b\n";
	b=15;
	cout<< "b: "<<b << "\tc: "<<*c;
	int *heapval = new int;
	*heapval = 4;
	cout <<"\nheap address: "<<heapval<<"\theapval: " <<*heapval;
	delete heapval;
	cout <<"\nAfter deleting-> heap address: "<<heapval<<"\theapval: " <<*heapval;
	heapval = nullptr;
	cout <<"\nAfter setting null-> heap address: "<<heapval<<"\theapval: " <<*heapval;
	return 0;
}