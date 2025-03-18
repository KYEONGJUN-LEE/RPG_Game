#include "Character.h"

Character::Character(string name, int health, int atkPw) :
	name(name), health(health), maxHealth(health), attackPower(atkPw) {
};

void Character::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

bool Character::isAlive() {
	return health > 0;
}

void Character::showStatus() {
	cout << name << ": Hp - " << health << endl;
}

void Character::resetHealth() {
	health = maxHealth;
}

string Character::getName() {
	return name;
}