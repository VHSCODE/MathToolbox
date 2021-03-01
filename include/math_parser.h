#pragma once
#ifndef MATH_PARSER_H
#define MATH_PARSER_H

#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using std::stack;
using std::string;
using std::vector;

class MathParser
{
public:
    static string parse(string expression);
private:
    static vector<string> tokenize( const string& string, char delim );
	MathParser();


};

#endif // MATH_PARSER
