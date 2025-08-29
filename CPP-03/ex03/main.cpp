#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap diamond("MC");
    std::string enemy = ("enemy");

    diamond.attack(enemy);
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.highFivesGuys();
    diamond.guardGate();

    return 0;
}