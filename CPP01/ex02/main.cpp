#include <iostream>

int main(void)
{
    std::string lorem = "HI THIS IS BRAIN";
    std::string* stringPTR = &lorem;
    std::string& stringREF = lorem;

    std::cout << "The memory address of the variable: " << &lorem << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    
    std::cout << "The value of the variable: " << lorem << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    
    return 0;
}
