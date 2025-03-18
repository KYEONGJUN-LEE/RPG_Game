#include "BattleManager.h"


BattleManager::BattleManager() {
    srand(static_cast<unsigned int>(time(nullptr)));  
}


void BattleManager::startBattle(Character& c1, Character& c2) {
    cout << "전투가 시작!!" << endl;

    bool turn = rand() % 2;
    Character* first = turn ? &c1 : &c2;
    Character* second = turn ? &c2 : &c1;

    cout << first->getName() << "이(가) 선공을 잡았습니다!\n" << endl;

    while (c1.isAlive() && c2.isAlive()) {
        for (int i = 0; i < 2; i++) {  
            Character* attacker = (i == 0) ? first : second;
            Character* defender = (i == 0) ? second : first;

            if (!attacker->isAlive()) {
                break;
            }

            cout << attacker->getName() << "의 차례!" << endl;

            int randNum = rand() % 100;
            try {
                if (randNum < 70) {
                    cout << attacker->getName() << "의 기본 공격을 시도" << endl;
                    attacker->attack(*defender);
                }
                else {
                    cout << attacker->getName() << "의 특수 공격을 시도" << endl;
                    attacker->specialAttack(*defender);
                }
            }
            catch (const runtime_error& e) {
                cout << "! " << e.what() << " 특수 공격 실패, 기본 공격으로 전환!" << endl;
                attacker->attack(*defender);
            }

            defender->showStatus();
            if (!defender->isAlive()) {
                cout << defender->getName() << "이(가) 쓰러졌습니다!" << endl;
                return;
            }

            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}
