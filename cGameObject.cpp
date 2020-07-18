#include "Framework.h"

cGameObject::cGameObject(POINT Pos, int tag)
{
	m_Tag = tag;

	m_Pos = Pos;

	m_Scale = 1;

	b_IsLive = true;
}

cGameObject::~cGameObject()
{
}

/**
	@fn		SetRect()

	@brief	오브젝트의 위치 및 크기를 Rect의 형식으로 저장.

	@remark	오브젝트의 위치는 변동될 수 있으므로, Rect값을 사용하는 오브젝트는 이 함수를 매 프레임 마다 실행시켜야 함.
*/
void cGameObject::SetRect()
{
	LONG Width = m_Sprite->info.Width * m_Scale / 2;
	LONG Height = m_Sprite->info.Height * m_Scale / 2;
	m_Rect = { m_Pos.x - Width, m_Pos.y - Height, m_Pos.x + Width, m_Pos.y + Height };
}
