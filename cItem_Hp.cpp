#include "Framework.h"

cItem_Hp::cItem_Hp(POINT Pos, int tag, cPlayer* Player, int* Score)
	:cItem(Pos, tag, Player, Score)
{
	m_Sprite = IMAGEMANAGER->AddImage("Item_Life", "./Images/Ingame/Item/Ingame_Life.png");
	m_PlusScore = 500;
}

cItem_Hp::~cItem_Hp()
{
}

void cItem_Hp::GetItem()
{
	if (m_Player->GetHp() == m_Player->GetMaxHp())
		*m_Score += m_PlusScore;
	m_Player->SetHp(m_Player->GetHp() + 1);
}
