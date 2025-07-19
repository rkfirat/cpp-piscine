#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n\033[1;92m🎮 [START] Welcome to the FragTrap Canonical Battle Demo! 🤖\033[0m\n" << std::endl;

    std::cout << "\n\033[1;34m🧱 Creating unit1 using default constructor\033[0m" << std::endl;
    FragTrap unit1;

    std::cout << "\n\033[1;34m🔧 Creating unit2 named 'FragMaster'\033[0m" << std::endl;
    FragTrap unit2("FragMaster");

    std::cout << "\n\033[1;34m📋 Creating unit3 by copying unit2 (copy constructor)\033[0m" << std::endl;
    FragTrap unit3(unit2);

    std::cout << "\n\033[1;34m📝 Assigning unit1 = unit2 (copy assignment operator)\033[0m" << std::endl;
    unit1 = unit2;

    std::cout << "\n\033[1;33m⚔️  unit1 attacks unit3\033[0m" << std::endl;
    unit1.attack("FragMaster Clone");
    unit3.takeDamage(30);

    std::cout << "\n\033[1;36m🔧 unit3 repairs itself\033[0m" << std::endl;
    unit3.beRepaired(15);

    std::cout << "\n\033[1;35m🖐️  unit2 requests a high-five\033[0m" << std::endl;
    unit2.highFiveGuys();

    std::cout << "\n\033[1;33m⚔️  unit3 attacks unit1\033[0m" << std::endl;
    unit3.attack("FragMaster");
    unit1.takeDamage(30);

    std::cout << "\n\033[1;35m🖐️  unit1 requests a high-five after taking damage\033[0m" << std::endl;
    unit1.highFiveGuys();

    std::cout << "\n\033[1;92m🏁 [END] Demo finished. Now destroying all units...\033[0m\n" << std::endl;

    return 0;
}
