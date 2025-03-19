#pragma once

#include <string>

class ScalarConverter {
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const &t);
    ScalarConverter &operator=(ScalarConverter const &t);

  public:
    static void convert(const std::string &);
};
