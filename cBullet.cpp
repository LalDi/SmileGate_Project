#include "Framework.h"

/**
	@fn		cBullet(POINT, int, int, int)

	@brief	�÷��̾�� ���ʹ̰� �߻��ϴ� �Ѿ�.

	@param	Pos		- ������Ʈ�� �����Ǵ� ��ġ
	@param	tag		- ������Ʈ�� ����� �����ϴ� �±�. �� Ŭ���������� BULLETP, BULLETE�� �����Ͽ� ����Ѵ�. 
	@param	Damage	- �Ѿ��� ���� ������. �ε��� ����� ü���� ���ҽ�Ű�� ��
	@param	Angle	- �Ѿ��� ���ư��� ����. 0�� ���, ���������� ���ư�
*/
cBullet::cBullet(POINT Pos, int tag, int Damage, int Angle, float Speed)
	:cGameObject(Pos, tag)
{
	if (tag == BULLETP)
		m_Sprite = IMAGEMANAGER->AddImage("BulletP", "./Images/Ingame/Ingame_Bullet_Player.png");
	if (tag == BULLETE)
		m_Sprite = IMAGEMANAGER->AddImage("BulletE", "./Images/Ingame/Ingame_Bullet_Enemy.png");

	m_Damage = Damage;
	m_Angle = Angle;
	m_Speed = Speed;
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
	m_Pos.y += m_Speed * sin(D3DXToRadian(m_Angle)) * DXUTGetElapsedTime();
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
