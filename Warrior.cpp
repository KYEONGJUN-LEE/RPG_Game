#include "Warrior.h"

Warrior::Warrior(string n) : Character(n, 100, 15) {}

void Warrior::attack(Character& target) {
    target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
    target.takeDamage(attackPower * 2);
    takeDamage(5);
}
