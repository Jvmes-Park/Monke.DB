#include <iostream>
#include <string>
using namespace std;

void meta_commands(string command) {
	if (command == ".help") {
		cout <<"[to be completed]"<<endl;
	}
	else if (command == ".exit") {
		exit(EXIT_SUCCESS);
	}
	else {
		cout<<"Unknown command: " + command<<endl;
	}
}

void operation_commands(string command) {
	if (command == "create") {
		cout<<"Create function"<<endl;
	}
	else if (command == "insert") {
		cout<<"Insert function"<<endl;
	}
	else if (command == "display") {
		cout <<"display function"<<endl;
	}
	else if (command == "delete") {
		cout<<"delete function"<<endl;
	}
	else {
		cout<<"Unknown command: " + command<<endl;
	}
}
//SQL COMMANDS
