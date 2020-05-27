#pragma once
#include <string>
#include <vector>
#include "Token.h"

class Tokenizer {
public:
	Tokenizer();
	enum isTheString { NONE, SINGLEQ, DOUBLEQ };
	enum isComment { CODE, LINE, MLINE };
	bool isInt(std::string exp);
	bool isNum(std::string exp);
	bool isVar(std::string exp);
	bool isBool(std::string exp);
	bool isString(std::string exp);
	bool isKeyword(std::string exp);
	bool isOP(std::string exp);
	bool isWS(std::string exp);
	std::vector<std::string> StrToken(std::string exp);
	std::vector<Token> StrToToken(std::vector<std::string> exp);
	std::vector<Token> Tokenize(std::string exp);
};