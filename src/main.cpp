#include "math_parser.h"
#include <iostream>

int main()
{
    std::string str;
    getline(std::cin,str);
    auto test = MathParser::parse(str);

    std::cout << test << std::endl;
    return 0;
}
