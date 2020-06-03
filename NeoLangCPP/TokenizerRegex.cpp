#include "Tokenizer.h"
#include <regex>
#include <algorithm>

bool Tokenizer::isInt(std::string exp) {
	return std::regex_match(exp, std::regex("^(-)?[0-9]+$"));
}

bool Tokenizer::isNum(std::string exp) {
	return std::regex_match(exp, std::regex("^[-+]?([0-9]*[.])?[0-9]+([eE][-+]?\d+)?$"));
}

bool Tokenizer::isBool(std::string exp) {
	return std::regex_match(exp, std::regex("^(true|false)$"));
}

bool Tokenizer::isString(std::string exp) {
	return std::regex_match(exp, std::regex("^(\".*\"|\'.*\')$"));
}

bool Tokenizer::isOP(std::string exp) {
	std::vector<std::string> ops{ "+", "-", "*", "%", "**", "/", "++", "--", "+=", "-=", "*=", "/=", "**=", "%=", "and", "or", "xor", "not", "&", "|", "^", "~", "==", "=", ">", "<", ">=", "<=" };
	return std::find(ops.begin(), ops.end(), exp) != ops.end();
}

bool Tokenizer::isVar(std::string exp) {
	return std::regex_match(exp, std::regex("^[a-zA-Z_][a-zA-Z_0-9]*$"));
}

bool Tokenizer::isKeyword(std::string exp) {
	return std::regex_match(exp, std::regex("^for|while|if|else|switch|case|default|break|continue|return|int|string|float|bool|func|include$"));
}

bool Tokenizer::isWS(std::string exp) {
	return std::regex_match(exp, std::regex("^[ \t\n]$"));
}