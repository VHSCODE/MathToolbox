#pragma once
#include <string>
#include <vector>
#include "BinaryTree.h"
class MathParser
{
public:
    
	static BinaryTreeNode<std::string>* parse(const std::string& expression);
private:
	static std::string to_rpn(const std::string& expression);
	MathParser();


};