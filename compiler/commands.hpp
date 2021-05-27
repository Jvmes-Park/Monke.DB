#include <iostream>
#include <string>
#include "../backend/b-tree.hpp"
using namespace std;

Btree t(3);

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
		t.insert(input[1]);
	}
	else if (input[0] == "display") {
		cout<<"Table: "<<endl;
		t.traverse();
	}
	else if (input[0] == "delete") {
		cout<<"delete function"<<endl;
	}
	else {
		cout<<"Unknown command"<<endl;
	}
}
//SQL COMMANDS
