#include "Framework.h"

cItem::cItem(POINT Pos, int tag, cPlayer* Player, int* Score)
	:cGameObject(Pos, tag)
{
	m_Player = Player;
	m_Speed = 250;
	m_Score = Score;
}

cItem::~cItem()
{
}

void cItem::Update()
{
	SetRect();

	m_Pos.x -= m_Speed * DXUTGetElapsedTime();

	if (Math::RectCrashCheck(m_Rect, m_Player->GetRect()))
	{
		GetItem();
		b_IsLive = false;
	}

	if (CheckOutMap())
		b_IsLive = false;
}

void cItem::Render()
{
	m_Sprite->Render(m_Pos);
}

bool cItem::CheckOutMap()
{
	bool temp;
	int x, y;
	x = m_Sprite->info.Width;
	y = m_Sprite->info.Height;
	temp = m_Pos.x < -x || m_Pos.x > WinSizeX + x || m_Pos.y < -y || m_Pos.y > WinSizeY + y;
	return temp;
}