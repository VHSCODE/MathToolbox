#pragma once
#include <string>
#include <vector>

class MathParser
{
public:
    static std::string parse(const std::string& expression);
	static std::vector<std::string> tokenize( const std::string& string, char delim );
private:

	MathParser();


};