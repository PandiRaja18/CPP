#include<iostream>
using namespace std;
//#include "header1.h"
//#include "header2.h"  
//#include nested depth 200 exceeds maximum of 200 (use -fmax-include-depth=DEPTH to increase the maximum)
// 1 | #include "header1.h"
#include "FriendFunction.h"
#include "arrayToPointer.h"
#include "swap.h"
#include "BubbleClass.h"
int main()
{
    base object1;
	anotherClass object2;
    cout <<"Accessing private and protected varibale using Friend Function" << endl;
	object2.memberFunction(object1);
    cout<<endl;
    
    int arr[5] = {10,12,3,11,56};
    cout <<"First address and value of element in array using pointer "<<startingAddress(arr) << "  "<<firstValue(arr) << endl;
    cout <<endl;
    
    int a=40;
    int b=20;
    cout <<"Pass by value "<<endl<<"*******************"<<endl <<"Before swapping : a= "<<a<<" = "<<b <<endl;
    passByValue(a,b);
    cout <<"After swapping : a= "<<a<<" b= "<<b<<endl;
    cout <<"Pass by Refrence "<<endl<<"*******************"<<endl <<"Before swapping : a= "<<a<<" b= "<<b <<endl;
    passByReference(&a,&b);
    cout <<"After swapping : a= "<<a<<" b= "<<b<<endl;
    cout<<endl;
    
    cout << "Sorting character Array "<<endl<<"************************"<<endl;
    char charArr[5] = { 'b', 'a', 'z', 's', 'c' };
    int index;
    cout<<"Before Sorting :";
    for(index=0;index<5;index+=1)
    {
        cout<<charArr[index] <<" ";
    }
    cout <<endl;
	BubbleClass<int> bs;
	bs.sortArr(arr,5);
    //int num = 5;
    //bs.printData(&num);
    return 0;
}