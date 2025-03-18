#include <memory>
#include "BattleManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"

unique_ptr<Character> chooseCharacter(const string& prompt) {
    int choice;
    while (true) {
        cout << prompt << endl;
        cout << "1. ���� (Warrior)" << endl;
        cout << "2. ������ (Mage)" << endl;
        cout << "3. ���� (Rogue)" << endl;
        cout << "���� (1~3): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
            continue;
        }
        break;
    }

    switch (choice) {
    case 1:
        return make_unique<Warrior>("����");
    case 2:
        return make_unique<Mage>("������");
    case 3:
        return make_unique<Rogue>("����");

    default:
        cout << "������ �߸��ϼ̾��. ���縦 �����ؿ�" << endl;
        return make_unique<Warrior>("����");
    }
}

int main() {
    BattleManager battleManager;

    while (true) {
        unique_ptr<Character> player = chooseCharacter("����� ĳ���͸� �����ϼ���:");
        unique_ptr<Character> enemy = chooseCharacter("������ ĳ���͸� �����ϼ���:");

        battleManager.startBattle(*player, *enemy);

        if (!player->isAlive()) {
            cout << "���� ����!!" << endl;
            break;
        }
        //�÷��̾ �¸��ϸ� ���ο� ���� �����Ͽ� ���� ���� ����(y / n �Է����� ���� ����)
        char choice;
        cout << "�¸��Ͽ����ϴ�! ������ ����ұ��? (y/n): ";
        cin >> choice;

        if (choice == 'n') {
            cout << "������ �����մϴ�" << endl;
            break;
        }

        player->resetHealth();
    }
    return 0;
}

