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

void cGameObject::SetRect()
{
	LONG Width = m_Sprite->info.Width * m_Scale / 2;
	LONG Height = m_Sprite->info.Height * m_Scale / 2;
	m_Rect = { m_Pos.x - Width, m_Pos.y - Height, m_Pos.x + Width, m_Pos.y + Height };
}
