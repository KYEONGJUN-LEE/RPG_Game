#include "Mage.h"

Mage::Mage(string n) : Character(n, 80, 18), mana(100) {}


void Mage::attack(Character& target) {
    target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
    if (mana < 20) { 
        throw runtime_error("마나가 부족합니다");
    }
    target.takeDamage(static_cast<int>(attackPower * 1.5)); // ?? 명시적 변환
    mana -= 20;
}
