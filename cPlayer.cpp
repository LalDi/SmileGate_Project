#include "Framework.h"

/**
	@fn		cPlayer(POINT, int)

	@brief	게임의 주인공

	@param	Pos		- 오브젝트가 생성되는 위치
	@param	tag		- 오브젝트의 기능을 구분하는 태그. 이 클래스에서는 BULLETP, BULLETE로 구분하여 사용한다.
*/
cPlayer::cPlayer(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_PlayerState = PlayerState::Wheel_of_Fortune;

	SetPlayerState();
	m_Hp = m_MaxHp;

	m_MaxBomb = 5;
	m_Bomb = 3;

	m_MaxPower = 500;
	m_Power = 100;

	m_Speed = 500;
	m_AttackSpeed = 10;

	m_FireTime = timeGetTime();

	b_GracePeriod = false;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	SetRect();	// Rect값 설정

	// 플레이어 충돌 판정 완화
	m_Rect.left + 5;
	m_Rect.right - 5;
	m_Rect.top + 20;
	m_Rect.bottom - 10;

	// 플레이어 조작
	if (b_PlayerControl)
	{
		// 플레이어 이동
		if (INPUTMANAGER->KeyPress(VK_W) && m_Pos.y >= 0)
			m_Pos.y -= m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_A) && m_Pos.x >= 0)
			m_Pos.x -= m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
			m_Pos.y += m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
			m_Pos.x += m_Speed * DXUTGetElapsedTime();

		// 플레이어 조작
		if (INPUTMANAGER->BtnPress(LEFTCLICK))
		{
			// 플레이어 공격 설정
			// (현재 시간) - (마지막 총알 발사 시간) > (딜레이(초 * 1000)) / 공격 속도
			if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
			{
				b_Fire = true;	// 총알을 발사하고
				m_FireTime = timeGetTime();	// 마지막 총알 발사 시간에 현재 시간 대입
			}
		}
		if (INPUTMANAGER->BtnDown(RIGHTCLICK))
		{
			// 폭탄 발사
			if (m_Bomb > 0)
			{
				b_Bomb = true;
				m_Bomb--;
			}
		}
		if (INPUTMANAGER->KeyDown(VK_CONTROL))
		{
			// 플레이어 속성 변경
			if (m_Power == m_MaxPower)
			{
				b_Change = true;
				m_Power = 0;
			}
		}
		if (INPUTMANAGER->KeyPress(VK_SHIFT))
			m_Speed = 250;
		if (INPUTMANAGER->KeyUp(VK_SHIFT))
			m_Speed = 500;
	}
}

void cPlayer::Render()
{
	if (b_GracePeriod) // 피격 당해 무적 대기 시간인 경우
		m_Sprite->CenterRender(m_Pos, m_Scale, 0, D3DCOLOR_XRGB(255, 100, 100)); // 플레이어를 빨갛게 출력
	else
		m_Sprite->CenterRender(m_Pos, m_Scale, 0);
}

/**
	@fn		Fire()

	@brief	플레이어가 발사하는 총알의 데이터를 담은 함수
	@remark	총알을 플레이어보다 살짝 앞에 생성하여 그 데이터를 반환하는 함수
*/
cGameObject* cPlayer::Fire()
{
	cGameObject* Temp;
	POINT Pos = { m_Pos.x + 80, m_Pos.y };
	Temp = new cBullet(Pos, BULLETP, m_Damage + m_Power / 100);
	b_Fire = false;
	SOUNDMANAGER->Play("ShootP", SE);
	return Temp;
}

cGameObject* cPlayer::Bomb()
{
	cGameObject* Temp;
	Temp = new cBomb(POINT{ 0,0 }, TEXTURE);
	b_Bomb = false;
	return Temp;
}

/**
	@fn		SetPlayerState()

	@brief	플레이어의 속성에 따라 스텟을 재설정하는 함수
*/
void cPlayer::SetPlayerState()
{
	switch (m_PlayerState)
	{
	case PlayerState::Wheel_of_Fortune:
		m_Sprite = IMAGEMANAGER->AddImage("Player_1", "./Images/Ingame/Ingame_Character_Player-1.png");
		m_MaxHp = 5;
		m_Damage = 3;
		m_BombDamage = 15;
		break;
	case PlayerState::Judgement:
		m_Sprite = IMAGEMANAGER->AddImage("Player_2", "./Images/Ingame/Ingame_Character_Player-2.png");
		m_MaxHp = 7;
		m_Damage = 2;
		m_BombDamage = 10;
		break;
	case PlayerState::The_Sun:
		m_Sprite = IMAGEMANAGER->AddImage("Player_3", "./Images/Ingame/Ingame_Character_Player-3.png");
		m_MaxHp = 3;
		m_Damage = 5;
		m_BombDamage = 20;
		break;
	default:
		break;
	}
	m_Hp = m_MaxHp;
}
