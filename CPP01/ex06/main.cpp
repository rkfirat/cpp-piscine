#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "[ Likely grumbling over trivial issues. ]" << std::endl;
        return 0;
    }

    Harl harl;

    harl.complain(argv[1]);
    return 0;
}
