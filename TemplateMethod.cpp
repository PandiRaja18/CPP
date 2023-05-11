#include <iostream>
using namespace std;
template <typename T> T maxNumber(T x, T y)
{
	return (x > y) ? x : y;
}
int main()
{

	// Maximum int
	cout << "Maximum Integer is "<<maxNumber<int>(13, 7) << endl;
	// Maximum double
	cout << "Maximum Double is "<< maxNumber<double>(3.56, 3.57) << endl;
	// Maximum char
	cout <<"Maximum Char is "<< maxNumber<char>('g', 'e') << endl;

	return 0;
}
