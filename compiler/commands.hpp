#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "../backend/b-tree.hpp"
using namespace std;

BTree t(3);

void meta_commands(vector<string> input) {
	if (input[0] == ".help") {
		cout<<".exit	exit the REPL"<<endl;
		cout<<"..."<<endl;
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
		if (input[1] == "database") {
			string db_name = input[2];
			cout<<"Function to create: " + db_name<<endl;
		}
		else if (input[1] == "table") {
			string tb_name = input[2];
			cout<<"Function to create: "+tb_name<<endl;
		}
		else {
			cout<<"Error: Syntax error"<<endl;
		}
	}
	else if (input[0] == "insert") {
		string s = input[1];
		stringstream num(s);
		int x = 0;
		num >> x;
		t.insert(x);
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
