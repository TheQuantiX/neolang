#include "Tokenizer.h"
#include <regex>
#include <algorithm>

Tokenizer::Tokenizer() {}

bool Tokenizer::isInt(std::string exp) {
	return std::regex_match(exp, std::regex("^(-)?[0-9]+$"));
}

bool Tokenizer::isNum(std::string exp) {
	return std::regex_match(exp, std::regex("^(-)?[0-9]+(\.[0-9]*)?$"));
}

bool Tokenizer::isBool(std::string exp) {
	return std::regex_match(exp, std::regex("^(true|false)$"));
}

bool Tokenizer::isString(std::string exp) {
	return std::regex_match(exp, std::regex("^(\".*\"|\'.*\')$"));
}

bool Tokenizer::isOP(std::string exp) {
	std::vector<std::string> ops{ "+", "-", "*", "%", "**", "/", "++", "--", "+=", "-=", "*=", "/=", "**=", "%=", "and", "or", "xor", "not", "&", "|", "^", "~", "==", "=", ">", "<", ">=", "<="};
	return std::find(ops.begin(), ops.end(), exp) != ops.end();
}

bool Tokenizer::isVar(std::string exp) {
	return std::regex_match(exp, std::regex("^[a-zA-Z_][a-zA-Z_0-9]*$"));
}

bool Tokenizer::isKeyword(std::string exp) {
	return std::regex_match(exp, std::regex("^for|while|if|else|switch|case|default|break|continue|return|int|string|float|bool|function|include$"));
}

bool Tokenizer::isWS(std::string exp) {
	return std::regex_match(exp, std::regex("^[ \t\n]$"));
}

std::vector<std::string> Tokenizer::StrToken(std::string exp) {
	Tokenizer::isTheString IS = NONE;
	Tokenizer::isComment IC = CODE;
	std::vector<std::string> tokens;
	std::vector<std::string> restokens;
	bool isAst = false;
	tokens.push_back("");
	for (char i : exp) {
		std::string str(1, i);
		if (IC == CODE && tokens[tokens.size() - 1] == "/" && str == "/") {
			IC = LINE;
			tokens.pop_back();
		}
		if (str == "\n" && IC == LINE) {
			IC = CODE;
			continue;
		}
		if (IC == CODE && tokens[tokens.size() - 1] == "/" && str == "*") {
			IC = MLINE;
			tokens.pop_back();
		}
		if (IC == MLINE && isAst && str == "/") {
			IC = CODE;
			continue;
		}
		if (IC != CODE) {
			if (str == "*") {
				isAst = true;
			}
			else {
				isAst = false;
			}
			continue;
		}
		if (tokens.size() > 0 && (str == "\"" || str == "\'")) {
			if (tokens[tokens.size() - 1].size()) {
				if (str == "\"" && IS == NONE && tokens[tokens.size() - 1][tokens[tokens.size() - 1].size() - 1] != '\\') {
					tokens.push_back("\"");
					IS = DOUBLEQ;
				}
				else if (i == '\"' && IS == DOUBLEQ && tokens[tokens.size() - 1][tokens[tokens.size() - 1].size() - 1] != '\\') {
					tokens[tokens.size() - 1] += '\"';
					tokens.push_back("");
					IS = NONE;
				}
				else if (str == "\'" && IS == NONE && tokens[tokens.size() - 1][tokens[tokens.size() - 1].size() - 1] != '\\') {
					tokens.push_back("\'");
					IS = SINGLEQ;
				}
				else if (i == '\'' && IS == SINGLEQ && tokens[tokens.size() - 1][tokens[tokens.size() - 1].size() - 1] != '\\') {
					tokens[tokens.size() - 1] += '\'';
					tokens.push_back("");
					IS = NONE;
				}
				else if (IS == DOUBLEQ || IS == SINGLEQ) {
					tokens[tokens.size() - 1] += str;
				}
			}
		}
		else if (str == "\"" && IS == NONE) {
			tokens.push_back("\"");
			IS = DOUBLEQ;
		}
		else if (i == '\"' && IS == DOUBLEQ) {
			tokens[tokens.size() - 1] += '\"';
			tokens.push_back("");
			IS = NONE;
		}
		else if (str == "\'" && IS == NONE) {
			tokens.push_back("\'");
			IS = SINGLEQ;
		}
		else if (i == '\'' && IS == SINGLEQ) {
			tokens[tokens.size() - 1] += '\'';
			tokens.push_back("");
			IS = NONE;
		}
		else if (IS == DOUBLEQ || IS == SINGLEQ) {
			tokens[tokens.size() - 1] += str;
		}
		else if (isNum(tokens[tokens.size() - 1]) && (isNum(str) || str == ".")) {
			tokens[tokens.size() - 1] += str;
		}
		else if (isWS(str)) {
			tokens.push_back("");
		}
		else if (isVar(tokens[tokens.size() - 1]) && (isVar(str) || isNum(str))) {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "*" && str == "*") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "+" && str == "+") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "-" && str == "-") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "=" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "+" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "-" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "*" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "/" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "%" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "!" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == ">" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else if (tokens[tokens.size() - 1] == "<" && str == "=") {
			tokens[tokens.size() - 1] += str;
		}
		else {
			tokens.push_back(str);
		}
		if (str == "*") {
			isAst = true;
		}
		else {
			isAst = false;
		}
	}
	for (std::string i : tokens) {
		if (restokens.size() > 1) {
			if (isNum(i) && !isNum(restokens[restokens.size() - 2]) && restokens[restokens.size() - 2] != ")" && (!isVar(restokens[restokens.size() - 2]) || isKeyword(restokens[restokens.size() - 2]) || isOP(restokens[restokens.size() - 2])) && (restokens[restokens.size() - 1] == "-" || restokens[restokens.size() - 1] == "+")) {
				restokens[restokens.size() - 1] += i;
			}
			else if (!isWS(i) && i != "") {
				restokens.push_back(i);
			}
		}
		else if (restokens.size() > 0) {
			if (isNum(i) && (restokens[restokens.size() - 1] == "-" || restokens[restokens.size() - 1] == "+")) {
				restokens[restokens.size() - 1] += i;
			}
			else if (!isWS(i) && i != "") {
				restokens.push_back(i);
			}
		}
		else if (!isWS(i) && i != "") {
			restokens.push_back(i);
		}
	}
	return restokens;
}

std::vector<Token> Tokenizer::StrToToken(std::vector<std::string> exp) {
	std::vector<Token> TokenList;
	for (int i = 0; i < exp.size(); i++) {
		if (Tokenizer().isInt(exp[i])) {
			Token tok = Token(Token::TokenType::INTL, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isNum(exp[i])) {
			Token tok = Token(Token::TokenType::FLOATL, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isBool(exp[i])) {
			Token tok = Token(Token::TokenType::BOOLL, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isString(exp[i])) {
			Token tok = Token(Token::TokenType::STRINGL, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isOP(exp[i])) {
			Token tok = Token(Token::TokenType::OP, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isKeyword(exp[i])) {
			Token tok = Token(Token::TokenType::KEYWORD, exp[i]);
			TokenList.push_back(tok);
		}
		else if (Tokenizer().isVar(exp[i])) {
			Token tok = Token(Token::TokenType::ID, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == ";") {
			Token tok = Token(Token::TokenType::SEMICOLON, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == ",") {
			Token tok = Token(Token::TokenType::COMMA, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == ".") {
			Token tok = Token(Token::TokenType::DOT, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == ":") {
			Token tok = Token(Token::TokenType::COLON, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == "{") {
			Token tok = Token(Token::TokenType::LEFTCURLY, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == "}") {
			Token tok = Token(Token::TokenType::RIGHTCURLY, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == "(") {
			Token tok = Token(Token::TokenType::LEFTROUND, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == ")") {
			Token tok = Token(Token::TokenType::RIGHTROUND, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == "[") {
			Token tok = Token(Token::TokenType::LEFTSQUARE, exp[i]);
			TokenList.push_back(tok);
		}
		else if (exp[i] == "]") {
			Token tok = Token(Token::TokenType::RIGHTSQUARE, exp[i]);
			TokenList.push_back(tok);
		}
	}
	return TokenList;
}

std::vector<Token> Tokenizer::Tokenize(std::string exp) {
	std::vector<std::string> StrTokenList;
	std::vector<Token> TokenList;
	StrTokenList = Tokenizer::StrToken(exp);
	TokenList = Tokenizer::StrToToken(StrTokenList);
	return TokenList;
}