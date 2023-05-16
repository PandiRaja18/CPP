#include "BubbleClass.h"
#include<iostream>
using namespace std;
template <typename T>
void BubbleClass<T>::sortArr(T tarr[], int length)
{
	for(int i=0;i<length;i+=1)
	{
		for(int j=0;j<length-i-1;j+=1)
		{
			if(tarr[j]>tarr[j+1]){
				T temp = tarr[j];
				tarr[j] = tarr[j+1];
				tarr[j+1] = temp;
			}
		}
	}
	print(tarr,length);
}
template <typename T>
void BubbleClass<T>::printArr(T tarr[], int size)
{
	std::cout << "After sorting -->"<<std::endl;
	for (int i = 0; i < size; i++)
		std::cout << " " << tarr[i];
	std::cout << endl;
}
template <typename T>
void BubbleClass<T>::printData(T x)
{
	cout <<"Welcome "<< x;
}