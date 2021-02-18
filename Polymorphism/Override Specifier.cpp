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
	cout << endl;
	Base* b_new = new Derived();
	b_new->methodA();
	delete b_new;
	cout << endl;
}

/**
Method A called from Derived Class
Destructor of Derived is called
Destructor of Base is called

*/