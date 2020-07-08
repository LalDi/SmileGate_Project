#include "Framework.h"

cBullet::cBullet(POINT Pos, int tag, int Damage, int Angle)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Bullet", "./Images/Ingame/Ingame_Bullet.png");

	m_Damage = Damage;
	m_Angle = Angle;
	m_Speed = 1500;
}

cBullet::~cBullet()
{
}

void cBullet::Update()
{
	SetRect();

	if (CheckOutMap())
		b_IsLive = false;

	m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
	m_Pos.y -= m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
}

void cBullet::Render()
{
	m_Sprite->CenterRender(m_Pos, m_Angle);
}

bool cBullet::CheckOutMap()
{
	bool temp;
	int x, y;
	x = m_Sprite->info.Width;
	y = m_Sprite->info.Height;
	temp = m_Pos.x < -x || m_Pos.x > WinSizeX + x || m_Pos.y < -y || m_Pos.y > WinSizeY + y;
	return temp;
}
