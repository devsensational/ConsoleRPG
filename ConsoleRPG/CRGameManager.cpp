#include "CRGameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CRGameManager* CRGameManager::instance = nullptr;

CRGameManager* CRGameManager::getInstance() {
    if (instance == nullptr) {
        instance = new CRGameManager();
    }
    return instance;
}

void CRGameManager::startGame() {
    cout << "������ �����մϴ�!" << endl;
}

void CRGameManager::showCharacterStatus(CRCharacter* character) {
    character->showStatus();
}

void CRGameManager::startBattle(CRCharacter* character) {
    cout << "������ ���۵Ǿ����ϴ�!" << endl;

    // ���� ���� ����
    srand(time(0));
    string monsterName = "Goblin";
    int monsterHealth = rand() % 10 + 20;
    int monsterAttack = rand() % 5 + 5;

    CRCharacter* monster = new CRCharacter(monsterName, monsterHealth, monsterAttack);

    while (character->getHealth() > 0 && monster->getHealth() > 0) {
        battleRound(character, monster);
    }

    if (character->getHealth() > 0) {
        cout << character->getName() << "��(��) �¸��߽��ϴ�!" << endl;
    }
    else {
        cout << character->getName() << "��(��) ����߽��ϴ�." << endl;
    }
}

void CRGameManager::battleRound(CRCharacter* character, CRCharacter* monster) {
    // �÷��̾� ����
    monster->takeDamage(character->getAttack());
    cout << character->getName() << "��(��) " << monster->getName() << "��(��) �����մϴ�!" << endl;
    cout << monster->getName() << " ü��: " << monster->getHealth() << endl;

    if (monster->getHealth() <= 0) {
        cout << monster->getName() << " óġ!" << endl;
        return;
    }

    // ���� ����
    character->takeDamage(monster->getAttack());
    cout << monster->getName() << "��(��) " << character->getName() << "��(��) �����մϴ�!" << endl;
    cout << character->getName() << " ü��: " << character->getHealth() << endl;
}
