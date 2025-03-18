#pragma once
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Rogue : public Character {
public:
    Rogue(string n); 
    void attack(Character& target) override;    
    void specialAttack(Character& target) override; 
};
