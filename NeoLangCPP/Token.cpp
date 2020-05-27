#include "Token.h"

Token::Token(TokenType type, std::string value) {
	_type = type;
	_value = value;
}