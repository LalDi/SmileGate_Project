#include "Framework.h"

cItem_Power::cItem_Power(POINT Pos, int tag, cPlayer* Player, int* Score)
	:cItem(Pos, tag, Player, Score)
{
	m_Sprite = IMAGEMANAGER->AddImage("Item_Power", "./Images/Ingame/Item/Ingame_Power.png");

	m_PlusScore = 500;
	m_PlusPower = NULL;
}

cItem_Power::~cItem_Power()
{
}

void cItem_Power::GetItem()
{
	if (m_Player->GetPower() == m_Player->GetMaxPower())
		*m_Score += m_PlusScore;
	m_Player->SetPower(m_Player->GetPower() + m_PlusPower);
}
