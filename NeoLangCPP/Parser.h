#pragma once
#include <vector>
#include <sstream>
#include <exception>
#include <string>
#include "Token.h"

class ParseNode {
public:
	Parser::NodeType type;
	std::string value;
	std::vector<ParseNode> children;
	ParseNode(Parser::NodeType _type = Parser::NONE, std::string _value = "");
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
	enum NodeType { // 'cause tokens are incomplete
		NONE,
		INTL,
		STRL,
		FLOATL,
		BOOLL,
		OP,
		ID,
		FUNCTION,
		BLOCK,
		BLOCK_STATEMENTS,
		PROGRAM,
		STATEMENT,
		EXPRESSION,
		TERM,
		FACTOR,
		BASE,
		ELEMENT
	};
	ParseNode tree;
	std::vector<Token> vec;
	int pos;
	/* My a priori bad code goes here */
	Parser(std::vector<Token> con_vec);
	ParseNode parse_program(std::vector<Token> vec);
};

