#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN &other)
{
    this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}


RPN::RPN(const std::string& arg)
{
    for (size_t i = 0; i < arg.length(); i++)
    {
        char c = arg[i];
        if (std::isspace(c))
            continue;
        else if (std::isdigit(c))
        {
            _stack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            if (_stack.size() >= 2)
            {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                if (c == '+') _stack.push(a + b);
                if (c == '-') _stack.push(a - b);
                if (c == '*') _stack.push(a * b);
                if (c == '/')
                {
                    if (b == 0)
                    {
                        std::cout << "Error" << std::endl;
                        return;
                    }
                    _stack.push(a / b);
                }
            }
            else
            {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return;
        }
    }
    if (_stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    std:: cout << "Result: " << _stack.top() << std::endl;
}