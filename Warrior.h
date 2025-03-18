#pragma once
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Warrior : public Character {
public:
    Warrior(string n);
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
};
