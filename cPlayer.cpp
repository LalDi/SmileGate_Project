#include "Framework.h"

/**
	@fn		cPlayer(POINT, int)

	@brief	������ ���ΰ�

	@param	Pos		- ������Ʈ�� �����Ǵ� ��ġ
	@param	tag		- ������Ʈ�� ����� �����ϴ� �±�. �� Ŭ���������� BULLETP, BULLETE�� �����Ͽ� ����Ѵ�.
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
	if (m_Hp <= 0)	// ���� ü���� 0 ���϶��
		b_IsLive = false;	// �÷��̾� ���

	SetRect();	// Rect�� ����

	// �÷��̾� �̵�
	if (INPUTMANAGER->KeyPress(VK_W) && m_Pos.y >= 0)
		m_Pos.y -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_A) && m_Pos.x >= 0)
		m_Pos.x -= m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
		m_Pos.y += m_Speed * DXUTGetElapsedTime();
	if (INPUTMANAGER->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
		m_Pos.x += m_Speed * DXUTGetElapsedTime();

	// �÷��̾� ���� ����
	// (���� �ð�) - (������ �Ѿ� �߻� �ð�) > (������(�� * 1000)) / ���� �ӵ�
	if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
	{
		b_Fire = true;	// �Ѿ��� �߻��ϰ�
		m_FireTime = timeGetTime();	// ������ �Ѿ� �߻� �ð��� ���� �ð� ����
	}

	if (INPUTMANAGER->KeyPress(VK_SHIFT))
		m_Speed = 200;
	if (INPUTMANAGER->KeyUp(VK_SHIFT))
		m_Speed = 400;
}

void cPlayer::Render()
{
	if (b_GracePeriod) // �ǰ� ���� ���� ��� �ð��� ���
		m_Sprite->CenterRender(m_Pos, m_Scale, 0, D3DCOLOR_XRGB(255, 100, 100)); // �÷��̾ ������ ���
	else
		m_Sprite->CenterRender(m_Pos, m_Scale, 0);
}

/**
	@fn		Fire()

	@brief	�÷��̾ �߻��ϴ� �Ѿ��� �����͸� ���� �Լ�
	@remark	�Ѿ��� �÷��̾�� ��¦ �տ� �����Ͽ� �� �����͸� ��ȯ�ϴ� �Լ�
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

	@brief	�÷��̾��� �Ӽ��� ���� ������ �缳���ϴ� �Լ�
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
