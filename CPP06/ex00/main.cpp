#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <sstream>

bool handleSpecialCases(const std::string &arg)
{
    if (arg == "nan" || arg == "nanf")
    {
        std::cout << "char: impossible"  << std::endl;
        std::cout << "int: impossible"  << std::endl;
        std::cout << "float: nanf"  << std::endl;
        std::cout << "double: nan"  << std::endl;
        return true;
    }

    if (arg == "+inf" || arg == "+inff" || arg == "inf" || arg == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return true;
    }

    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }

    return false;
}

void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
    {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value, const std::string &original_input)
{
    float f_val = static_cast<float>(value);
    if (original_input.find('.') == std::string::npos && !std::isinf(f_val) && !std::isnan(f_val))
        std::cout << "float: " << std::fixed << std::setprecision(1) << f_val << "f" << std::endl;
    else
        std::cout << "float: " << f_val << "f" << std::endl;
}

void printDouble(double value, const std::string &original_input)
{
    if (original_input.find('.') == std::string::npos && !std::isinf(value) && !std::isnan(value))
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <arg>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    if (input.empty())
    {
        std::cerr << "Usage: ./convert <arg>" << std::endl;
        return 1;
    }
    if (handleSpecialCases(input))
        return 0;

    double value = 0.0;

    std::stringstream ss(input);
    ss >> value;

    if (ss.fail() && input.length() != 1)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }

    if (input.length() == 1 && !isdigit(input[0]))
    {
        value = static_cast<double>(input[0]);
    }

    printChar(value);
    printInt(value);
    printFloat(value, input);
    printDouble(value, input);
    return 0;
}