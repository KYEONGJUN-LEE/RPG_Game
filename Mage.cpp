#include "Mage.h"

Mage::Mage(string n) : Character(n, 80, 18), mana(100) {}


void Mage::attack(Character& target) {
    target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
    if (mana < 20) { 
        throw runtime_error("������ �����մϴ�");
    }
    target.takeDamage(static_cast<int>(attackPower * 1.5)); // ?? ����� ��ȯ
    mana -= 20;
}
