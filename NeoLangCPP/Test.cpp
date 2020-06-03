#include "Tokenizer.h"
#include "Token.h"
#include <vector>
#include <iostream>

using namespace std;

vector<string> vec{ "NONE", "INTL", "FLOATL", "STRINGL", "BOOLL", "OP", "KEYWORD", "ID", "SEMICOLON", "COMMA", "DOT", "COLON", "LEFTCURLY", "RIGHTCURLY", "LEFTROUND", "RIGHTROUND", "LEFTSQUARE", "RIGHTSQUARE", "EOC" };

void printVS(vector<Token> v) {
	cout << "Tokens:\n";
	for (int i = 0; i < v.size(); i++) {
		cout << i << " -> " << vec[v[i]._type] << " | " << v[i]._value <<  "\n";
	}
}

int main() {
	vector<Token> v = Tokenizer().Tokenize("int a;");
	printVS(v);
}