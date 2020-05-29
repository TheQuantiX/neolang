#pragma once
#include <vector>
#include <sstream>
#include <exception>
#include "Token.h"

class ParseNode {
public:
	Token nodeToken;
	std::vector<ParseNode> children;
	ParseNode(Token con_token = Token(Token::NONE, ""));
};

class ParseError: public std::exception {
public:
	int pos;
	std::string msg;
	ParseError(int con_pos, std::string con_msg);
	std::string toString();
};

class Parser {
public:
	ParseNode tree;
	std::vector<Token> vec;
	int pos;
	/* My a priori bad code goes here */
	Parser(std::vector<Token> con_vec);
	ParseNode parse(std::vector<Token> vec);
};

