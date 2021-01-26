#include <iostream>
using namespace std;
class Players {
	Players() {
		player_count++;
	}

	~Players() {
		player_count;
	}
public:
	static int player_count;
	static int getPlayerCount() {
		return player_count;
	}
};

int Players::player_count = 0;

int main() {
	Players::player_count++;
	cout << Players::getPlayerCount() << '\n';
	return 0;
}