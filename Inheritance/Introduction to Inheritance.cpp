#include <iostream>
using namespace std;
class Base {
public:
	int a;
protected:
	int b;
private:
	int c;
};

class PublicDerived: public Base {
public:
	void setBaseVariables() {
		a = 100; // public member
		b = 200; // protected member
		c = 300; // Is not accessible
	}
};
class ProtectedDerived : protected Base {
public:
	void setBaseVariables() {
		a = 100; // protected member
		b = 200; // protected member
		c = 300; // is not accessible
	}
};

class PrivateDerived : private Base {
public:
	void setBaseVariables() {
		a = 100; //private member
		b = 200; // private member
		c = 100; // not accessible
	}
}
int main() {
	PublicDerived d;
	d.setBaseVariables();
	ProtectedDerived d2;
	d2.setBaseVariables();
	PrivateDerived d3;
	d3.setBaseVariables();
}