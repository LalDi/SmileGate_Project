#include "Framework.h"

/**
	@fn		cItem(POINT, int, cPlayer*, int*)

	@brief	게임 중 드랍되는 아이템의 기본 기능을 담은 클래스

	@param	Pos		- 오브젝트가 생성되는 위치
	@param	tag		- 오브젝트의 기능을 구분하는 태그.
	@param	Player	- 아이템의 효과를 적용시킬 플레이어의 포인터(주소값)
	@param	Score	- 아이템의 효과를 적용시킬 점수값의 포인터(주소값)
*/
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