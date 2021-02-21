#include <iostream>
#include <memory> // required to use smart pointer.
using namespace std;
class Base {
public:
	Base(int value = 0): d_value{value} {
		cout << "Constructor called" << endl;
	}
	int getValue() {
		return d_value;
	}
	void setValue(int value) {
		d_value = value;
	}
	~Base() {
		cout << "Destructor called " << endl;
	}
private:
	int d_value;

};
void custom_deleter(Base* ptr) {
	if (ptr != nullptr) {
		cout << "Ptr still pointing to a valid location " << endl;
	}
	delete ptr;
	cout << "Custom deleter called" << endl;
}
int main() {
	shared_ptr<Base> ptr {new Base{}, custom_deleter};
	cout << "Value is " << ptr->getValue() << '\n';
	cout << "Address of ptr " << ptr.get() << '\n';

}

/** Output

Constructor called
Value is 0
Address of ptr 0xe91770
Ptr still pointing to a valid location
Destructor called
Custom deleter called

*/