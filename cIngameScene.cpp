#include "Framework.h"

cIngameScene::cIngameScene()
{
	m_Player = nullptr;
	m_Boss = nullptr;
	m_NowStatus = Status::Playing;
	m_NowStage = Stage::Stage1;
}

cIngameScene::~cIngameScene()
{
	RemoveAllObject();
}

void cIngameScene::Init()
{
	cGameObject* Background;
	cGameObject* UI_Temp;

	b_Time = true;

	// ���� �ʱ�ȭ
	m_Player = nullptr;
	m_Boss = nullptr;
	m_NowStatus = Status::Playing;
	m_NowStage = Stage::Stage1;
	m_PlayTime.Init();
	m_GPTime.Init();
	m_MobSpawn.Init();
	m_MobDelay = 0.75f;
	m_DelayBoss = 120;
	m_Score = 0;
	b_OnBoss = false;

	// ��� ������Ʈ ����
	Background = new cIngameBackground(POINT{ 0, 0 }, TEXTURE, 1);
	AddObject(Background);

	// �÷��̾� ����
	m_Player = new cPlayer(POINT{ 300, WinSizeY / 2 }, PLAYER);
	AddObject(m_Player);

	// �⺻ UI ����
	UI_Temp = new cUI_Background(POINT{ 20, 10 }, UI);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Character(POINT{ 50, 40 }, UI, m_Player);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_PlayerHp(POINT{ 105, 40 }, UI, m_Player);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_Bomb(POINT{ 180, 775 }, UI, m_Player);
	AddObject(UI_Temp); 
	UI_Temp = new cUI_Taro(POINT{ 20, 720 }, UI, m_Player);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Gauge_Power(POINT{ 335, 850 }, UI, m_Player);
	AddObject(UI_Temp);
	UI_Temp = new cUI_Score(POINT{ 1400, 30 }, UI, &m_Score);
	AddObject(UI_Temp);

	// ������� ���
	SOUNDMANAGER->Play("Stage1", 1, true);
}

void cIngameScene::Update()
{
	// Ÿ�̸� ����
	m_PlayTime.Update();
	m_MobSpawn.Update();
	m_GPTime.Update();

	// ���� ��ȣ�ۿ�
	if (b_OnBoss)
	{
		if (m_NowStatus == Status::Event)
		{
			if (m_Boss->GetHp() == m_Boss->GetMaxHp())	// ������ ó�� ������ ��
			{
				if (m_Boss->Appear(POINT{ WinSizeX - 250, WinSizeY / 2 }))
				{
					m_NowStatus = Status::Playing;
				}
			}
			else if (m_Boss->GetHp() <= 0)
			{
				if (m_Boss->DisAppear())
				{
					m_Boss->b_IsLive = false;				// ���� ������Ʈ ����
					b_OnBoss = false;						// ������ ����
					switch (m_NowStage)						// �������� ��ȯ
					{
					case cIngameScene::Stage::Stage1:
						ChangeStage(Stage::Stage2);
						m_NowStatus = Status::Playing;
						break;
					case cIngameScene::Stage::Stage2:
						ChangeStage(Stage::Stage3);
						m_NowStatus = Status::Playing;
						break;
					case cIngameScene::Stage::Stage3:		// 3��������(������ ��������)�� ���
						OnGameClear();						// ���� Ŭ����
						b_Time = false;
						break;
					}
				}
			}
		}
	}

	// ������ �������� �� ���μ���
	if (m_NowStatus == Status::Playing && b_Time)
	{
		// ���������� ���ʹ̰� ������ ��, ������ �ֱⰡ ������, �������� �ƴ϶��
		if (m_MobSpawn.Time(m_MobDelay) && !b_OnBoss)
		{
			POINT Pos = { WinSizeX, Math::Random(0, WinSizeY) };
			POINT Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
			int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));	// ��� ���ʹ̴� ������ ����� �÷��̾ �ִ� �������� ���ư���.

			int Temp = Random(1, 1000);
			// ������������ �ַ� ��Ÿ���� ���ʹ̰� �ٸ�
			switch (m_NowStage)
			{
			case Stage::Stage1:	// ��Ȳ�Ӽ� �ַ� ��������
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// ��Ȳ �Ӽ� Ȯ�� 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// ������ �Ӽ� Ȯ�� 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// ������ �Ӽ� Ȯ�� 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// ���� �Ӽ� Ȯ�� 5%
				break;
			case Stage::Stage2:	// �����ڼӼ� �ַ� ��������
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// ������ �Ӽ� Ȯ�� 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// ��Ȳ �Ӽ� Ȯ�� 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// ������ �Ӽ� Ȯ�� 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// ���� �Ӽ� Ȯ�� 5%
				break;
			case Stage::Stage3: // ������Ӽ� �ַ� ��������
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// ������ �Ӽ� Ȯ�� 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// ������ �Ӽ� Ȯ�� 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// ��Ȳ �Ӽ� Ȯ�� 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// ���� �Ӽ� Ȯ�� 5%
				break;
			}

			// �� ���� Ÿ�̸� ����
			m_MobSpawn.Reset();
		}

		// �÷���Ÿ���� �����ð� ������ ������ �����ȴ�
		if (m_PlayTime.Time(m_DelayBoss) && !b_OnBoss)
		{
			b_OnBoss = true;	// ������ Ȱ��ȭ
			
			// ���� ���� �����ϴ� ��� ���� �Ѿ� ����
			for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			{
				if ((*iter)->m_Tag == BULLETE || (*iter)->m_Tag == ENEMY)
					(*iter)->b_IsLive = false;
			}

			m_NowStatus = Status::Event;	// �̺�Ʈ Ȱ��ȭ

			// ���� ����
			switch (m_NowStage)
			{
			case cIngameScene::Stage::Stage1:
				m_Boss = new cBoss_TheHierophant(POINT{ WinSizeX + 430, WinSizeY / 2 }, BOSS, m_Player);
				break;
			case cIngameScene::Stage::Stage2:
				m_Boss = new cBoss_TheHermit(POINT{ WinSizeX + 430, WinSizeY / 2 }, BOSS, m_Player);
				break;
			case cIngameScene::Stage::Stage3:
				m_Boss = new cBoss_TheMagician(POINT{ WinSizeX + 430, WinSizeY / 2 }, BOSS, m_Player);
				break;
			default:	break;
			}
			AddObject(m_Boss);
			AddObject(new cUI_Gauge_BossHp(POINT{ WinSizeX / 2, 100 }, UI, m_Boss));
			AddObject(new cUI_Warning(POINT{ 0, 0 }, UI));
		}

		// �÷��̾� ��ȣ�ۿ�
		if (m_Player)
		{
			if (m_Player->GetIsFire())						// �÷��̾ �Ѿ��� �߻��ϴ� Ÿ�ֿ̹�
				AddObject(m_Player->Fire());				// �÷��̾��� �Ѿ��� ������Ʈ�� �߰��Ѵ�.
			if (m_Player->GetIsBomb())						// �÷��̾ ��ź�� �߻��ϴ� Ÿ�ֿ̹�
			{
				AddObject(m_Player->Bomb());				// �÷��̾��� ��ź�� ������Ʈ�� �߰��ϰ�

				// ��� ���鿡�� ��ź �������� ������.
				for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
				{
					if ((*iter)->m_Tag == ENEMY)
						((cEnemy*)(*iter))->MinusHp(m_Player->GetBombDamage());
					if ((*iter)->m_Tag == BOSS)
						((cBoss*)(*iter))->MinusHp(m_Player->GetBombDamage());
					if ((*iter)->m_Tag == BULLETE)
						(*iter)->b_IsLive = false;
				}
			}
			if (m_Player->GetIsChange() && !b_ChangeCard)	// �÷��̾ ī�带 �����ϴ� Ÿ�ֿ̹�
			{
				OnChangeCard();								// ī�� ���� UI�� ����
				b_ChangeCard = true;
			}

			if (m_Player->GetGracePeriod())					// �÷��̾ �����ð��� ��
			{
				if (m_GPTime.Time(2))						// �÷��̾��� ���� �ð��� �����ٸ�
					m_Player->SetGracePeriod(false);		// �÷��̾��� ������ ������Ų��.
			}

			if (m_Player->GetHp() <= 0)						// �÷��̾��� ü���� 0 ������ ��
			{
				OnGameover();								// Gameover ���� Ȱ��ȭ
				m_Player->b_IsLive = false;					// �÷��̾� ������Ʈ ����
			}
		}

		// ���� ��ȣ�ۿ�
		if (b_OnBoss)
		{
			// ������ ���� Ÿ�̹��� ��
			if (m_Boss->GetAttack())
				m_Boss->Attack(&m_Objects);					// ������ ���� �Լ� ����

			// ������ �÷��̾�� �ε��� ���
			if (RectCrashCheck(m_Player->GetRect(), m_Boss->GetRect()))
			{
				// �����ð��� �ƴ϶��
				if (!m_Player->GetGracePeriod())
				{
					m_Player->MinusHp(1);					// ü�� ����
					m_Player->SetGracePeriod(true);			// ���� Ȱ��ȭ
					m_GPTime.Reset();						// ���� Ÿ�̸� �ʱ�ȭ
				}
			}

			if (m_Boss->GetHp() <= 0)						// ������ ü���� 0 ������ ��
			{
				m_NowStatus = Status::Event;
				m_Score += m_Boss->GetScore();				// ���� �߰�
				m_Boss->SetControl(false);					// ������ �ൿ ����

				// ��� �� �Ѿ˰� �� ���ʹ̸� ����
				for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
				{
					if ((*iter)->m_Tag == BULLETE || (*iter)->m_Tag == ENEMY)
						(*iter)->b_IsLive = false;
				}
			}
		}

		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		{
			// �÷��̾��� �Ѿ�
			if ((*iter)->m_Tag == BULLETP)
			{
				for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
				{
					// ���ʹ�
					if ((*iter2)->m_Tag == ENEMY || (*iter2)->m_Tag == BOSS)
					{
						// �Ѿ˰� ���ʹ��� �浹 ��
						if (RectCrashCheck((*iter)->GetRect(), (*iter2)->GetRect()))
						{
							// ���ʹ��� �Ӽ��� �󼺵�����
							switch (((cEnemy*)(*iter2))->GetEnemyState())
							{
							case EnemyState::The_Hierophant:	// ��Ȳ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _Judgement:		((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _The_Sun:			((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								}
								break;
							case EnemyState::The_Hermit:		// ������ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _Judgement:		((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _The_Sun:			((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								}
								break;
							case EnemyState::The_Magician:		// ������ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _Judgement:		((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _The_Sun:			((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								}
								break;
							case EnemyState::The_Fool:
								((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
							}
							switch (((cBoss*)(*iter2))->GetEnemyState())
							{
							case EnemyState::The_Hierophant:	// ��Ȳ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								}
								break;
							case EnemyState::The_Hermit:		// ������ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								}
								break;
							case EnemyState::The_Magician:		// ������ Ÿ�� ��
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								}
								break;
							}
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
						m_GPTime.Reset();				// ���� Ÿ�̸� �ʱ�ȭ
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
					// �����ð��� �ƴ϶��
					if (!m_Player->GetGracePeriod())
					{
						m_Player->MinusHp(1);			// ü�� ����
						m_Player->SetGracePeriod(true);	// ���� Ȱ��ȭ
						m_GPTime.Reset();				// ���� Ÿ�̸� �ʱ�ȭ
					}
					(*iter)->b_IsLive = false;	// ���ʹ� ����
				}

				// ���ʹ��� ü���� 0 ���Ϸ� ������ ���
				if (((cEnemy*)(*iter))->GetHp() <= 0)
				{
					if (Random(0, 99) < 30)		// 30% Ȯ��
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
					m_Score += ((cEnemy*)(*iter))->GetScore();
				}

				// ���ʹ̰� �Ѿ��� �߻��ϴ� Ÿ�ֿ̹�
				if (((cEnemy*)(*iter))->GetIsFire())
					((cEnemy*)(*iter))->Attack(&m_Objects);	// �Ѿ��� ������Ʈ�� ���ʹ̿� �߰��Ѵ�.
			}
		}
	}


	// ��� ������Ʈ�� Update()�� �����Ų��.
	UpdateAllObject();


	// ESC�� ������, Pauseâ�� ��� �� �ִ� ������ ���
	if (INPUTMANAGER->KeyDown(VK_ESCAPE) && m_NowStatus != Status::Pause && m_NowStatus != Status::GameOver)
		OnPause();		// Pause Ȱ��ȭ

	// Pause���¿��� b_Pause�� false�� �� ���
	if (!b_Pause && m_NowStatus == Status::Pause)
	{
		m_NowStatus = m_PauseStatus;	// Pause���°� �Ǳ� ���� ���·� ����
		// Ÿ�̸� �簳
		m_PlayTime.Resume();
		m_MobSpawn.Resume();
		m_GPTime.Resume();
		if (m_Boss)
			m_Boss->Pause(false);
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == ENEMY)
				((cEnemy*)(*iter))->Pause(false);
	}

	if (m_NowStatus == Status::Pause || m_NowStatus == Status::GameOver || b_ChangeCard)
	{
		b_Time = false;	// Pause���³� Gameover������ ���, �÷��̾ ī�带 �ٲٴ� ��쿣 ���� �ð��� ������Ű��,
		// ��� Ÿ�̸Ӹ� ������Ų��.
		m_PlayTime.Pause();
		m_MobSpawn.Pause();
		m_GPTime.Pause();
		if (m_Boss)
			m_Boss->Pause(true);
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == ENEMY)
				((cEnemy*)(*iter))->Pause(true);
	}
	else
	{
		b_Time = true;	// �� �ܿ��� �ð��� Ȱ��ȭ ��Ų��.
		// Ÿ�̸ӵ� �簳��Ų��
		m_PlayTime.Resume();
		m_MobSpawn.Resume();
		m_GPTime.Resume();
		if (m_Boss)
			m_Boss->Pause(false);
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == ENEMY)
				((cEnemy*)(*iter))->Pause(false);
	}


	// DEBUG Mode
	if (INPUTMANAGER->KeyDown(VK_F11))
		DEBUGMODE = true;
	if (DEBUGMODE)
	{
		cGameObject* Temp;
		if (INPUTMANAGER->KeyDown(VK_F1))
		{
			POINT Pos = { WinSizeX, Math::Random(0, WinSizeY) };
			POINT Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
			int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));
			AddEnemy(Pos, Angle, EnemyState::The_Hierophant);
		}
		if (INPUTMANAGER->KeyDown(VK_F2))
		{
			m_Player->SetHp(m_Player->GetMaxHp());
		}
		if (INPUTMANAGER->KeyDown(VK_F3))
		{
			m_Player->SetHp(0);
		}
		if (INPUTMANAGER->KeyDown(VK_F4))
		{
			m_Player->SetPlayerState(PlayerState::Wheel_of_Fortune);
		}
		if (INPUTMANAGER->KeyDown(VK_F5))
		{
			m_Player->SetPlayerState(PlayerState::Judgement);
		}
		if (INPUTMANAGER->KeyDown(VK_F6))
		{
			m_Player->SetPlayerState(PlayerState::The_Sun);
		}
		if (INPUTMANAGER->KeyDown(VK_F7))
		{
			m_Player->SetBomb(m_Player->GetBomb() + 1);
		}
		if (INPUTMANAGER->KeyDown(VK_F8))
		{
			m_Player->SetPower(m_Player->GetPower() + 100);
		}
		if (INPUTMANAGER->KeyDown(VK_F9))
		{
			m_DelayBoss = 0;
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
	SOUNDMANAGER->StopAll();
	m_Player = nullptr;
	m_Score = 0;
}

/**
	@fn		AddEnemy(POINT, int, EnemyState)

	@brief	���ǿ� �´� ���ʹ� 5��ü �� �������� �ϳ��� ��ü�� �߰��Ѵ�.

	@param	Pos		- ���ʹ̰� ��ȯ�� ��ġ
	@param	Angle	- ���ʹ̰� ���ư� ����
	@param	State	- ���ʹ��� �Ӽ���
*/
void cIngameScene::AddEnemy(POINT Pos, int Angle, EnemyState State)
{
	int Temp = Random(1, 5);
	switch (Temp)
	{
	case 1:	AddObject(new cEnemy1(Pos, ENEMY, Angle, State));		break;
	case 2:	AddObject(new cEnemy2(Pos, ENEMY, m_Player, State));	break;
	case 3:	AddObject(new cEnemy3(Pos, ENEMY, Angle, State));		break;
	case 4:	AddObject(new cEnemy4(Pos, ENEMY, Angle, State));		break;
	case 5:	AddObject(new cEnemy5(Pos, ENEMY, Angle, State));		break;
	}
}

/**
	@fn		OnPause()

	@brief	�Ͻ����� ������ UI�� �����ϰ�, Pause���¸� Ȱ��ȭ��Ų��.
*/
void cIngameScene::OnPause()
{
	cGameObject* Temp;

	// ���� ���� ���¸� �ӽ÷� ����
	m_PauseStatus = m_NowStatus;
	//m_PauseTime = timeGetTime();
	// ���� ���� ���¸� Pause�� ��ȯ
	m_NowStatus = Status::Pause;
	b_Pause = true;

	// Pause������ UI ����
	Temp = new cUI_Pause_Background(POINT{ 0, 0 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Resume(POINT{ WinSizeX / 2, 350 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Reset(POINT{ WinSizeX / 2, 500 }, UI, &b_Pause);
	AddObject(Temp);
	Temp = new cUI_Button_Pause_Title(POINT{ WinSizeX / 2, 650 }, UI, &b_Pause);
	AddObject(Temp);
}

/**
	@fn		OnGameover()

	@brief	���ӿ��� ������ UI�� �����ϰ�, Gameover���¸� Ȱ��ȭ��Ų��.
*/
void cIngameScene::OnGameover()
{
	cGameObject* Temp;

	// ���� ���� ���¸� GameOver�� ��ȯ
	m_NowStatus = Status::GameOver;

	// GameOver������ UI ����
	Temp = new cUI_Gameover_Background(POINT{ 0, 0 }, UI, m_Score);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Restart(POINT{ WinSizeX / 2, 600 }, UI);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Title(POINT{ WinSizeX / 2, 750 }, UI);
	AddObject(Temp);
}

/**
	@fn		OnChangeCard()

	@brief	ī�� ��ü ������ UI�� �����Ѵ�.
*/
void cIngameScene::OnChangeCard()
{
	cGameObject* Temp;

	// ��� Ÿ�̸� �ߴ�
	m_PlayTime.Pause();
	m_MobSpawn.Pause();
	m_GPTime.Pause();
	if (m_Boss)
		m_Boss->Pause(true);
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		if ((*iter)->m_Tag == ENEMY)
			((cEnemy*)(*iter))->Pause(true);


	// ī�� ��ü ������ UI�� ����
	Temp = new cUI_ChangeCard(POINT{ 0, 0 }, UI, m_Player);
	AddObject(Temp);
	Temp = new cUI_Button_SeleteCard1(POINT{ WinSizeX / 2 - 300, WinSizeY / 2 }, UI, m_Player, &b_ChangeCard);
	AddObject(Temp);
	Temp = new cUI_Button_SeleteCard2(POINT{ WinSizeX / 2 , WinSizeY / 2 }, UI, m_Player, &b_ChangeCard);
	AddObject(Temp);
	Temp = new cUI_Button_SeleteCard3(POINT{ WinSizeX / 2 + 300, WinSizeY / 2 }, UI, m_Player, &b_ChangeCard);
	AddObject(Temp);
}

/**
	@fn		OnGameClear()

	@brief	����Ŭ���� ������ UI�� �����Ѵ�.
*/
void cIngameScene::OnGameClear()
{
	cGameObject* Temp;
	
	Temp = new cUI_Clear_Background(POINT{ 0,0 }, UI);
	AddObject(Temp);

	Temp = new cUI_Clear_Score(POINT{ 700, 450 }, UI, &m_Score);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Restart(POINT{ WinSizeX / 2, 550 }, UI);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Title(POINT{ WinSizeX / 2, 700 }, UI);
	AddObject(Temp);
}

/**
	@fn		ChangeStage(Stage)

	@brief	���� ������������ ���� ���������� �Ѿ�� �Լ�

	@param	NextStage	- ��ȯ�� ��������
*/
void cIngameScene::ChangeStage(Stage NextStage)
{
	cPlayer Temp = *m_Player; // �÷��̾��� �����͸� �ӽ÷� ����
	cGameObject* UI_Temp;

	// �ٲٰ��� �ϴ� ���������� ���� ���������� ���
	if (m_NowStage == NextStage)
		return;	// ��ȯ ���� �Լ� ����

	// ���� ���������� ���� ���� BGM�� �޶���
	switch (NextStage)
	{
	case cIngameScene::Stage::Stage1:
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == TEXTURE)
				((cIngameBackground*)(*iter))->ChangeBG(1);
		m_DelayBoss = 120;
		SOUNDMANAGER->StopAll();
		SOUNDMANAGER->Play("Stage1", 1, true);
		break;
	case cIngameScene::Stage::Stage2:
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == TEXTURE)
				((cIngameBackground*)(*iter))->ChangeBG(2);
		m_DelayBoss = 140;
		SOUNDMANAGER->StopAll();
		SOUNDMANAGER->Play("Stage2", 1, true);
		break;
	case cIngameScene::Stage::Stage3:
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			if ((*iter)->m_Tag == TEXTURE)
				((cIngameBackground*)(*iter))->ChangeBG(3);
		m_DelayBoss = 160;
		SOUNDMANAGER->StopAll();
		SOUNDMANAGER->Play("Stage3", 1, true);
		break;
	default:
		break;
	}

	// �÷��� Ÿ�̸� ����
	m_PlayTime.Reset();

	// �������� ����
	m_NowStage = NextStage;
}
