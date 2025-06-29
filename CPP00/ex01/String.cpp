#include "String.hpp"

std::string strToUpper(std::string str)
{
    for (size_t i = 0; str[i]; i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return (str);
}

std::string truncate(std::string str, size_t width)
{
    if (str.length() > width)
        return str.substr(0, width) + ".";
    return str;
}
