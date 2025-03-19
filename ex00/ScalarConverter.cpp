#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &t) { *this = t; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &t) {
    (void)t;
    return *this;
}

void ScalarConverter::convert(const std::string &s) {
    // convert char: 'c', '0', '\' but not '\\', '\'', '\x1b', '\033'
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'') {
        if (std::isprint(s[1]) && s[1] != '\\' && s[1] != '\'') {
            std::cout << "Char:   '" << s[1] << "'" << std::endl; // no need for static cast, it's already char
        } else {
            std::cout << "Char:   Not displayable in a simple format (either not printable, out of ASCII range, or a single quote or backslash)" << std::endl;
        }
        std::cout << "Int:    " << static_cast<int>(s[1]) << std::endl;
        std::cout << "Float:  " << static_cast<int>(s[1]) << ".f" << std::endl;
        std::cout << "Double: " << static_cast<int>(s[1]) << "." << std::endl;
    } else {
        char *end;
        errno = 0;
        double d = strtod(s.c_str(), &end);
        int err = errno;
        long l = static_cast<long>(d);

        if (s.length() == 0) {
            std::cout << "Char:   Invalid format" << std::endl;
            std::cout << "Int:    Invalid format" << std::endl;
            std::cout << "Float:  Invalid format" << std::endl;
            std::cout << "Double: Invalid format" << std::endl;
            return;
        } else if (*end != '\0') { // check floating point literal case, i.e. 1.5f, 1.F, 1.e-14f, or invalid cases like 31f
            char *start = const_cast<char *>(s.c_str());
            bool has_dot = false;
            while (start != end) {
                if (*start == '.') {
                    has_dot = true;
                }
                ++start;
            }
            char char_before = *(end - 1);

            if (has_dot && (*end == 'f' || *end == 'F')) {
                // all good
            } else if (char_before != '.') {
                std::cout << "Char:   Invalid format" << std::endl;
                std::cout << "Int:    Invalid format" << std::endl;
                std::cout << "Float:  Invalid format" << std::endl;
                std::cout << "Double: Invalid format" << std::endl;
                return;
            }
        }

        if (l >= ' ' && l <= '~' && l != '\\' && l != '\'' && err != ERANGE) {
            std::cout << "Char:   '" << static_cast<char>(l) << "'" << std::endl;
        } else {
            std::cout << "Char:   Not displayable in a simple format (either not printable, out of ASCII range, or a single quote or backslash)" << std::endl;
        }

        if (l >= INT_MIN && l <= INT_MAX && err != ERANGE) {
            std::cout << "Int:    " << l << std::endl;
        } else {
            std::cout << "Int:    Out of range" << std::endl;
        }

        if ((d >= static_cast<double>(-FLT_MAX) && d <= static_cast<double>(FLT_MAX) && err != ERANGE) || isnan(d)) {
            if (isnan(d)) {
                if (std::signbit(d)) {
                    std::cout << "Float:  " << "Negative float NaN not supported according to subject" << std::endl;
                } else {
                    std::cout << "Float:  " << static_cast<float>(d) << "f" << std::endl;
                }
            } else {
                if (static_cast<long>(floorf(static_cast<float>(d))) == static_cast<long>(ceilf(static_cast<float>(d)))) {
                    std::cout << "Float:  " << std::fixed << std::setprecision(0) << static_cast<float>(d) << ".f" << std::endl;
                } else {
                    std::cout << "Float:  " << static_cast<float>(d) << "f" << std::endl;
                }
            }
        } else {
            if (d > static_cast<double>(FLT_MAX)) {
                std::cout << "Float:  +" << static_cast<float>(d) << "f" << std::endl;
            } else {
                std::cout << "Float:  " << static_cast<float>(d) << "f" << std::endl;
            }
        }

        if ((!isinf(d) && err != ERANGE) || isnan(d)) {
            if (isnan(d)) {
                if (std::signbit(d)) {
                    std::cout << "Double: " << "Negative double NaN not supported according to subject" << std::endl;
                } else {
                    std::cout << "Double: " << d << std::endl;
                }
            } else {
                if (static_cast<long>(d) == static_cast<long>(ceil(d))) {
                    std::cout << "Double: " << std::fixed << std::setprecision(0) << d << "." << std::endl;
                } else {
                    std::cout << "Double: " << d << std::endl;
                }
            }
        } else {
            if (d > static_cast<double>(DBL_MAX)) {
                std::cout << "Double: +" << d << std::endl;
            } else {
                std::cout << "Double: " << d << std::endl;
            }
        }
    }
}
