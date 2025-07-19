#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n\033[1;92m🎮 [START] Welcome to the ScavTrap Canonical Battle Demo! 🤖\033[0m\n" << std::endl;

    std::cout << "\n\033[1;34m🧱 Creating unit1 using default constructor\033[0m" << std::endl;
    ScavTrap unit1;

    std::cout << "\n\033[1;34m🔧 Creating unit2 named 'Brutus'\033[0m" << std::endl;
    ScavTrap unit2("Brutus");

    std::cout << "\n\033[1;34m📋 Creating unit3 by copying unit2 (copy constructor)\033[0m" << std::endl;
    ScavTrap unit3(unit2);

    std::cout << "\n\033[1;34m📝 Assigning unit1 = unit2 (copy assignment operator)\033[0m" << std::endl;
    unit1 = unit2;

    std::cout << "\n\033[1;33m⚔️  unit1 attacks unit3\033[0m" << std::endl;
    unit1.attack("Brutus Clone");
    unit3.takeDamage(20);

    std::cout << "\n\033[1;36m🔧 unit3 repairs itself\033[0m" << std::endl;
    unit3.beRepaired(10);

    std::cout << "\n\033[1;35m🛡️  unit2 enters Guard Gate mode\033[0m" << std::endl;
    unit2.guardGate();

    std::cout << "\n\033[1;92m🏁 [END] Demo finished. Now destroying all units...\033[0m\n" << std::endl;

    return 0;
}
