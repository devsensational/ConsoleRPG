#include <iostream>
#include <memory>
#include "CRWarrior.h"
#include "CRMage.h"
#include "CRRogue.h"
#include "CRHealPotion.h"
#include "CRAttackBoost.h"
#include "CRGameManager.h"

using namespace std;

int main() 
{
    cout << "=== 텍스트 RPG 게임 시작 ===" << endl;

    // 1. 캐릭터 생성
    shared_ptr<CRCharacter> player = make_shared<CRWarrior>("조호영튜터님", 200, 30, 10);
    cout << "\n플레이어 생성 완료!" << endl;
    player->showStatus();

    // 2. 아이템 생성 및 인벤토리에 추가
    shared_ptr<CRItem> potion = make_shared<CRHealPotion>();
    shared_ptr<CRItem> boost = make_shared<CRAttackBoost>();

    player->getInventory()->addItem(potion);
    player->getInventory()->addItem(boost);

    cout << "\n아이템이 인벤토리에 추가되었습니다:" << endl;
    player->getInventory()->showItems();

    // 3. 아이템 사용
    cout << "\n첫 번째 아이템 사용 중..." << endl;
    player->useItem(0); // 힐포션 사용
    player->showStatus();

    // 4. 전투 시작
    cout << "\n전투를 시작합니다!" << endl;
    CRGameManager::getInstance()->startBattle(player.get());

    cout << "\n=== 게임 종료 ===" << endl;
    return 0;
}
