#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;

typedef enum {
	T_LEFT_PAREN, T_RIGHT_PAREN, T_SEMI_COLON,
	T_COMMA, T_DOT, T_STAR, T_EQUAL, T_SLASH, 

	T_CREATE, T_INSERT, T_DELETE, T_DISPLAY, T_HELP, T_EXIT,

	T_IDENTIFIER, T_STRING, T_NUMBER,

	T_ERROR, T_EOF
} TokenType;

typedef struct {
	TokenType type;
	const char* start;
	int length;
	int line;
} Token;

typedef struct {
	const char* start;
	const char* current;
	int line;
} Scanner;

Scanner scanner;

void initScanner(const char* source) {
	scanner.start = source;
	scanner.current = source;
	scanner.line = 1;
}

static bool isAtEnd() {
	return *scanner.current == '\0';
}

static Token makeToken(TokenType type) {
	Token token;
	token.type = type;
	token.start = scanner.start;
	token.length = (int)(scanner.current - scanner.start);
	token.line = scanner.line;
	return token;
}

static Token errorToken(const char* message) {
	Token token;
	token.type = T_ERROR;
	token.start = message;
	token.length = (int)strlen(message);
	token.line = scanner.line;
	return token;
}

static char advance() {
	scanner.current++;
	return scanner.current[-1];
}

static char peek() {
	return *scanner.current;
}

static char peekNext() {
	if (isAtEnd()) return '\0';
	return scanner.current[1];
}

static Token String() {
	while (peek() != '"' && !isAtEnd()) {
		if (peek() == '\n') scanner.line++;
		advance();
	}
	if (isAtEnd()) return errorToken("Unterminated string");
	advance();
	return makeToken(T_STRING);
}

static TokenType checkKeyword(int start, int length, const char* rest, TokenType type) {
	if (scanner.current - scanner.start == start + length && memcmp(scanner.start + start, rest, length) == 0) {
		return type;
	}
	return T_IDENTIFIER;
}

static TokenType identifierType() {
	switch (scanner.start[0]) {
		case 'c': return checkKeyword(1, 5, "reate", T_CREATE);
		case 'i': return checkKeyword(1, 5, "nsert", T_INSERT);
		case 'd': 
			if (scanner.current - scanner.start > 1) {
				switch(scanner.start[1]) {
					case 'e': return checkKeyword(2, 4, "lete", T_DELETE);
					case 'i': return checkKeyword(2, 4, "play", T_DISPLAY);
				}
			}
			break;
		case '.': 
			if (scanner.current - scanner.start > 1) {
				switch(scanner.start[1]) {
					case 'h': return checkKeyword(2, 3, "elp", T_HELP);
					case 'e': return checkKeyword(2, 3, "xit", T_EXIT);
				}
			}
			break;
	}
	return T_IDENTIFIER;
}

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

static bool isAlpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

static Token identifier() {
	while (isAlpha(peek()) || isDigit(peek())) advance();
	return makeToken(identifierType());
}

static Token number() {
	while (isDigit(peek())) advance();
	if (peek() == '.' && isDigit(peekNext())) {
		advance();
	}
	while (isDigit(peek())) advance();
	return makeToken(T_NUMBER);
}

static void skipWhitespace() {
	for (;;) {
		char c = peek();
		switch(c) {
			case ' ':
				advance();
				break;
			default:
				return;
		}
	}
}

Token scanToken() {
	skipWhitespace();
	scanner.start = scanner.current;
	if (isAtEnd()) 
		return makeToken(T_EOF);
	char c = advance();
	if (isAlpha(c)) return identifier();
	if (isDigit(c)) return number();
	switch(c) {
		case '(': return makeToken(T_LEFT_PAREN);
		case ')': return makeToken(T_RIGHT_PAREN);
		case ',': return makeToken(T_COMMA);
		case '.': return makeToken(T_DOT);
		case '/': return makeToken(T_SLASH);
		case ';': return makeToken(T_SEMI_COLON);
		case '=': return makeToken(T_EQUAL);
		case '*': return makeToken(T_STAR);
		case '"': return String();
	}
	return errorToken("Unexpected character.");
}

