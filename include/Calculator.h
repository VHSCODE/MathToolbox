//
// Created by shado on 02/03/2021.
//

#pragma once
#include "BinaryTree.h"
#include <string>
class Calculator
{
 public:
	Calculator();

	float evaluate_expression(BinaryTreeNode<std::string>* expression);
};
