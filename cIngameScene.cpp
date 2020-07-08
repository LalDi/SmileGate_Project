#include "Framework.h"

cIngameScene::cIngameScene()
{
	m_Player = nullptr;
	m_GPTime = 0;
}

cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{
	cGameObject* Background;
	cGameObject* UI_Temp;

	Background = new cIngameBackground(POINT{ 0, 0 }, TEXTURE);
	AddObject(Background);

	m_Player = new cPlayer(POINT{ 300, WinSizeY / 2 }, PLAYER);
	AddObject(m_Player);

	UI_Temp = new cUI_Background(POINT{ 20, 20 }, TEXTURE);
	AddObject(UI_Temp);
	UI_Temp = new cUI_PlayerHp(POINT{ 30, 30 }, TEXTURE, m_Player);
	AddObject(UI_Temp);
}

void cIngameScene::Update()
{
	UpdateAllObject();

	if (m_Player->GetIsFire())
		AddObject(m_Player->Fire());

	if (m_Player->GetGracePeriod())
	{
		if (timeGetTime() - m_GPTime >= 2000)
			m_Player->SetGracePeriod(false);
	}

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		if ((*iter)->m_Tag == ENEMY)
		{
			if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
			{
				m_Player->MinusHp(1);
				(*iter)->b_IsLive = false;
			}

			if (((cEnemy*)(*iter))->GetIsFire())
				AddObject(((cEnemy*)(*iter))->Fire());
		}
		if ((*iter)->m_Tag == BULLETP)
		{
			for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
			{
				if ((*iter2)->m_Tag == ENEMY)
				{
					if (RectCrashCheck((*iter)->GetRect(), (*iter2)->GetRect()))
					{
						((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());
						(*iter)->b_IsLive = false;
					}
				}
			}
		}
		if ((*iter)->m_Tag == BULLETE)
		{
			if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
			{
				if (!m_Player->GetGracePeriod())
				{
					m_Player->MinusHp(1);
					m_Player->SetGracePeriod(true);
					m_GPTime = timeGetTime();
				}
				(*iter)->b_IsLive = false;
			}
		}
	}

	// DEBUG Mode
	if (INPUTMANAGER->KeyDown(VK_F11))
		DEBUGMODE = true;
	if (DEBUGMODE)
	{
		cGameObject* Temp;
		if (INPUTMANAGER->KeyDown(VK_F1))
		{
			Temp = new cEnemy1(POINT{ 1600, rand() % WinSizeY }, ENEMY);
			AddObject(Temp);
		}
		if (INPUTMANAGER->KeyDown(VK_F10))
		{
			SCENEMANAGER->ChangeScene("Title");
		}
	}
}

void cIngameScene::Render()
{
	RenderAllObject();
}

void cIngameScene::Release()
{
	RemoveAllObject();
}
