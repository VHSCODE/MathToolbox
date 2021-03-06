//
// Created by vhs on 02/03/2021.
//

#include "Calculator.h"
#include "BinaryTree.h"
#include "math_parser.h"
#include "utils.h"
Calculator::Calculator()
{

}
float Calculator::evaluate_expression(BinaryTreeNode<std::string>* root)
{

	return 0;
}


float sum(std::vector<float> operands)
{
	float result = 0;
	for(float opr : operands)
		result += opr;

	return result;
}
