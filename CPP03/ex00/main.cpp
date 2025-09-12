#include "ClapTrap.hpp"

int main() {
    std::cout << std::endl << "\033[1;94m🎮 Welcome to the ClapTrap Battle Arena! 🎮\033[0m" << std::endl << std::endl;

    ClapTrap jack("Jack");
    ClapTrap bob("Bob");

    std::cout << std::endl << "\033[1;33m🔥 Round 1: Jack attacks Bob\033[0m" << std::endl;
    jack.attack("Bob");
    bob.takeDamage(10);

    std::cout << std::endl << "\033[1;33m🛠️  Round 2: Bob repairs himself\033[0m" << std::endl;
    bob.beRepaired(5);

    std::cout << std::endl << "\033[1;33m⚔️  Round 3: Jack attacks again\033[0m" << std::endl;
    jack.attack("Bob");
    bob.takeDamage(4);

    std::cout << std::endl << "\033[1;33m💤 Round 4: Jack is low on energy but tries to repair\033[0m" << std::endl;
    jack.beRepaired(2);

    std::cout << std::endl << "\033[1;33m🧪 Round 5: Bob gets hit hard\033[0m" << std::endl;
    jack.attack("Bob");
    bob.takeDamage(20);

    std::cout << std::endl << "\033[1;33m🧟 Final Round: Bob tries to fight back while dead\033[0m" << std::endl;
    bob.attack("Jack");
    bob.beRepaired(3);

    std::cout << std::endl << "\033[1;94m🏁 Battle ended!\033[0m" << std::endl;
    return 0;
}
