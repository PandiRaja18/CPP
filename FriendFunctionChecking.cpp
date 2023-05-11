#include <iostream>
using namespace std;

class base; // forward definition needed since another class in which function is declared with base class object
class anotherClass {
private :
  	int checking_private=11;
public:
	void memberFunction(base& obj);
};

class base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	// friend function declaration
  	void memberFunction2(anotherClass& obj);
	friend void anotherClass::memberFunction(base&);
};

// friend function definition
void anotherClass::memberFunction(base& obj)
{
    cout << "Private Variable: " << obj.private_variable<< endl;
	cout << "Protected Variable: " << obj.protected_variable;
}
void base::memberFunction2(anotherClass& obj)
{
	count<<"Another class private variable"<<obj.checking_private;
}
int main()
{
	base object1;
	anotherClass object2;
	object2.memberFunction(object1);
	object1.memberFunction2(object2);
	return 0;
}
