#pragma once

#include <functional>
#include "../Interface/CRMonsterBase.h"

using MonsterCreator = std::function<std::shared_ptr<MonsterBase>(int level, int uniqueId)>;

struct LevelRange {
  int minLevel;
  int maxLevel;
  MonsterCreator creator;
};