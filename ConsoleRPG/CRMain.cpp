// 작성자: 김선호

#include <iostream>
#include <memory>
#include "CRGameSystem.h"

using namespace std;

int main() 
{
    // new를 사용한 이유
    CRGameSystem* GameSystem = new CRGameSystem;
    GameSystem->GameStart();
    // delete 필요하지않나?

    //cout << "=== 텍스트 RPG 게임 시작 ===" << endl;

    //// 1. 캐릭터 생성
    //shared_ptr<CRCharacter> player = make_shared<CRWarrior>("조호영튜터님", 200, 30, 10);
    //cout << "\n플레이어 생성 완료!" << endl;
    //player->showStatus();

    //// 2. 아이템 생성 및 인벤토리에 추가
    ////shared_ptr<CRItem> spRedPotion = make_shared<CRRedPotion>("RedPotion", 20);
    ////shared_ptr<CRItem> spOrangePotion = make_shared<CROrangePotion>("OrangePotion", 35);
    ////shared_ptr<CRItem> spWhitePotion = make_shared<CRWhitePotion>("WhitePotion", 40);
    ////shared_ptr<CRItem> spAttackBoost = make_shared<CRAttackBoost>("AttackBoost", 20);

    ////player->getInventory()->addItem(spRedPotion);
    ////player->getInventory()->addItem(spAttackBoost);

    //player->getInventory()->createItem(1);
    //player->getInventory()->createItem(2);
    //player->getInventory()->createItem(3);
    //


    //cout << "\n아이템이 인벤토리에 추가되었습니다:" << endl;
    //player->getInventory()->showItems();

    //// 3. 아이템 사용
    //cout << "\n첫 번째 아이템 사용 중..." << endl;
    //player->useItem(0); // 빨간물약 힐포션 사용
    //player->showStatus();

    //// 4. 전투 시작
    //cout << "\n전투를 시작합니다!" << endl;
    //CRGameManager::getInstance()->startBattle(player.get());

    //cout << "\n=== 게임 종료 ===" << endl;
    return 0;
}
