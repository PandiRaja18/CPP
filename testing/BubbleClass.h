#ifndef BUBBLECLASS_H
#define BUBBLECLASS_H
template <typename T> class BubbleClass {
private:
	int size;

public:
	void sortArr(T tarr[],int length);
	void printArr(T tarr[],int size);	
	void printData(T x);
};
#endif