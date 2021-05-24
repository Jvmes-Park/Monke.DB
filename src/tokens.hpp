typedef enum {
	LEFT_PAREN, RIGHT_PAREN, SEMI_COLON,
	QUOTE, COMMA, DOT, STAR, EQUAL, SLASH,

	CREATE, INSERT, DELETE, DISPLAY, HELP, EXIT,

	IDENTIFIER, STRING, NUMBER,

	TOKEN_ERROR, TOKEN_EOF
} TokenType;

typedef struct {
	TokenType type;
	const char* start;
	int length;
	int line;
} Token;
