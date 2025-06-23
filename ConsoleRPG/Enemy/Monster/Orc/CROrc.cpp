#include "CROrc.h"
#include "../../../Singleton.h"

CROrc::CROrc(int level) {
  name = "Orc";
  CurrentHealth = 50 + level * 7;
  MonsterDamage = 10 + level * 2;
}