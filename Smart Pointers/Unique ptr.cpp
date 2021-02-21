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

int main() {
	std::unique_ptr<Base> ptr = make_unique <Base>(1);
	cout << "Value is " << ptr->getValue() << '\n';
	cout << "Address of ptr " << ptr.get() << '\n';
	// std::unique_ptr<Base> ptr2 = ptr; (Compilation error as you can`t have two pointers pointing to same location on the heap.
	// std::unique_ptr<Base> ptr2(ptr); Compilation error.

	std::unique_ptr<Base> ptr2 = move(ptr);
	if (ptr == nullptr) {
		cout << "ptr moved to ptr2 and not it is pointing to nothing" << endl;
	}
	cout << "Address of ptr2 " << ptr2.get() << '\n';

}

/** Output

Constructor called
Value is 1
Address of ptr 0x1061770
ptr moved to ptr2 and not it is pointing to nothing
Address of ptr2 0x1061770
Destructor called

*/