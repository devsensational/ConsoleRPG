#include "CRHealthPotion.h"
#include "CRCharacterBase.h"
#include "CRConsoleRenderer.h"
#include "ConsoleRPG.h"

using namespace std;

string CRHealthPotion::GetName() const
{
	return Name;
}

void CRHealthPotion::Use(CRCharacterBase* character)
{
	if (character)
	{
		character->Heal(HealthRestore);
	}
	
}