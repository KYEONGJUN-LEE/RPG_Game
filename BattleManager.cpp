#include "BattleManager.h"


BattleManager::BattleManager() {
    srand(static_cast<unsigned int>(time(nullptr)));  
}


void BattleManager::startBattle(Character& c1, Character& c2) {
    cout << "������ ����!!" << endl;

    bool turn = rand() % 2;
    Character* first = turn ? &c1 : &c2;
    Character* second = turn ? &c2 : &c1;

    cout << first->getName() << "��(��) ������ ��ҽ��ϴ�!\n" << endl;

    while (c1.isAlive() && c2.isAlive()) {
        for (int i = 0; i < 2; i++) {  
            Character* attacker = (i == 0) ? first : second;
            Character* defender = (i == 0) ? second : first;

            if (!attacker->isAlive()) {
                break;
            }

            cout << attacker->getName() << "�� ����!" << endl;

            int randNum = rand() % 100;
            try {
                if (randNum < 70) {
                    cout << attacker->getName() << "�� �⺻ ������ �õ�" << endl;
                    attacker->attack(*defender);
                }
                else {
                    cout << attacker->getName() << "�� Ư�� ������ �õ�" << endl;
                    attacker->specialAttack(*defender);
                }
            }
            catch (const runtime_error& e) {
                cout << "! " << e.what() << " Ư�� ���� ����, �⺻ �������� ��ȯ!" << endl;
                attacker->attack(*defender);
            }

            defender->showStatus();
            if (!defender->isAlive()) {
                cout << defender->getName() << "��(��) ���������ϴ�!" << endl;
                return;
            }

            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}
