#include "CRCharacter.h"
#include "ConsoleRPG.h"
#include "Singleton.h"
#include "CREventManager.h"

#include <iostream>
#include <algorithm>


using namespace std;



CRCharacter::CRCharacter(string name, int health, int attack, const int InUniqueId)
    : name(name), iHealth(health), iAttack(attack), iMaxHealth(health), iLevel(1), iExperience(0), UniqueId(InUniqueId),
    spInventory(make_shared<CRInventory>())
{
    // ĳ���� �����ڿ��� inventory shared_ptr��ü �ʱ�ȭ.
    //EventIds.push_back(Singleton<CREventManager<int>>::GetInstance()
    //    .Subscribe(EEventType::EET_CharacterTakeDamage, bind(&CRCharacter::TakeDamage, this, placeholders::_1)));
    Status = EUnitStatus::EUS_Alive;


}



// �κ��丮�� �������� �Լ�
shared_ptr<CRInventory>CRCharacter::getInventory()
{
    return spInventory;
}
// ĳ���Ͱ� ���° �ε����� �ִ� �������� ����Ұ������� ���� �Լ�
void CRCharacter::useItem(int index)
{
    spInventory->useItem(index, this);
}



void CRCharacter::TakeDamage(int damage) 
{
    iHealth = clamp(iHealth - damage, 0, iMaxHealth);
    if (iHealth <= 0) Dead();
}

// HealPosition ����ؼ� 50 healȸ��
void CRCharacter::takeHealPosition(int heal)
{
    iHealth += heal;
    if (iHealth < 0) iHealth = 0;
}

void CRCharacter::takeAttackBoost(int attack)
{
    iAttack += attack;
    if (iAttack < 0) iAttack = 0;
}

void CRCharacter::levelUp() 
{
    if (iLevel < 10) 
    {
        iLevel++;
        iMaxHealth += iLevel * 20;
        iAttack += iLevel * 5;
        iHealth = iMaxHealth;  // ������ �� ü�� ȸ��
        cout << name << " ������! ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
    }
}

void CRCharacter::showStatus() 
{
    cout << name << " - ����: " << iLevel << ", ü��: " << iHealth << ", ���ݷ�: " << iAttack << endl;
}

void CRCharacter::Dead()
{
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterDead, UniqueId);
    //Singleton<CREventManager<int>>::GetInstance().Unsubscribe(EEventType::EET_CharacterTakeDamage, EventIds[0]);
    Status = EUnitStatus::EUS_Dead;
}

void CRCharacter::Attack()
{
    //Todo: CombatSystem�� �ִ� �̺�Ʈ�� ȣ���ؼ� �����ϴ� ������� ������ ��
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterAttack, iAttack);
}