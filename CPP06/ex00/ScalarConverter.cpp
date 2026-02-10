#include "ScalarConverter.hpp"

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

void printFloat(double value)
{
    float f_val = static_cast<float>(value);
    if (!std::isinf(f_val) && !std::isnan(f_val) && std::floor(f_val) == f_val)
        std::cout << "float: " << std::fixed << std::setprecision(1) << f_val << "f" << std::endl;
    else
        std::cout << "float: " << f_val << "f" << std::endl;
}

void printDouble(double value)
{
    if (!std::isinf(value) && !std::isnan(value) && std::floor(value) == value)
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}


void ScalarConverter::convert(const std::string &arg)
{
    if (handleSpecialCases(arg))
        return ;

    std::string input = arg;
    if (input.length() > 1 && input[input.length() - 1] == 'f' && input.find('.') != std::string::npos)
        input.erase(input.length() - 1);

    double value = 0.0;

    std::stringstream ss(input);
    ss >> value;

    if (ss.fail() && arg.length() != 1)
    {
        std::cerr << "Error: invalid input" << std::endl;
        return ;
    }

    if (arg.length() == 1 && !isdigit(arg[0]))
    {
        value = static_cast<double>(arg[0]);
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}