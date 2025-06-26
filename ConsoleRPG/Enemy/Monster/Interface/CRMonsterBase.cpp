<<<<<<< feature/CombatManager
﻿
=======
﻿#include "CRMonsterBase.h"

std::string MonsterBase::GetName() const noexcept
{
    return Name;
}

int MonsterBase::GetCurrentMonsterHealth() const noexcept
{
    return CurrentHealth;
}

int MonsterBase::GetMaxMonsterHealth() const noexcept
{
    return MaxHealth;
}

void MonsterBase::TakeDamage(int value)
{
    CurrentHealth = std::clamp(CurrentHealth - value, 0, MaxHealth);
    cout << "TakeDamage: " << value << endl;
    cout << "CurrentHP: " << CurrentHealth << endl;
}

void MonsterBase::Attack()
{
    Singleton<CREventManager<int>>::GetInstance().Broadcast(EEventType::EET_CharacterTakeDamage, MonsterDamage);
}

MonsterHealthInfo MonsterBase::GetHealthInfo() const noexcept
{
    return { CurrentHealth, MaxHealth };
}

int MonsterBase::GetUniqueId() const
{
    return UniqueId;
}
>>>>>>> dev
