#include "CRSlime.h"
#include "../../../Singleton.h"

CRSlime::CRSlime(int level)
{
  name = "Troll";
  health = 70 + level * 10;
  attack = 8 + level * 3;
}