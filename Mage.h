#pragma once
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Mage : public Character {
private:
    int mana;
public:
    Mage(string n); 
    void attack(Character& target) override;  
    void specialAttack(Character& target) override; 
};
