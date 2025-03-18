#include "Rogue.h"
#include <cstdlib>
#include <ctime>


Rogue::Rogue(string n) : Character(n, 90, 12) {
    srand(static_cast<unsigned int>(time(nullptr))); 
}

void Rogue::attack(Character& target) {
    target.takeDamage(attackPower);
}


void Rogue::specialAttack(Character& target) {
    int randNum = rand() % 100;  
    if (randNum < 70) {  
        target.takeDamage(attackPower * 3);
    }
    else {
        cout << "공격 실패" << endl;
    }
}
