/** Final specifier
  -> When used at class level : Prevents a class from being derived. ( Class A final{};)
  -> When used at method level : Prevents virtual method from being overriden
                                 in derived classes. [ return_type func() final;]
*/
#include <iostream>
using namespace std;
class Base {
public:
	virtual void methodA()  { // If final is added here, It will result in compilation error while deriving another class from it.
		cout << "Method A called from Base Class" << endl;
	}
	virtual ~Base() {
		cout << "Destructor of Base is called " << endl;
	};
};

class Derived1 : public Base {
public:
	void methodA()  { // MethodA cannot be override further.
		cout << "MethodA called from Derived Class" << endl;
	}
	~Derived1() {
		cout << "Destructor of Derived is called" << endl;
	}
};
class Derived2: public Derived1 {
public:
	void methodA()  override {
		cout << "MethodA called from Derived2 class" << endl;
	}
};
void displayMethod(Base& obj) {
	obj.methodA();
}
int main() {
	cout << endl;
	Base* b_new = new Derived1();
	b_new->methodA();
	delete b_new;
	cout << endl;
}

/**

MethodA called from Derived Class
Destructor of Derived is called
Destructor of Base is called

*/