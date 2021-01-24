#include <iostream>
using namespace std;
class Student {
public:
	void getName();
	void printName();
	void getAge() { // By default inline functions.
		cin >> d_age;
	}
	void printAge() { // By default inline function.
		cout << "Age is " << d_age;
	}
	Student(const string& name, int age) {
		cout << "Student object created";
		d_name = name;
		d_age = age;
	}
private:
	string d_name;
	int d_age;
};
void Student::getName() {
	cin >> d_name;
}
void Student::printName() {
	cout << "Name of student is " << d_name;
}

int main() {
	Student* s2 = new Student("Tanay", 22);
	s2->printName();
	s2->printAge();
	return 0;
}