#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <iterator>
#include "helper.hpp"
#include "commands.hpp"
using namespace std;

#define MAX_COMMAND_SIZE 100
#define MAX_PASSWORD_SIZE 20

void indent() {
	cout<<">> ";
}

void start() {
	indent();
	char command[MAX_COMMAND_SIZE];
	cin.getline (command, MAX_COMMAND_SIZE);
	string cmd = strip(command);
	if (cmd == ".help") {
		cout<<"[to be completed]"<<endl;
	}
	else if (cmd == ".exit") {
		exit(EXIT_SUCCESS);
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
	if (password == "jdp") {
		start();
	}
	else {
		cout<<"error: Password authentication failed"<<endl;
	}
	//To be completed
}

int main() {
	prompt();
}
