#include "Framework.h"

cPlayer::cPlayer(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Player", "./Images/Ingame/Ingame_Character_Player.png");

	m_PlayerState = PlayerState::Wheel_of_Fortune;
	SetPlayerState();
	m_Hp = m_MaxHp;
	m_Bomb = 0;
	m_Speed = 450;
	m_AttackSpeed = 10;

	m_FireTime = timeGetTime();
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	if (m_Hp <= 0)
		b_IsLive = false;

	SetRect();

	if (INPUTMANAGER->KeyPress(VK_W) && m_Pos.y >= 0)
		m_Pos.y -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_A) && m_Pos.x >= 0)
		m_Pos.x -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
		m_Pos.y += m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
		m_Pos.x += m_Speed * DXUTGetElapsedTime();

	if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
	{
		b_Fire = true;
		m_FireTime = timeGetTime();
	}
}

void cPlayer::Render()
{
	if (b_GracePeriod)
		m_Sprite->CenterRender(m_Pos, m_Scale, 0, D3DCOLOR_XRGB(255, 100, 100));
	else
		m_Sprite->CenterRender(m_Pos);
}

cGameObject* cPlayer::Fire()
{
	cGameObject* Temp;
	POINT Pos = { m_Pos.x + 80, m_Pos.y };
	Temp = new cBullet(Pos, BULLETP, m_Damage);
	b_Fire = false;
	return Temp;
}

void cPlayer::SetPlayerState()
{
	if (m_PlayerState == PlayerState::Wheel_of_Fortune)
	{
		m_MaxHp = 5;
		m_Damage = 2;
		m_BombDamage = 10;
	}
	else if (m_PlayerState == PlayerState::Judgement)
	{
		m_MaxHp = 7;
		m_Damage = 1;
		m_BombDamage = 8;
	}
	else if (m_PlayerState == PlayerState::The_Sun)
	{
		m_MaxHp = 3;
		m_Damage = 4;
		m_BombDamage = 15;
	}
	if (m_Hp > m_MaxHp)
		m_Hp = m_MaxHp;
}
