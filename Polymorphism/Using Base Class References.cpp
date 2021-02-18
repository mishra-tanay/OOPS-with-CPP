// Adding override ensures that you are overriding the base class function,
// So that compiler generates warning when you instead of overriding it,
// redefine it.

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
};

class Derived: public Base {
public:
	void methodA() const override {
		cout << "Method A called from Derived Class" << endl;
	}
	~Derived() {
		cout << "Destructor of Derived is called" << endl;
	}
};
void displayMethod(Base& obj) {
	obj.methodA();
}
int main() {
	Base a;
	Base &ref = a;
	ref.methodA();
	cout << endl;
	Derived t;
	Base &ref1 = t;
	ref1.methodA();
	cout << endl;

	displayMethod(a);

	cout << endl;

	displayMethod(t);
}

/**
Method A called from Base Class

Method A called from Derived Class

Method A called from Base Class

Method A called from Derived Class
Destructor of Derived is called
Destructor of Base is called
Destructor of Base is called
*/