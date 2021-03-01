#pragma once
#ifndef UTILS_H
#define UTILS_H


#include <string>

using std::string;


bool is_function(string expression)
{
    //TODO add inverse trigonometric functiosn and the
    if(expression == "sin")
        return true;
    else if(expression == "cos")
        return true;
    else if(expression == "tan")
        return true;
    else if(expression == "arcsin")
        return true;
    else if(expression == "arccos")
        return true;
    else if(expression == "arctan")
        return true;
    else if(expression == "log")
        return true;
    else if(expression == "ln")
        return true;
    else if(expression == "sqrt")
        return true;
    else if(expression == "e")
        return true;
    else if(expression == "pi")
        return true;
    else if(expression == "max")
    	return true;
    else
        return false;

}

bool is_number(string expression)
{
    for(char ch : expression)
    {
        if(!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief associativity
 * @param op operator
 * @return true if left associativity, false if not
 */
bool associativity(string op)
{
    if(op == "^")
        return false;
    return true;
}

/**
 * @brief precedes
 * @param op1
 * @return 1 if op1 has greater precedence than op2, -1 if not, 0 if equal precedence
 */
int precedes(string op1, string op2)
{
    if(op1 == "-" || op1 == "+")
    {
        if(op2 == "+" || op2 == "-")
            return 0;
        return -1;
    }
    else if(op1 == "/" || op1 == "*")
    {
        if(op2 == "/" || op2 == "*")
            return 0;
        if(op2 == "^")
            return -1;
        return 1;
    }
    else if(op1 == "^")
    {
        if(op2 == "^")
            return 0;
        return 1;
    }
    return 0;

}
bool is_operator(string expression)
{
    if(expression == "+")
        return true;
    else if(expression == "-")
        return true;
    else if(expression == "*")
        return true;
    else if(expression == "/")
        return true;
    else if(expression == "^")
        return true;
    else
        return false;
}
#endif
