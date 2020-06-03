#include "Parser.h"

ParseError::ParseError(int con_pos, std::string con_msg) {
	pos = con_pos;
	msg = con_msg;
}

std::string ParseError::toString() {
	std::stringstream ss("");
	ss.str(msg + " on position ");
	ss << pos;
	return ss.str();
}

ParseNode::ParseNode(Parser::NodeType _type = Parser::NONE, std::string _value = "") {
	type = _type;
	value = _value;
}

Parser::Parser(std::vector<Token> con_vec) {
	vec = con_vec;
	pos = 0;
	tree = parse_program(vec);
}

ParseNode Parser::parse_program(std::vector<Token> vec) {
	/* COMING SOON */
	ParseNode x(PROGRAM);
	/* Some code here */
	return x;
}