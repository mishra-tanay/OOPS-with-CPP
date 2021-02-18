// When we have atleast one virtual function, it is good to have virtual destructor.
#include <iostream>
using namespace std;
class Base {
public:
	virtual void methodA() {
		cout << "Method A called from Base Class" << endl;
	}
	virtual ~Base() {
		cout << "Destructor of Base is called " << endl;
	};
};

class Derived: public Base {
public:
	void methodA() {
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
	Base* b_new = new Derived(); // Since b_new is an pointer of Base type so
	// but unlike last example.it will dynamically bind appropriate class version of methodA at
	// run time.

	b_new->methodA();
	delete b_new;
	cout << endl;
}

/**
-----Without virual destructor -->
Method A called from Derived Class
Destructor of Base is called

-----With virtual destructor ----
Method A called from Derived Class
Destructor of Derived is called
Destructor of Base is called
*/