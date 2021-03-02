//
// Created by vhs on 02/03/2021.
//

#include "Calculator.h"
#include "math_parser.h"
#include "utils.h"
Calculator::Calculator()
{

}
float Calculator::evaluate_expression(std::string expression)
{

	std::string reverse_polish = MathParser::parse(expression);

	std::vector<std::string> tokens = MathParser::tokenize(reverse_polish,' ');
	std::vector<float> stack;

	float result = 0.0f;

	for(std::string token : tokens)
	{
		if(Utils::is_number(token))
			stack.push_back(std::stof(token));
	}

}


float sum(std::vector<float> operands)
{
	float result = 0;
	for(float opr : operands)
		result += opr;

	return result;
}
