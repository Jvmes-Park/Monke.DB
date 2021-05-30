#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
#include "../src/compile.hpp"
#include "../compiler/commands.hpp"
#include "../compiler/tokenizer.hpp"
using namespace std;

#define MAX_COMMAND_SIZE 100
#define MAX_PASSWORD_SIZE 20

void indent() {
	cout<<">> ";
}

string strip(string input) {
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	return input;
}

void run() {
	for (;;) {
		indent();
		//TO DO: We need char command not string.
		string command;
		getline (cin, command);
		vector<string> tokens;
		compile(command);
		//tokenize(command, tokens, ' ');
		//if (command[0] == '.') {
		//	meta_commands(tokens);
		//}
		//else {
		//	operation_commands(tokens);
	}
}

void prompt() {
	cout<<"Monke.DB"<<endl;
	cout<<"Version : 1.0"<<endl;
	cout<<"Type '.help' for more info\n"<<endl;
	cout<<"Password: ";

	char password_input[MAX_PASSWORD_SIZE];
	cin.getline (password_input, MAX_PASSWORD_SIZE);
	string password = strip(password_input);

	if (password == "placeholder") {
		run();
	}
	else {
		cout<<"error: Password authentication failed"<<endl;
	}
}

int main() {
	system("cls");
	prompt();
}
