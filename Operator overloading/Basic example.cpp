#include <iostream>
#include <cstring>
using namespace std;
class MyString {
public:
	MyString();

	MyString(const char* str);

	MyString(const MyString& source);

	~MyString() {
		cout << "Destructor called  for string " << str << '\n';
		delete [] str;
	}

	void display() const;

	int get_length() const;

	const char* get_string() const;

	MyString& operator=(const MyString& rhs);   // Copy assignment

	MyString& operator=(MyString &&rhs);     // Move assignment

private:
	char *str;
};

MyString::MyString() : str{nullptr} {
	cout << "No Param constructor called " << endl;
	str = new char[1];
	*str = '\0';
}

MyString::MyString(const char* s): MyString {} {
	cout << "Char* param constructor called " << endl;
	if (s != nullptr) {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}
MyString::MyString(const MyString& obj) : str{nullptr} {
	cout << "Copy constructor called " << endl;
	str = new char[strlen(obj.str) + 1];
	strcpy(str, obj.str);
}

void MyString::display() const {
	cout << "String is " << str << " and  has length " << get_length() << endl;
}

int MyString::get_length() const {
	return strlen(str);
}

const char* MyString::get_string() const {
	return str;
}

MyString &MyString::operator=(const MyString &rhs) {
	cout << "Copy assignment called" << endl;
	if (this == &rhs) {
		return *this;
	}
	delete []str;
	str = new char[rhs.get_length() + 1];
	strcpy(str, rhs.get_string());
	return *this;
}

MyString& MyString::operator=(MyString &&rhs) {
	cout << "Move assignment called " << endl;
	if (this == &rhs) {
		return *this;
	}

	delete []str;
	str = rhs.str;

	rhs.str = nullptr;

	return *this;
}

int main() {
	MyString a;
	MyString b{"Tanay"};
	a.display();
	b.display();
	b = a ;
	b.display();
	cout << '\n';
	b = "Hello";
	b.display();
	return 0;
}
