#include "Framework.h"

cIngameScene::cIngameScene()
{
	m_Player = nullptr;
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

	m_NowStatus = Status::Playing;
	m_GPTime = 0;
	m_Score = 0;
	m_MobSpawn = timeGetTime();
	m_MobDelay = 2500;
}

void cIngameScene::Update()
{
	if (m_Player->GetIsFire())					// 플레이어가 총알을 발사하는 타이밍에
		AddObject(m_Player->Fire());			// 플레이어의 총알을 오브젝트에 추가한다.

	if (m_Player->GetGracePeriod())				// 플레이어가 무적시간일 때
	{
		if (timeGetTime() - m_GPTime >= 2000)	// 플레이어의 무적 시간이 끝난다면
			m_Player->SetGracePeriod(false);	// 플레이어의 무적을 해제시킨다.
	}

	if (m_Player->GetHp() <= 0)					// 플레이어의 체력이 0 이하일 때
	{
		OnGameover();							// Gameover 상태 활성화
		m_Player->b_IsLive = false;				// 플레이어 오브젝트 제거
	}

	// 마지막으로 에너미가 스폰된 후, 정해진 주기가 지났다면	
	if (timeGetTime() - m_MobSpawn > m_MobDelay)
	{
		AddObject(new cEnemy1(POINT{ WinSizeX - 50, Math::Random(0, WinSizeY - 150) }, ENEMY)); // 에너미 스폰
		m_MobSpawn = timeGetTime();
	}

	// 게임이 진행중일 때 프로세스
	if (m_NowStatus == Status::Playing)
	{
		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		{
			// 플레이어의 총알
			if ((*iter)->m_Tag == BULLETP)
			{
				for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
				{
					// 에너미
					if ((*iter2)->m_Tag == ENEMY)
					{
						// 총알과 에너미의 충돌 시
						if (RectCrashCheck((*iter)->GetRect(), (*iter2)->GetRect()))
						{
							((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());	// 에너미의 체력 감소
							(*iter)->b_IsLive = false;	// 총알 삭제
						}
					}
				}
			}

			// 에너미의 총알
			if ((*iter)->m_Tag == BULLETE)
			{
				// 플레이어와 총알의 충돌 시
				if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
				{
					// 무적시간이 아니라면
					if (!m_Player->GetGracePeriod())
					{
						m_Player->MinusHp(1);			// 체력 감소
						m_Player->SetGracePeriod(true);	// 무적 활성화
						m_GPTime = timeGetTime();
					}
					(*iter)->b_IsLive = false;	// 총알 삭제
				}
			}

			//	에너미
			if ((*iter)->m_Tag == ENEMY)
			{
				// 에너미가 플레이어랑 부딪힌 경우
				if (RectCrashCheck(m_Player->GetRect(), (*iter)->GetRect()))
				{
					m_Player->MinusHp(1);		// 체력 감소
					(*iter)->b_IsLive = false;	// 에너미 삭제
				}

				// 에너미의 체력이 0 이하로 낮아진 경우
				if (((cEnemy*)(*iter))->GetHp() <= 0)
				{
					if (Random(0, 99) < 50)		// 50% 확률
					{
						switch (Random(0, 2))	// 3가지 중 하나
						{
						case 0:	AddObject(new cItem_Hp((*iter)->GetPos(), ITEM, m_Player, &m_Score));		break;	// 체력 회복 아이템 생성
						case 1:	AddObject(new cItem_Bomb((*iter)->GetPos(), ITEM, m_Player, &m_Score));		break;	// 폭탄 추가 아이템 생성
						case 2:	AddObject(new cItem_Power((*iter)->GetPos(), ITEM, m_Player, &m_Score));	break;	// 파워 회복 아이템 생성
						default:																			break;
						}
					}
					(*iter)->b_IsLive = false;
				}

				// 에너미가 총알을 발사하는 타이밍에
				if (((cEnemy*)(*iter))->GetIsFire())
					((cEnemy*)(*iter))->Attack(&m_Objects);	// 총알의 오브젝트를 에너미에 추가한다.
			}
		}
	}


	// 모든 오브젝트의 Update()를 실행시킨다.
	UpdateAllObject();

	// ESC를 누르고, Pause상태가 아닌 경우
	if (INPUTMANAGER->KeyDown(VK_ESCAPE) && m_NowStatus == Status::Playing)
		OnPause();		// Pause 활성화

	// Pause상태에서 b_Pause가 false가 될 경우
	if (!b_Pause && m_NowStatus == Status::Pause)
		m_NowStatus = Status::Playing;	// Playing 활성화	

	if (m_NowStatus != Status::Playing)
		b_Time = false;	// Pause상태나 Gameover상태인 경우 씬의 시간을 정지시키고,
	else
		b_Time = true;	// 아니라면 활성화 시킨다.

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
		if (INPUTMANAGER->KeyDown(VK_F3))
		{
			m_Player->SetHp(0);
		}
		if (INPUTMANAGER->KeyDown(VK_F10))
		{
			SCENEMANAGER->ChangeScene("Title");
		}
	}
}

void cIngameScene::Render()
{
	// 모든 오브젝트의 Render()를 실행시킨다.
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

	@brief	일시정지 상태의 UI를 생성하고, Pause상태를 활성화시킨다.
*/
void cIngameScene::OnPause()
{
	cGameObject* Temp;

	// 현재 씬의 상태를 Pause로 전환
	m_NowStatus = Status::Pause;
	b_Pause = true;

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

	@brief	게임오버 상태의 UI를 생성하고, Gameover상태를 활성화시킨다.
*/
void cIngameScene::OnGameover()
{
	cGameObject* Temp;

	// 현재 씬의 상태를 GameOver로 전환
	m_NowStatus = Status::GameOver;

	Temp = new cUI_Gameover_Background(POINT{ 0, 0 }, UI, m_Score);
	AddObject(Temp);
	Temp = new cUI_Button_Gameover_Restart(POINT{ WinSizeX / 2, 600 }, UI);
	AddObject(Temp);
	Temp = new cUI_Button_Gameover_Title(POINT{ WinSizeX / 2, 750 }, UI);
	AddObject(Temp);
}
