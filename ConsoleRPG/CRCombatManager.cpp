#include <Windows.h>

#include "CRCombatManager.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRGameMode.h"
#include "Enemy/Monster//Interface/CRMonsterBase.h"
#include "Enemy/Monster/Slime/CRSlime.h"
#include "Enemy/Monster/Goblin/CRGoblin.h"
#include "Enemy/Monster/Factory/CRMonsterFactory.h"

CRCombatManager::CRCombatManager()
{
	CombatSequence = make_unique<vector<shared_ptr<ICRCombat>>>();

	// �÷��̾� ĳ���� �� �ϳ��� �׾��� �� ȣ��
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterDead, bind(&CRCombatManager::PlayerCharacterDead, this, placeholders::_1));
	// ���� �� �ϳ��� �׾��� �� ȣ��
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterDead, bind(&CRCombatManager::MonsterDead, this, placeholders::_1));
	// �÷��̾ ������ �õ��� �� ȣ��
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_CharacterAttack, bind(&CRCombatManager::PlayerCharacterAttack, this, placeholders::_1));
	// ���Ͱ� ������ �õ��� �� ȣ��
	Singleton<CREventManager<int>>::GetInstance()
		.Subscribe(EEventType::EET_MonsterAttack, bind(&CRCombatManager::MonsterAttack, this, placeholders::_1));
	
}

/*
* ����(Combat)�� �ʱ�ȭ�մϴ�.
* CombatSequence�� ���ֵ��� �߰��մϴ�.
*/
void CRCombatManager::CombatInit(const shared_ptr<ICRCombat> Unit, const int InLevel)
{
	PlayerCharacterMap[Unit->GetUniqueId()] = Unit;
	PlayerCount = PlayerCharacterMap.size();
	PlayerCharacterList.push_back(Unit);
	CombatSequence->push_back(Unit);

	shared_ptr<CRCharacter> Player = dynamic_pointer_cast<CRCharacter>(Unit);
	Singleton<CREventManager<string, int, int>>::GetInstance()
		.Broadcast(EEventType::EET_CharacterCombatStatInit, Player->GetName(), Player->getHealth(), Player->GetMaxHp());

	shared_ptr<MonsterBase> MonsterTemp = CRMonsterFactory::CreateMonster(EMonsterType::EMT_Goblin, InLevel, 0);
	MonsterMap[MonsterTemp->GetUniqueId()] = MonsterTemp;
	MonsterList.push_back(MonsterTemp);
	MonsterCount = MonsterMap.size();
	CombatSequence->push_back(MonsterTemp);

	Singleton<CREventManager<string, int, int>>::GetInstance()
		.Broadcast(EEventType::EET_MonsterCombatStatInit, MonsterTemp->GetName(), MonsterTemp->GetCurrentMonsterHealth(), MonsterTemp->GetMaxMonsterHealth());

	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatApply);
}

/*
* CombatSequence�� ������ ���� ��� ������ ������ �����մϴ�.
* ICRCombat�� ���� Attack()�� ȣ���մϴ�.
*
*/
void CRCombatManager::CombatStart()
{
	if (CombatSequence->empty()) return;

	for (int i = 0; i < CombatSequence->size(); i++)
	{
		//cout << i << "��° �ൿ���" << '\n';
		if ((*CombatSequence)[i]->GetUnitStatus() == EUnitStatus::EUS_Alive)
		{
			//cout << i << "��° ���ݽõ�!" << '\n';
			(*CombatSequence)[i]->Act();
			Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatApply);
			Sleep(500);
			if (PlayerCount <= 0) CombatLose();
			if (MonsterCount <= 0) CombatWin();
		}

	}

}

/*
* Combat�� �ֱⰡ ��� ������� �� ȣ��˴ϴ�.
* CombatSquence�� �ʱ�ȭ�մϴ�.
*/
void CRCombatManager::CombatEnd()
{
	//Singleton<CREventManager<>>::GetInstance().Broadcast("CombatEnd");
	CombatSequence->clear();


	PlayerCharacterMap.clear();
	PlayerCharacterList.clear();
	MonsterMap.clear();
	MonsterList.clear();

}

void CRCombatManager::CombatWin()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatWin);
	CombatEnd();
}

void CRCombatManager::CombatLose()
{
	Singleton<CREventManager<>>::GetInstance().Broadcast(EEventType::EET_CombatLose);
	CombatEnd();
}

void CRCombatManager::PlayerCharacterAttack(int InDamage)
{
	int idx = 0;

	if (MonsterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	//cout << "���͸� ����!" << '\n';
	MonsterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::MonsterAttack(int InDamage)
{
	int idx = 0;
	if (PlayerCharacterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	//cout << "�÷��̾ ����!2" << '\n';
	PlayerCharacterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::PlayerCharacterDead(int UniqueId)
{
	PlayerCount--;
}

void CRCombatManager::MonsterDead(int UniqueId)
{
	MonsterCount--;
}
