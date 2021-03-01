#include "math_parser.h"


int main()
{

    string str;


    getline(std::cin,str);
    auto test = MathParser::parse(str);

    std::cout << test << std::endl;
    return 0;
}
