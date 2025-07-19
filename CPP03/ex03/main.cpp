#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n\033[1;92m🎮 [START] Welcome to the DiamondTrap Multiple Inheritance Demo! 💎\033[0m\n" << std::endl;

    std::cout << "\n\033[1;34m🧱 Creating unit1 using default constructor\033[0m" << std::endl;
    DiamondTrap unit1;

    std::cout << "\n\033[1;34m🔧 Creating unit2 named 'DiamondMaster'\033[0m" << std::endl;
    DiamondTrap unit2("DiamondMaster");

    std::cout << "\n\033[1;34m📋 Creating unit3 by copying unit2 (copy constructor)\033[0m" << std::endl;
    DiamondTrap unit3(unit2);

    std::cout << "\n\033[1;34m📝 Assigning unit1 = unit2 (copy assignment operator)\033[0m" << std::endl;
    unit1 = unit2;

    std::cout << "\n\033[1;35m💎 Testing whoAmI method\033[0m" << std::endl;
    unit1.whoAmI();
    unit2.whoAmI();
    unit3.whoAmI();

    std::cout << "\n\033[1;33m⚔️  unit1 attacks unit3 (using ScavTrap's attack)\033[0m" << std::endl;
    unit1.attack("DiamondMaster Clone");
    unit3.takeDamage(20);

    std::cout << "\n\033[1;36m🔧 unit3 repairs itself\033[0m" << std::endl;
    unit3.beRepaired(15);

    std::cout << "\n\033[1;35m🖐️  unit2 requests a high-five (from FragTrap)\033[0m" << std::endl;
    unit2.highFiveGuys();

    std::cout << "\n\033[1;35m🛡️  unit3 enters Guard Gate mode (from ScavTrap)\033[0m" << std::endl;
    unit3.guardGate();

    std::cout << "\n\033[1;33m⚔️  unit3 attacks unit1\033[0m" << std::endl;
    unit3.attack("DiamondMaster");
    unit1.takeDamage(20);

    std::cout << "\n\033[1;35m💎 Final whoAmI check\033[0m" << std::endl;
    unit1.whoAmI();

    std::cout << "\n\033[1;92m🏁 [END] Demo finished. Now destroying all units...\033[0m\n" << std::endl;

    return 0;
}
