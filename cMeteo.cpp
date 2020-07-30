#include "Framework.h"

cMeteo::cMeteo(POINT Pos, int tag, int Angle, float Speed)
	:cBullet(Pos, tag, 1, Angle, Speed)
{
	m_Sprite = IMAGEMANAGER->AddImage("Meteo", "./Images/Ingame/Ingame_Bullet_Meteo.png");
	m_Warning = IMAGEMANAGER->AddImage("Meteo_Warning", "./Images/Ingame/Ingame_Warning_meteo.png");
	b_IsShoot = false;

	m_Radius = m_Sprite->info.Height / 2;
	m_Timer.Init();
}

cMeteo::~cMeteo()
{
}

void cMeteo::Update()
{
	m_Timer.Update();
	if (m_Timer.Time(3) && !b_IsShoot)
	{
		b_IsShoot = true;
		SOUNDMANAGER->Play("Meteo", SE);
	}

	if (b_IsShoot)
	{
		m_Pos.x += m_Speed * cos(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
		m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();

		if (CheckOutMap())
			b_IsLive = false;
	}
}

void cMeteo::Render()	
{
	if (b_IsShoot)
		m_Sprite->CenterRender(m_Pos, m_Angle);
	else
		m_Warning->CenterRender(m_Pos, m_Angle);
}
