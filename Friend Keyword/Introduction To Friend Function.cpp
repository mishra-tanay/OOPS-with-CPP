#include <iostream>
using namespace std;
class Student {
public:
	Student(const string& name, int age = 10): d_name{name}, d_age{age} {
		if (!d_name.empty()) {
			cout << "Name is not empty before constructor is called" << endl;
		}
		cout << "Constructor with two arguements called" << endl;
	}
	~Student() {
		cout << "Destructor for student " << d_name << " called " << endl;
	}
	friend void displayStudent(Student &s);
private:
	string d_name;
	int d_age;
};
void displayStudent(Student &s) {
	cout << "Student name " << s.d_name << '\n';
	cout << "Student Age " << s.d_age << '\n';
}
int main() {

	Student s4("Tom");
	displayStudent(s4);
	return 0;
}
