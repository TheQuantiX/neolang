#pragma once
#include <string>

class Token {
public:
	enum TokenType {
		NONE,
		INTL,
		FLOATL,
		STRINGL,
		BOOLL,
		OP,
		KEYWORD,
		ID,
		SEMICOLON,
		COMMA,
		DOT,
		COLON,
		LEFTCURLY,
		RIGHTCURLY,
		LEFTROUND,
		RIGHTROUND,
		LEFTSQUARE,
		RIGHTSQUARE,
		EOC //end-of-code
	};

	TokenType _type;
	std::string _value;

	Token(TokenType type = NONE, std::string value = "");
};

