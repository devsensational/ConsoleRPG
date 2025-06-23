#include "Troll.h"

Troll::Troll(int level)
{
  name = "Troll";
  health = 70 + level * 10;
  attack = 8 + level * 3;
}

std::string Troll::GetName() const
{
  return name;
}

int Troll::GetHealth() const
{
  return health;
}

int Troll::GetAttack() const
{
  return attack;
}

void Troll::TakeDamage(int damage)
{
  health = std::max(0, health - damage);
}