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

ParseNode::ParseNode(Token con_token) {
	nodeToken = Token(con_token._type, con_token._value);
}

Parser::Parser(std::vector<Token> con_vec) {
	vec = con_vec;
	pos = 0;
	tree = parse(vec);
}

ParseNode Parser::parse(std::vector<Token> vec) {
	/* COMING SOON */
	ParseNode x;
	/* Some code here */
	return x;
}