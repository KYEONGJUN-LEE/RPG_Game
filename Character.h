#pragma once
#include <iostream>
#include <memory>
using namespace std;

class Character {
protected:
	string name;
	int health;
	int maxHealth;
	int attackPower;

public:
	Character(string name, int health, int atkPw);

	virtual void attack(Character& target) = 0;
	virtual void specialAttack(Character& target) = 0;

	void takeDamage(int damage);
	bool isAlive();
	void resetHealth();
	void showStatus();
	string getName();
};