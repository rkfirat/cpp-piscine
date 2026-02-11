#pragma once

#include <stack>
#include <iostream>

class RPN
{
public:
    RPN();
    RPN(const std::string& arg);
    ~RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);


private:
    std::stack<int> _stack;
};