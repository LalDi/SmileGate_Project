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
	SetRect();	// Rect�� ����

	// �÷��̾� �浹 ���� ��ȭ
	m_Rect.left + 5;
	m_Rect.right - 5;
	m_Rect.top + 20;
	m_Rect.bottom - 10;

	// �÷��̾� ����
	if (b_PlayerControl)
	{
		// �÷��̾� �̵�
		if (INPUTMANAGER->KeyPress(VK_W) && m_Pos.y >= 0)
			m_Pos.y -= m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_A) && m_Pos.x >= 0)
			m_Pos.x -= m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_S) && m_Pos.y <= WinSizeY)
			m_Pos.y += m_Speed * DXUTGetElapsedTime();
		if (INPUTMANAGER->KeyPress(VK_D) && m_Pos.x <= WinSizeX)
			m_Pos.x += m_Speed * DXUTGetElapsedTime();

		// �÷��̾� ����
		if (INPUTMANAGER->BtnPress(LEFTCLICK))
		{
			// �÷��̾� ���� ����
			// (���� �ð�) - (������ �Ѿ� �߻� �ð�) > (������(�� * 1000)) / ���� �ӵ�
			if (timeGetTime() - m_FireTime > 1000 / m_AttackSpeed)
			{
				b_Fire = true;	// �Ѿ��� �߻��ϰ�
				m_FireTime = timeGetTime();	// ������ �Ѿ� �߻� �ð��� ���� �ð� ����
			}
		}
		if (INPUTMANAGER->BtnDown(RIGHTCLICK))
		{
			// ��ź �߻�
			if (m_Bomb > 0)
			{
				b_Bomb = true;
				m_Bomb--;
			}
		}
		if (INPUTMANAGER->KeyDown(VK_CONTROL))
		{
			// �÷��̾� �Ӽ� ����
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

	@brief	�÷��̾��� �Ӽ��� ���� ������ �缳���ϴ� �Լ�
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
