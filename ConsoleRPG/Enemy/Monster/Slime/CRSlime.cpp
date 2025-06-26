#include "CRSlime.h"

<<<<<<< feature/CombatManager
Slime::Slime(int level, int InUniqueId)
=======
Slime::Slime(int level, int uniqueId)
>>>>>>> dev
{
  Name = "Slime";
  UniqueId = InUniqueId;
  CurrentHealth = 70 + level * 10;
  MaxHealth = CurrentHealth;
  MonsterDamage = 8 + level * 3;
<<<<<<< feature/CombatManager
}
=======
  MonsterAttribute = EMonsterAttribute::EMA_Poison;
}
>>>>>>> dev
