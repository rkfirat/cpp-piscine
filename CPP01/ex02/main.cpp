#include <iostream>

int main(void)
{
    std::string lorem = "HI THIS IS BRAIN";
    std::string* stringPTR = &lorem;
    std::string& stringREF = lorem;

    std::cout << "\033[1;36m📍 Memory Addresses:\033[0m\n";
    std::cout << "  🧠  &lorem      : \033[1;33m" << &lorem << "\033[0m\n";
    std::cout << "  🔗  stringPTR   : \033[1;33m" << stringPTR << "\033[0m\n";
    std::cout << "  🪞  &stringREF   : \033[1;33m" << &stringREF << "\033[0m\n";

    std::cout << "\n\033[1;32m📦 Stored Values:\033[0m\n";
    std::cout << "  🧠  lorem       : \033[1;37m" << lorem << "\033[0m\n";
    std::cout << "  🔗  *stringPTR  : \033[1;37m" << *stringPTR << "\033[0m\n";
    std::cout << "  🪞   stringREF   : \033[1;37m" << stringREF << "\033[0m\n";

    return 0;
}
