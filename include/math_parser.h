#pragma once
#include <string>
#include <vector>
#include "BinaryTree.h"
class MathParser
{
public:
    
	static BinaryTreeNode* parse(const std::string& expression);
private:
	static std::string to_rpn(const std::string& expression);
	static std::vector<std::string> tokenize( const std::string& string, char delim );
	MathParser();


};