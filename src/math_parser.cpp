#include "math_parser.h"
#include "utils.h"
#include <sstream>
#include <stack>
#include <iostream>
MathParser::MathParser()
{

}

BinaryTreeNode* MathParser::parse(const std::string& expression)
{

    std::string rpn_expression = to_rpn(expression);

    std::stack<BinaryTreeNode*> stack;

    for(std::string token : tokenize(rpn_expression,' '))
    {
        if(Utils::is_operator(token))
        {
            auto* right = stack.top();
            stack.pop();
            auto* left = stack.top();
            stack.pop();

            auto insert = new BinaryTreeNode(token,left,right);
            stack.push(insert);
        }
        else
            stack.push(new BinaryTreeNode(token));
    }
    return stack.top();
}
/**
 * Convert the mathematical expression to reverse polish notation using the Shunting-yard algorithm
 * @param expression mathematical expression
 * @return string with reverse polish notation
 */
std::string MathParser::to_rpn(const std::string& expression)
{

	std::stack<std::string> output_stack;
	std::stack<std::string> operator_stack;
	std::vector<std::string> tokens = tokenize(expression, ' ');
    int index = 0;
    while(index <= tokens.size() - 1)
    {
    	std::string token = tokens.at(index);
    	if(token == ",")
    	{
    		index++;
			continue;
    	}

        if(Utils::is_number(token))
        {
            output_stack.push(token);
        }
        else if(Utils::is_function(token))
        {
            operator_stack.push(token);
        }
        else if(Utils::is_operator(token))
        {
            while ( (!operator_stack.empty() ) && (  (Utils::precedes(operator_stack.top(),token) == 1) || ((Utils::precedes(operator_stack.top(),token) == 0) && Utils::associativity(token)))
            && operator_stack.top()  != "(")
            {
                std::string top = operator_stack.top();
                operator_stack.pop();
                output_stack.push(top);
            }
            operator_stack.push(token);
        }
        else if(token == "(")
            operator_stack.push(token);
        else if(token == ")")
        {
            while(operator_stack.top() != "(")
            {
                std::string top = operator_stack.top();
                operator_stack.pop();
                output_stack.push(top);
            }

            if(operator_stack.top() == "(")
            {
                operator_stack.pop();
            }
            if(!operator_stack.empty())
            {
            	if(Utils::is_function(operator_stack.top()))
				{
					std::string top = operator_stack.top();
					operator_stack.pop();
					output_stack.push(top);
				}
            }
        }
        else
        {
            output_stack.push(token);
        }
        index++;
    }


    while(!operator_stack.empty())
    {
        std::string top = operator_stack.top();
        operator_stack.pop();
        output_stack.push(top);
    }

    std::vector<std::string> output;



    while(!output_stack.empty())
    {
    	std::string top = output_stack.top();
    	output_stack.pop();
    	output.push_back(top);
    }


    std::string string_output = "";
	for (unsigned i = output.size(); i-- > 0; )
	{
		string_output += output.at(i) + " ";
	}
    return string_output;
}



std::vector<std::string> MathParser::tokenize( const std::string& str, char delim )
{
        std::vector<std::string> tokens;

        std::stringstream stream(str);
        std::string temp;
        while( getline( stream, temp, delim ) )
        {
            tokens.push_back( temp );
        }
        return tokens;
}
