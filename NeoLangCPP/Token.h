#pragma once
#include <string>

class Token {
public:
	enum TokenType {
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
		RIGHTSQUARE
	};

	TokenType _type;
	std::string _value;

	Token(TokenType type, std::string value);
};

