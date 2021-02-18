/**
Abstract class:
> Cannot instantiate objects.
> Often used as base classes in inheritance.
> Referred to Abstract Base class.
> Must contain atleast 1 pure virtual function.


Concrete class.
> Used to instantiate objects.
> All their member functions are defined.
*/

#include <iostream>
using namespace std;
class Base {
public:
	virtual void methodA() const {
		cout << "Method A called from Base Class" << endl;
	}
	virtual ~Base() {
		cout << "Destructor of Base is called " << endl;
	};
	virtual void pure_virtual_function() = 0;
};

class Derived: public Base {
public:
	void methodA() const override {
		cout << "Method A called from Derived Class" << endl;
	}
	void pure_virtual_function() {
		cout << "pure_virtual_function is defined here otherwise it will also become abstract class." << endl;
	}
	~Derived() {
		cout << "Destructor of Derived is called" << endl;
	}
};
void displayMethod(Base& obj) {
	obj.methodA();
}
int main() {
	// Base a; Since Base is now an abstract class, it can`t be instantiated.
	Derived t;
	t.methodA();
}

/** Output

Method A called from Derived Class
Destructor of Derived is called
Destructor of Base is called

*/