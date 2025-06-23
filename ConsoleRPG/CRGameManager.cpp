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
    cout << "게임을 시작합니다!" << endl;
}

void CRGameManager::showCharacterStatus(CRCharacter* character) {
    character->showStatus();
}

void CRGameManager::startBattle(CRCharacter* character) {
    cout << "전투가 시작되었습니다!" << endl;

    // 몬스터 랜덤 생성
    srand(time(0));
    string monsterName = "Goblin";
    int monsterHealth = rand() % 10 + 20;
    int monsterAttack = rand() % 5 + 5;

    CRCharacter* monster = new CRCharacter(monsterName, monsterHealth, monsterAttack);

    while (character->getHealth() > 0 && monster->getHealth() > 0) {
        battleRound(character, monster);
    }

    if (character->getHealth() > 0) {
        cout << character->getName() << "이(가) 승리했습니다!" << endl;
    }
    else {
        cout << character->getName() << "이(가) 사망했습니다." << endl;
    }
}

void CRGameManager::battleRound(CRCharacter* character, CRCharacter* monster) {
    // 플레이어 공격
    monster->takeDamage(character->getAttack());
    cout << character->getName() << "이(가) " << monster->getName() << "을(를) 공격합니다!" << endl;
    cout << monster->getName() << " 체력: " << monster->getHealth() << endl;

    if (monster->getHealth() <= 0) {
        cout << monster->getName() << " 처치!" << endl;
        return;
    }

    // 몬스터 공격
    character->takeDamage(monster->getAttack());
    cout << monster->getName() << "이(가) " << character->getName() << "을(를) 공격합니다!" << endl;
    cout << character->getName() << " 체력: " << character->getHealth() << endl;
}
