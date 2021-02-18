#include <iostream>
using namespace std;
class Base {
public:
	void methodA() {
		cout << "Method A called from Base Class" << endl;
	}
};

class Derived: public Base {
public:
	void methodA() {
		cout << "Method A called from Derived Class" << endl;
	}
};
void displayMethod( Base& obj) {
	obj.methodA();
}
int main() {
	Base b;
	b.methodA();
	cout << endl;
	Derived d;
	d.methodA();
	cout << endl;
	Base* b_new = new Derived(); // Since b_new is an pointer of Base type so
	// it will bind base class version of methodA at
	// compile time.

	b_new->methodA();
	cout << endl;
	displayMethod(b);
	cout << endl;
	displayMethod(d);
}

/** Output

Method A called from Base Class

Method A called from Derived Class

Method A called from Base Class

Method A called from Base Class

Method A called from Base Class
**/