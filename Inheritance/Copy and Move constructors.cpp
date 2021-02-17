#include <iostream>
using namespace std;

class Base {
public:
	Base() : base{0} {
		cout << "Base no-args constructor called " << endl;
	}
	Base(int x): base{x} {
		cout << "Base (int) arg constructor called" << endl;
	}
	Base(const Base& b_obj): base{b_obj.base} {
		cout << "Base copy constructor called" << endl;
	}
	Base &operator=(const Base&b_rhs) {
		cout << "Base class =operator " << endl;
		if (this ==   &b_rhs) {
			return *this;
		}
		base = b_rhs.base;
		return *this;
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
	Derived(int x): Base{x}, derived{x} {
		cout << "Derived (int) arg constructor called" << endl;
	}
	Derived(const Derived& d_obj): Base(d_obj), derived{d_obj.derived} {
		cout << "Derived copy constructor called" << endl;
	}
	Derived &operator=(const Derived& d_obj) {
		cout << "Derived copy assignment operator called" << endl;
		if (this == &d_obj) {
			return *this;
		}
		Base::operator=(d_obj);
		derived = d_obj.derived;
		return *this;
	}
	~Derived() {
		cout << "Derived destructor called " << endl;
	}
private:
	int derived;
};

int main() {
	Derived d{100};
	cout << '\n';
	Derived d2(d);
	cout << '\n';
	Derived d3;
	d3 = d2;
	cout << '\n';
}

/** Output
Base (int) arg constructor called
Derived (int) arg constructor called

Base copy constructor called
Derived copy constructor called

Base no-args constructor called
Derived constructor called
Derived copy assignment operator called
Base class =operator

Derived destructor called
Base destructor called
Derived destructor called
Base destructor called
Derived destructor called
Base destructor called
*/