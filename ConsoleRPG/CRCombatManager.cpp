#include "CRCombatManager.h"
#include "Singleton.h"
#include "CREventManager.h"
#include "CRGameMode.h"
#include "Enemy/Monster/Slime/CRSlime.h"
#include "Enemy/Monster/Goblin/CRGoblin.h"

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

	shared_ptr<ICRCombat> MonsterTemp = make_shared<Slime>(InLevel, 1);
	MonsterMap[MonsterTemp->GetUniqueId()] = MonsterTemp;
	MonsterList.push_back(MonsterTemp);
	MonsterCount = MonsterMap.size();
	CombatSequence->push_back(MonsterTemp);
	
	MonsterTemp = make_shared<Slime>(InLevel, 2);
	MonsterMap[MonsterTemp->GetUniqueId()] = MonsterTemp;
	MonsterList.push_back(MonsterTemp);
	MonsterCount = MonsterMap.size();
	//Todo: �� ĳ���Ϳ� ���� �� ���ֵ��� ���� �� CombatSequence�� �߰��ؾ� ��, ���� �ൿ�� ��ġ�� �ִٸ� �ൿ�� ��ġ�� �������� ����
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
			(*CombatSequence)[i]->Attack();
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
	int idx = RandomIndexSelector(MonsterList.size() - 1);

	if (MonsterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	cout << "���͸� ����!" << '\n';
	MonsterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::MonsterAttack(int InDamage)
{
	int idx = RandomIndexSelector(PlayerCharacterList.size() - 1);
	if (PlayerCharacterList[idx]->GetUnitStatus() == EUnitStatus::EUS_Dead) return;

	cout << "�÷��̾ ����!2" << '\n';
	PlayerCharacterList[idx]->TakeDamage(InDamage);
}

void CRCombatManager::PlayerCharacterDead(int UniqueId)
{
	PlayerCount--;
	if (PlayerCount <= 0) CombatLose();
}

void CRCombatManager::MonsterDead(int UniqueId)
{
	MonsterCount--;
	if (MonsterCount <= 0) CombatWin();
}

int CRCombatManager::RandomIndexSelector(int InMaxValue)
{
	random_device rd;                     // �ϵ���� �õ� ��� ���� ������
	mt19937 gen(rd());                    
	uniform_int_distribution<> dist(0, InMaxValue); // [0, InMaxValue] ���� ���� ����

	return dist(gen);
}
