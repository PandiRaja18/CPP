class base;
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