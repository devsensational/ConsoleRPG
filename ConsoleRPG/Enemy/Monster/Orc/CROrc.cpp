#include "CROrc.h"
#include "../../../Singleton.h"

CROrc::CROrc(int level) {
  name = "Orc";
  health = 50 + level * 7;
  attack = 10 + level * 2;
}