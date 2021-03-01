#include "math_parser.h"
#include "utils.h"
MathParser::MathParser()
{

}

/**
 * Parses the mathematical expression to reverse polish notation using the Shunting-yard algorithm
 * @param expression mathematical expression
 * @return string with reverse polish notation
 */
string MathParser::parse(std::string expression)
{

	stack<string> output_stack;
	stack<string> operator_stack;
    vector<string> tokens = tokenize(expression, ' ');
    int index = 0;
    while(index <= tokens.size() - 1)
    {
    	string token = tokens.at(index);
    	if(token == ",")
    	{
    		index++;
			continue;
    	}

        if(is_number(token))
        {
            output_stack.push(token);
        }
        else if(is_function(token))
        {
            operator_stack.push(token);
        }
        else if(is_operator(token))
        {
            while ( (!operator_stack.empty() ) && (  (precedes(operator_stack.top(),token) == 1) || ((precedes(operator_stack.top(),token) == 0) && associativity(token)))
            && operator_stack.top()  != "(")
            {
                string top = operator_stack.top();
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
                string top = operator_stack.top();
                operator_stack.pop();
                output_stack.push(top);
            }

            if(operator_stack.top() == "(")
            {
                operator_stack.pop();
            }
            if(is_function(operator_stack.top()))
            {
                string top = operator_stack.top();
                operator_stack.pop();
                output_stack.push(top);

            }
        }
        index++;
    }


    while(!operator_stack.empty())
    {
        string top = operator_stack.top();
        operator_stack.pop();
        output_stack.push(top);
    }

    vector<string> output;



    while(!output_stack.empty())
    {
    	string top = output_stack.top();
    	output_stack.pop();
    	output.push_back(top);
    }


    string string_output = "";
	for (unsigned i = output.size(); i-- > 0; )
	{
		string_output += output.at(i) + " ";
	}
    return string_output;
}


std::vector<std::string> MathParser::tokenize( const string& str, char delim )
{
        vector<string> tokens;
        std::stringstream stream(str);
        string temp;

        while( getline( stream, temp, delim ) )
        {
            tokens.push_back( temp );
        }
        return tokens;
}
