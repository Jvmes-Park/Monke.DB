#include <algorithm>
#include <string>
using namespace std;

string strip(string input) {
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	return input;
}

string read_input() {
	string input;
	while (cin.peek() != '\n') {
		cin >> input;
	}
	strip(input);
	return input;
}


