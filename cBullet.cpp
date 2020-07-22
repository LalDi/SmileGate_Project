#include "Framework.h"

/**
	@fn		cBullet(POINT, int, int, int)

	@brief	플레이어와 에너미가 발사하는 총알.

	@param	Pos		- 오브젝트가 생성되는 위치
	@param	tag		- 오브젝트의 기능을 구분하는 태그. 이 클래스에서는 BULLETP, BULLETE로 구분하여 사용한다. 
	@param	Damage	- 총알이 갖는 데미지. 부딪힌 대상의 체력을 감소시키는 양
	@param	Angle	- 총알이 나아가는 방향. 0일 경우, 오른쪽으로 나아감
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
