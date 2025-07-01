#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "[ Likely grumbling over trivial issues. ]" << std::endl;
        return 0;
    }

    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    return 0;
}
