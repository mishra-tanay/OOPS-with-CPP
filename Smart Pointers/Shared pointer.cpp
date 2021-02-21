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
	shared_ptr<Base> ptr = make_shared <Base>(1);
	cout << "Value is " << ptr->getValue() << '\n';
	shared_ptr<Base> ptr1 = ptr;

	std::shared_ptr<Base> ptr2(ptr);
	if (ptr == nullptr) {
		cout << "ptr moved to ptr2 and not it is pointing to nothing" << endl;
	}
	cout << "Address of ptr  " << ptr.get() << '\n';
	cout << "Address of ptr1 " << ptr1.get() << '\n';
	cout << "Address of ptr2 " << ptr2.get() << '\n';
	cout << " \n---------------------------------------\n";
	cout << "Use count of ptr " << ptr.use_count() << '\n';
	cout << "Use count of ptr1 " << ptr1.use_count() << '\n';
	cout << "Use count of ptr2 " << ptr2.use_count() << '\n';
	cout << " \n---------------------------------------\n";
	ptr.reset();

	cout << "Use count of ptr " << ptr.use_count() << '\n';
	cout << "Use count of ptr1 " << ptr1.use_count() << '\n';
	cout << "Use count of ptr2 " << ptr2.use_count() << '\n';
	cout << '\n';
}

/** Output

Constructor called
Value is 1
Address of ptr  0xe31780
Address of ptr1 0xe31780
Address of ptr2 0xe31780

---------------------------------------
Use count of ptr 3
Use count of ptr1 3
Use count of ptr2 3

---------------------------------------
Use count of ptr 0
Use count of ptr1 2
Use count of ptr2 2

Destructor called

*/