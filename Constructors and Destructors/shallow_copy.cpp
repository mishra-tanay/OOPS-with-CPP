#include <iostream>
using namespace std;
class Shallow {
public:
	Shallow(int data) {
		d_data = new int;
		*d_data = data;
		cout << "Constructor called" << endl;
	}
	Shallow(const Shallow& shallow): d_data{shallow.d_data} {
		cout << "Copy Constructor called" << endl;
	}
	~Shallow() {
		cout << "Destructor called " << endl;
		delete d_data;
	}
	int getDataValue() const {
		return *d_data;
	}
private:
	int* d_data;
};

int main() {
	Shallow shallow_object(2);
	Shallow another_shallow_object(shallow_object); // This will lead to runtime error as after calling destructor of another_shallow_object,
	// the memory d_data is pointed to is freed, i.e not a valid memory. So when destructor of shallow_object is called
	// It will try to free a memory which is no longer valid.

}