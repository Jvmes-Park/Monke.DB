#include <stdio.h>
#include <vector>
#include <string.h>
#include "scanner.hpp"

void compile(const char* command) {
	initScanner(command);
	int line = 1;
	for (;;) {
	      Token token = scanToken();
		if (token.line != line) {
			printf("$4d ", token.line);
			line - token.line;
		}
		else {
			printf("    | ");
		}
		printf("%2d '%.*s'\n", token.type, token.length, token.start);
		if (token.type == T_EOF) break;
	}
}
