#include "Harl.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{

    (void)argv;
    if (argc != 1)
    {
        std::cout << "\033[1;90m[🤷 Unknown] Likely grumbling over trivial issues.\033[0m" << std::endl;
        return 0;
    }

    Harl harl;

    std::cout << "\n\033[1;35m--- Harl is about to complain at all levels ---\033[0m\n" << std::endl;

    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "\033[1;32m✔️  All complaints delivered.\033[0m" << std::endl;

    return 0;
}
