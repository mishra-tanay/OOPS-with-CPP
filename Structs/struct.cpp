#include <iostream>
using namespace std;
struct node {
	void getInput();
	void printVal();
private:
	string val;
};
void node::getInput() {
	cin >> val;
}
void node::printVal() {
	cout << "Value is " << val << std::endl;
}

struct anotherNode : public node {
private:
	int val;
};

int main() {
	node a;
	a.getInput();
	a.printVal();
	anotherNode b;
	b.getInput();
	b.printVal();
	anotherNode* temp = new anotherNode;
	temp->getInput();
	temp->printVal();
	temp = NULL;
}