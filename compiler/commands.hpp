#include <iostream>
#include <string>
using namespace std;

void meta_commands(vector<string> input) {
	if (input[0] == ".help") {
		cout <<"[to be completed]"<<endl;
	}
	else if (input[0] == ".exit") {
		exit(EXIT_SUCCESS);
	}
	else {
		cout<<"Unknown command"<<endl;
	}
}

void operation_commands(vector<string> input) {
	if (input[0] == "create") {
		cout<<"Create function"<<endl;
	}
	else if (input[0] == "insert") {
		cout<<"Insert function"<<endl;
	}
	else if (input[0] == "display") {
		cout <<"display function"<<endl;
	}
	else if (input[0] == "delete") {
		cout<<"delete function"<<endl;
	}
	else {
		cout<<"Unknown command"<<endl;
	}
}
//SQL COMMANDS
