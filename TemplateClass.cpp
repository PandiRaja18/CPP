#include <iostream>
using namespace std;

template <typename T> class BubbleSort {
private:
	int size;

public:
	void sort(T tarr[],int length);
	void print(T *ptr,int size);	
};
template <typename T> void BubbleSort<T>::sort(T tarr[],int length)
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
template <typename T> void BubbleSort<T>::print(T *ptr,int size)
{
	cout << "After sorting -->"<<endl;
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

int main()
{
	int arr[5] = { 11, 2, 23, 41, 5 };
	BubbleSort<int> bs;
	bs.sort(arr,5);
	return 0;
}
