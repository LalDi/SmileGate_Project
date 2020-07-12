#include "Framework.h"

cItem_Bomb::cItem_Bomb(POINT Pos, int tag, cPlayer* Player, int* Score)
	:cItem(Pos, tag, Player, Score)
{
	m_Sprite = IMAGEMANAGER->AddImage("Item_Bomb", "./Images/Ingame/Item/Ingame_Bomb.png");

	m_PlusScore = 500;
}

cItem_Bomb::~cItem_Bomb()
{
}

void cItem_Bomb::GetItem()
{
	if (m_Player->GetBomb() == m_Player->GetMaxBomb())
		m_Score += m_PlusScore;
	m_Player->SetBomb(m_Player->GetBomb() + 1);
}
