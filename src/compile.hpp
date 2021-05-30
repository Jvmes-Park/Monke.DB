#include <stdio.h>
#include <vector>
#include <string.h>
#include "scanner.hpp"

void compile(const char* command) {
	initScanner(command);
	int line = 1;
	vector<int>inputs;
	for (;;) {
	      Token token = scanToken();
		if (token.line != line) {
			cout<<token.line<<endl;
			line - token.line;
		}
		else {
			cout<<"    | "<<endl;
		}
		printf("%2d '%.*s'\n", token.type, token.length, token.start);
		if (token.type == T_EOF) break;
	}
}
