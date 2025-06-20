#include "CRDamageBoost.h"
#include "CRCharacterBase.h"
#include "CRConsoleRenderer.h"
#include "ConsoleRPG.h"

using namespace std;

string CRDamageBoost::GetName() const
{
	return Name;
}

void CRDamageBoost::Use(CRCharacterBase* character)
{
	if (character)
	{
		character->Boost(DamageIncrease);
	}
		
}