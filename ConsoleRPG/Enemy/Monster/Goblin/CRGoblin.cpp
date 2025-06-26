#include "CRGoblin.h"
#include "../../../Singleton.h"

Goblin::Goblin(int level, int uniqueId) : MonsterBase("고블린", uniqueId) 
{
	CurrentHealth = 70 + level * 10;
	MonsterDamage = 8 + level * 3;
	MaxHealth = CurrentHealth;
	Status = EUnitStatus::EUS_Alive;
}
