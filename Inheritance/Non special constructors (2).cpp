#include <iostream>
using namespace std;

class Base {
public:
	Base() : base{0} {
		cout << "Base constructor called " << endl;
	}
	Base(int x): base{x} {
		cout << "Base (int) arg constructor called" << endl;
	}
	~Base() {
		cout << "Base destructor called" << endl;
	}
private:
	int base;
};

class Derived : public Base {
	using Base::Base;
public:
	Derived() {
		cout << "Derived constructor called" << endl;
	}
	Derived(int x): derived{x} {
		cout << "Derived (int) arg constructor called" << endl;
	}
	~Derived() {
		cout << "Derived destructor called " << endl;
	}
private:
	int derived;
};

int main() {
	Derived d{100};
}

/** Output
Base constructor called
Derived (int) arg constructor called
Derived destructor called
Base destructor called
*/