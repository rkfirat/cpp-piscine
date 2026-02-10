#include "ScalarConverter.hpp"

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
    ScalarConverter::convert(input);
    return 0;
}