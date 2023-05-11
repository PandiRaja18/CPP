#include<iostream>
using namespace std;
class Singleton
{
	public :
		Singleton()
		{
			cout<<"\nWelcome to Singleton Class";
		}
	private:
		int empId;
		char name[30];
	
	public :
		int getEmpId()
		{
			return this->empId;
		}
		string getName()
		{
			return this->name;
		}
		void setEmpId(int id)
		{
			this->empId = id;
		}
		void setName(char name[30])
		{
			this->name = name;
		}
}instance;
int main()
{
	instance.setEmpId(101);
	instance.setName("Temp1");
	cout<<"\nEmployee id : "<<instance.getEmpId() <<"\t Employee Name : "<<instance.getName();
	Singleton instance2;
	instance2.setEmpId(102);
	instance2.setName("Temp2");	
	cout<<"\nEmployee id : "<<instance2.getEmpId() <<"\t Employee Name : "<<instance2.getName();
	
	return 0;
}