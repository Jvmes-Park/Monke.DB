#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

size_t tokenize(const string &line, vector<string> &tokens, char ch) {
	size_t position = line.find( ch );
	size_t initPos = 0;
	tokens.clear();
	while (position != string::npos) {
		tokens.push_back(line.substr(initPos, position - initPos));
		initPos = position + 1;
		position = line.find(ch, initPos);
	}
	tokens.push_back(line.substr(initPos, min(position, line.size()) - initPos + 1));
	return tokens.size();
}
