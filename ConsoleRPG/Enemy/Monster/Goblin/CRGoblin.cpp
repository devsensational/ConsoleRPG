#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level, int uniqueId) : MonsterBase("Goblin", uniqueId) 
{
	CurrentHealth = 30 + level * 20;
	MonsterDamage = 5 + level * 5;
	MaxHealth = CurrentHealth;
	Status = EUnitStatus::EUS_Alive;
}
