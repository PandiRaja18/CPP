#include<iostream>
using namespace std;
struct Employee
{
	int Id;
	char name[10];
	string dept;
	
	void setData(int tId,string tname,string tDept)
	{
		Id = tId;
		name = tname;
		dept = tDept;  
	}
};
int main()
{
	Employee emp ;
	//emp.setData(1001,"Raja","ML");
	cout << "ID :" << emp.Id << "\t";
	cout << "Name :" << emp.name << "\t";
	cout << "department :" << emp.dept << "\n";

	emp.Id = 1002;
	emp.name = "Over";
	emp.dept = "PMP";
	cout << "ID :" << emp.Id << "\t";
	cout << "Name :" << emp.name << "\t";
	cout << "department :" << emp.dept << "\n";
	
	return 0;
	
	
}