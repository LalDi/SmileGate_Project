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
	m_Sprite = IMAGEMANAGER->AddImage("Player", "./Images/Ingame/Ingame_Character_Player.png");

	m_PlayerState = PlayerState::Wheel_of_Fortune;

	SetPlayerState();
	m_Hp = m_MaxHp;

	m_MaxBomb = 5;
	m_Bomb = 3;

	m_MaxPower = 5;
	m_Power = 0;

	m_Speed = 400;
	m_AttackSpeed = 10;

	m_FireTime = timeGetTime();

	//m_Scale = 0.7f;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	if (m_Hp <= 0)	// 현재 체력이 0 이하라면
		b_IsLive = false;	// 플레이어 사망

	SetRect();	// Rect값 설정

	// 플레이어 이동
	if (INPUTMANAGER->KeyPress(VK_W) && m_Pos.y >= 0)
		m_Pos.y -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_A) && m_Pos.x >= 0)
		m_Pos.x -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
		m_Pos.y += m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
		m_Pos.x += m_Speed * DXUTGetElapsedTime();

	// 플레이어 공격 설정
	// (현재 시간) - (마지막 총알 발사 시간) > (딜레이(초 * 1000)) / 공격 속도
	if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
	{
		b_Fire = true;	// 총알을 발사하고
		m_FireTime = timeGetTime();	// 마지막 총알 발사 시간에 현재 시간 대입
	}

	if (INPUTMANAGER->KeyPress(VK_SHIFT))
		m_Speed = 200;
	if (INPUTMANAGER->KeyUp(VK_SHIFT))
		m_Speed = 400;
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
	Temp = new cBullet(Pos, BULLETP, m_Damage);
	b_Fire = false;
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
		m_MaxHp = 5;
		m_Damage = 2;
		m_BombDamage = 10;
		break;
	case PlayerState::Judgement:
		m_MaxHp = 7;
		m_Damage = 1;
		m_BombDamage = 8;
		break;
	case PlayerState::The_Sun:
		m_MaxHp = 3;
		m_Damage = 4;
		m_BombDamage = 15;
		break;
	default:
		break;
	}
	if (m_Hp > m_MaxHp)
		m_Hp = m_MaxHp;
}
