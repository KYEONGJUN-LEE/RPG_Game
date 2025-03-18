#pragma once
#include "Character.h"
#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <thread>    // this_thread::sleep_for
#include <chrono>    // chrono::seconds

using namespace std;

class BattleManager {
public:
    BattleManager();  // 생성자 선언
    void startBattle(Character& c1, Character& c2);  // 전투 시작 함수
};
