#include <memory>
#include "BattleManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

unique_ptr<Character> chooseCharacter(const string& prompt) {
    int choice;
    while (true) {
        cout << prompt << endl;
        cout << "1. 전사 (Warrior)" << endl;
        cout << "2. 마법사 (Mage)" << endl;
        cout << "3. 도적 (Rogue)" << endl;
        cout << "선택 (1~3): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            continue;
        }
        break;
    }

    switch (choice) {
    case 1:
        return make_unique<Warrior>("전사");
    case 2:
        return make_unique<Mage>("마법사");
    case 3:
        return make_unique<Rogue>("도적");

    default:
        cout << "선택을 잘못하셨어요. 전사를 선택해요" << endl;
        return make_unique<Warrior>("전사");
    }
}

int main() {
    BattleManager battleManager;

    while (true) {
        unique_ptr<Character> player = chooseCharacter("당신의 캐릭터를 선택하세요:");
        unique_ptr<Character> enemy = chooseCharacter("상대방의 캐릭터를 선택하세요:");

        battleManager.startBattle(*player, *enemy);

        if (!player->isAlive()) {
            cout << "게임 종료!!" << endl;
            break;
        }
        //플레이어가 승리하면 새로운 적을 선택하여 전투 진행 가능(y / n 입력으로 선택 가능)
        char choice;
        cout << "승리하였습니다! 전투를 계속할까요? (y/n): ";
        cin >> choice;

        if (choice == 'n') {
            cout << "게임을 종료합니다" << endl;
            break;
        }

        player->resetHealth();
    }
    return 0;
}

