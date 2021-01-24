#include <iostream>
using namespace std;
class Student {
public:
	Student(const string& name, int age) {
		cout << "Constructor with two arguements called" << endl;
		d_name = name;
		d_age = age;
	}
	Student(const string& name) {
		cout << "Constructor with one arguement called" << endl;
		d_name = name;
		d_age = 20;
	}
	void setName(const string& name);
	void printName();
	void setAge(int age) { // By default inline functions.
		d_age = age;
	}
	void printAge() { // By default inline function.
		cout << "Age is " << d_age << '\n';
	}
private:
	string d_name;
	int d_age;
};
void Student::setName(const string& name) {
	d_name = name;
}
void Student::printName() {
	cout << "Name of student is " << d_name << endl;
}

int main() {
	Student* s = new Student("Tanay Mishra", 22);
	s->printName();
	s->printAge();
	cout << endl;
	Student* s2 = new Student("Tanay Mishra");
	s2->printName();
	s2->printAge();
	return 0;
}

/* Output

Constructor with two arguements called
Name of student is Tanay Mishra
Age is 22

Constructor with one arguement called
Name of student is Tanay Mishra
Age is 20
*/