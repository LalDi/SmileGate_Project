#include "Framework.h"

cIngameScene::cIngameScene()
{
	m_Player = nullptr;
	m_GPTime = 0;
	m_Score = 0;
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

	UI_Temp = new cUI_Background(POINT{ 20, 10 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Character(POINT{ 50, 40 }, UI);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_PlayerHp(POINT{ 105, 40 }, UI, m_Player);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_Bomb(POINT{ 180, 775 }, UI, m_Player);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_Taro(POINT{ 20, 720 }, UI, m_Player);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Score(POINT{ 1400, 30 }, UI, &m_Score);
	AddObject(UI_Temp);
}

void cIngameScene::Update()
{
	if (m_Player->GetIsFire())			// �÷��̾ �Ѿ��� �߻��ϴ� Ÿ�ֿ̹�
		AddObject(m_Player->Fire());	// �÷��̾��� �Ѿ��� ������Ʈ�� �߰��Ѵ�.

	if (m_Player->GetGracePeriod())		// �÷��̾ �����ð��� ��
	{
		if (timeGetTime() - m_GPTime >= 2000)	// �÷��̾��� ���� �ð��� �����ٸ�
			m_Player->SetGracePeriod(false);	// �÷��̾��� ������ ������Ų��.
	}

	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
	{
		// �÷��̾��� �Ѿ�
		if ((*iter)->m_Tag == BULLETP)
		{
			for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
			{
				// ���ʹ�
				if ((*iter2)->m_Tag == ENEMY)
				{
					// �Ѿ˰� ���ʹ��� �浹 ��
					if (RectCrashCheck((*iter)->GetRect(), (*iter2)->GetRect()))
					{
						((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());	// ���ʹ��� ü�� ����
						(*iter)->b_IsLive = false;	// �Ѿ� ����
					}
				}
			}
		}

		// ���ʹ��� �Ѿ�
		if ((*iter)->m_Tag == BULLETE)
		{
			// �÷��̾�� �Ѿ��� �浹 ��
			if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
			{
				// �����ð��� �ƴ϶��
				if (!m_Player->GetGracePeriod())
				{
					m_Player->MinusHp(1);			// ü�� ����
					m_Player->SetGracePeriod(true);	// ���� Ȱ��ȭ
					m_GPTime = timeGetTime();
				}
				(*iter)->b_IsLive = false;	// �Ѿ� ����
			}
		}

		//	���ʹ�
		if ((*iter)->m_Tag == ENEMY)
		{
			// ���ʹ̰� �÷��̾�� �ε��� ���
			if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
			{
				m_Player->MinusHp(1);		// ü�� ����
				(*iter)->b_IsLive = false;	// ���ʹ� ����
			}

			// ���ʹ��� ü���� 0 ���Ϸ� ������ ���
			if (((cEnemy*)(*iter))->GetHp() <= 0)
			{
				if (Random(0, 99) < 50)		// 50% Ȯ��
				{
					switch (Random(0, 2))	// 3���� �� �ϳ�
					{
					case 0:	AddObject(new cItem_Hp((*iter)->GetPos(), ITEM, m_Player, &m_Score));		break;	// ü�� ȸ�� ������ ����
					case 1:	AddObject(new cItem_Bomb((*iter)->GetPos(), ITEM, m_Player, &m_Score));		break;	// ��ź �߰� ������ ����
					case 2:	AddObject(new cItem_Power((*iter)->GetPos(), ITEM, m_Player, &m_Score));	break;	// �Ŀ� ȸ�� ������ ����
					default:																			break;
					}
				}
				(*iter)->b_IsLive = false;
			}

			// ���ʹ̰� �Ѿ��� �߻��ϴ� Ÿ�ֿ̹�
			if (((cEnemy*)(*iter))->GetIsFire())
				((cEnemy*)(*iter))->Attack(&m_Objects);	// �Ѿ��� ������Ʈ�� ���ʹ̿� �߰��Ѵ�.
		}
	}

	// ��� ������Ʈ�� Update()�� �����Ų��.
	UpdateAllObject();

	// ESC�� ������, Pause���°� �ƴ� ���
	if (INPUTMANAGER->KeyDown(VK_ESCAPE) && !b_Pause)
		OnPause();	// Pause Ȱ��ȭ

	b_Time = !b_Pause;	// Pause������ ��� ���� �ð��� ������Ű��, �ƴ϶�� Ȱ��ȭ ��Ų��.

	// DEBUG Mode
	if (INPUTMANAGER->KeyDown(VK_F11))
		DEBUGMODE = true;
	if (DEBUGMODE)
	{
		cGameObject* Temp;
		if (INPUTMANAGER->KeyDown(VK_F1))
		{
			Temp = new cEnemy1(POINT{ 1000, rand() % WinSizeY }, ENEMY);
			AddObject(Temp);
		}
		if (INPUTMANAGER->KeyDown(VK_F2))
		{
			m_Player->SetHp(m_Player->GetMaxHp());
		}
		if (INPUTMANAGER->KeyDown(VK_F10))
		{
			SCENEMANAGER->ChangeScene("Title");
		}
	}
}

void cIngameScene::Render()
{
	// ��� ������Ʈ�� Render()�� �����Ų��.
	RenderAllObject();
}

void cIngameScene::Release()
{
	RemoveAllObject();
	m_Player = nullptr;
	m_GPTime = 0;
	m_Score = 0;
}

/**
	@fn		OnPause()

	@brief	�Ͻ����� ������ UI�� �����ϰ�, Pause���¸� Ȱ��ȭ��Ų��.
*/
void cIngameScene::OnPause()
{
	cGameObject* Temp;

	Temp = new cUI_Pause_Background(POINT{ 0, 0 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Resume(POINT{ WinSizeX / 2, 350 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Reset(POINT{ WinSizeX / 2, 500 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Title(POINT{ WinSizeX / 2, 650 }, UI, &b_Pause);
	AddObject(Temp);

	b_Pause = true;
}
