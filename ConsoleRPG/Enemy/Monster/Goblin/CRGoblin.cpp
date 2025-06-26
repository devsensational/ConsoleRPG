#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level, int uniqueId) : MonsterBase("고블린", uniqueId) 
{
	CurrentHealth = 30 + level * 5;
	MonsterDamage = 5 + level;
	MaxHealth = CurrentHealth;
	Status = EUnitStatus::EUS_Alive;
}
