#include <stdio.h>
#include <vector>
#include <string.h>
#include "scanner.hpp"
#include "commands.hpp"

void compile(const char* command) {
	initScanner(command);
	int line = 1;
	vector<int>inputs;
	for (;;) {
	      Token token = scanToken();
	      //if (token.line != line) {
	      //   printf("%4d ", token.line);
      	      //     line = token.line;
	      //} 	
		if (token.type == 8) {
			operation_commands("create");
		}
	      else {
	               printf("   | ");
	      }
              printf("%2d '%.*s'\n", token.type, token.length, token.start); 
	      inputs.push_back(token.type);
	      if (token.type == TOKEN_EOF) break;
	}
}
