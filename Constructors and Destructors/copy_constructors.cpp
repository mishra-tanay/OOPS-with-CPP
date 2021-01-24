#include <iostream>
using namespace std;
class Student {
public:
	Student(const string& name = "None", int age = 0): d_name{name}, d_age{age} {
		if (!d_name.empty()) {
			cout << "Name is not empty before constructor is called" << endl;
		}
		cout << "Constructor with two arguements called" << endl;
	}
	/* One way of doing it.
	Student(const Student& student): d_name{student.getName()}, d_age{student.getAge()} {
		cout << "Copy Constructor called" << endl;
	}
	*/
	/* Another way of doing it.*/
	Student(const Student& student): Student{student.getName(), student.getAge()} {
		cout << "Copy constructor called " << endl;
	}
	void setName(const string& name);
	void printName();
	void setAge(int age) { // By default inline functions.
		d_age = age;
	}
	void printAge() {
		cout << "Age of student is " << d_age << '\n';
	}
	int getAge() const { // By default inline function.
		return d_age;
	}
	string getName() const {
		return d_name;
	}
	~Student() {
		cout << "Destructor for student " << d_name << " called " << endl;
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
	Student s = Student("Tanay Mishra", 22);
	s.printName();
	s.printAge();
	Student* s2 = new Student(s);
	s2->printName();
	s2->printAge();
	cout << endl;
	return 0;
}

/* Output

Name is not empty before constructor is called
Constructor with two arguements called
Name of student is Tanay Mishra
Age of student is 22
Name is not empty before constructor is called
Constructor with two arguements called
Copy constructor called
Name of student is Tanay Mishra
Age of student is 22

Destructor for student Tanay Mishra called
*/