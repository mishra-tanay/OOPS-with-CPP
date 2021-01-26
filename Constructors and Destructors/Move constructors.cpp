#include <iostream>
#include <vector>
using namespace std;
class Move {
public:
	Move(int data) {
		d_data = new int;
		*d_data = data;
		cout << "Constructor called with data =  " << data << '\n';
	}
	Move(const Move& deep): Move(*deep.d_data) {
		cout << "Copy Constructor called" << endl;
	}
	Move(Move && move) : Move(*move.d_data) {
		cout << "Move constructor called " << endl;
		move.d_data = nullptr;
	}
	~Move() {
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
	vector < Move> vec;
	Move M(1);
	Move a = Move(M);
	return 0l;
}