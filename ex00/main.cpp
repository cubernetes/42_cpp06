#include "ScalarConverter.hpp"
#include <iostream>

void tests() {
    ScalarConverter::convert("0");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-0.5f");
    ScalarConverter::convert("-3.141592");
}

int main(int ac, char **av) {
    if (ac <= 1)
        tests();
    else if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cout << "Expected 0 or 1 argument, not " << ac - 1 << std::endl;
    return 0;
}
