#include <iostream>
#include <memory>
using namespace std;
class B;

class A {
public:
	void set_B(shared_ptr<B>& obj) {
		d_obj = obj;
	}
	A() {
		cout << "A Constructor called " << endl;
	}
	~A() {
		cout << "A destructor called" << endl;
	}
private:
	shared_ptr<B> d_obj;
};

class B {
public:
	void set_A(shared_ptr<A>& obj) {
		d_obj = obj;
	}
	B() {
		cout << "B Constructor called" << endl;
	}
	~B() {
		cout << "B destructor called" << endl;
	}
private:
	weak_ptr<A> d_obj;
};

int main() {
	shared_ptr<A> pt1 = make_shared<A>();
	shared_ptr<B> pt2 = make_shared<B>();

	pt1->set_B(pt2);
	pt2->set_A(pt1);
	cout << '\n';
}

/** Output

A Constructor called
B Constructor called

A destructor called
B destructor called
*/