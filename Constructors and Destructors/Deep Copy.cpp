#include <iostream>
#include <vector>
using namespace std;
class Deep {
public:
	Deep(int data) {
		d_data = new int;
		*d_data = data;
		cout << "Constructor called with data =  " << data << '\n';
	}
	Deep(const Deep& deep): Deep(*deep.d_data) {
		cout << "Copy Constructor called" << endl;
	}
	~Deep() {
		if (d_data != nullptr)
			cout << "Destructor called with data = " << d_data <<  endl;
		else
			cout << "Destructor call with nullptr" << endl;
		delete d_data;
	}
	int getDataValue() const {
		return *d_data;
	}
private:
	int* d_data;
};

int main() {
	vector < Deep> vec;
	vec.push_back(Deep{1});
	vec.push_back(Deep{2});
	return 0l;
}