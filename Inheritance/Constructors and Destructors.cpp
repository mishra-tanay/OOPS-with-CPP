#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base constructor called " << endl;
	}
	~Base() {
		cout << "Base destructor called" << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << "Derived constructor called" << endl;
	}
	~Derived() {
		cout << "Derived destructor called " << endl;
	}
};

int main() {
	Derived d;
}

/** Output

Base constructor called
Derived constructor called
Derived destructor called
Base destructor called

*/