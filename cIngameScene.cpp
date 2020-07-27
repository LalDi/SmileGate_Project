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

	// 변수 초기화
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

	// 배경 오브젝트 생성
	Background = new cIngameBackground(POINT{ 0, 0 }, TEXTURE, 1);
	AddObject(Background);

	// 플레이어 생성
	m_Player = new cPlayer(POINT{ 300, WinSizeY / 2 }, PLAYER);
	AddObject(m_Player);

	// 기본 UI 생성
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

	// 배경음악 재생
	SOUNDMANAGER->Play("Stage1", 1, true);
}

void cIngameScene::Update()
{
	// 타이머 갱신
	m_PlayTime.Update();
	m_MobSpawn.Update();
	m_GPTime.Update();

	// 보스 상호작용
	if (b_OnBoss)
	{
		if (m_NowStatus == Status::Event)
		{
			if (m_Boss->GetHp() == m_Boss->GetMaxHp())	// 보스가 처음 등장할 때
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
					m_Boss->b_IsLive = false;				// 보스 오브젝트 제거
					b_OnBoss = false;						// 보스전 종료
					switch (m_NowStage)						// 스테이지 변환
					{
					case cIngameScene::Stage::Stage1:
						ChangeStage(Stage::Stage2);
						m_NowStatus = Status::Playing;
						break;
					case cIngameScene::Stage::Stage2:
						ChangeStage(Stage::Stage3);
						m_NowStatus = Status::Playing;
						break;
					case cIngameScene::Stage::Stage3:		// 3스테이지(마지막 스테이지)일 경우
						OnGameClear();						// 게임 클리어
						b_Time = false;
						break;
					}
				}
			}
		}
	}

	// 게임이 진행중일 때 프로세스
	if (m_NowStatus == Status::Playing && b_Time)
	{
		// 마지막으로 에너미가 스폰된 후, 정해진 주기가 지났고, 보스전이 아니라면
		if (m_MobSpawn.Time(m_MobDelay) && !b_OnBoss)
		{
			POINT Pos = { WinSizeX, Math::Random(0, WinSizeY) };
			POINT Vec = { m_Player->GetPos().x - Pos.x, m_Player->GetPos().y - Pos.y };
			int Angle = D3DXToDegree(atan2(Vec.y, Vec.x));	// 모든 에너미는 생성된 당시의 플레이어가 있던 방향으로 날아간다.

			int Temp = Random(1, 1000);
			// 스테이지별로 주로 나타나는 에너미가 다름
			switch (m_NowStage)
			{
			case Stage::Stage1:	// 교황속성 주류 스테이지
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// 교황 속성 확률 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// 은둔자 속성 확률 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// 마법사 속성 확률 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// 광대 속성 확률 5%
				break;
			case Stage::Stage2:	// 은둔자속성 주류 스테이지
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// 은둔자 속성 확률 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// 교황 속성 확률 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// 마법사 속성 확률 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// 광대 속성 확률 5%
				break;
			case Stage::Stage3: // 마법사속성 주류 스테이지
				if (Temp <= 700)
					AddEnemy(Pos, Angle, EnemyState::The_Magician);		// 마법사 속성 확률 70%
				else if (Temp <= 825)
					AddEnemy(Pos, Angle, EnemyState::The_Hermit);		// 은둔자 속성 확률 12.5%
				else if (Temp <= 950)
					AddEnemy(Pos, Angle, EnemyState::The_Hierophant);	// 교황 속성 확률 12.5%
				else
					AddEnemy(Pos, Angle, EnemyState::The_Fool);			// 광대 속성 확률 5%
				break;
			}

			// 몹 스폰 타이머 리셋
			m_MobSpawn.Reset();
		}

		// 플레이타임이 일정시간 지나서 보스가 스폰된다
		if (m_PlayTime.Time(m_DelayBoss) && !b_OnBoss)
		{
			b_OnBoss = true;	// 보스전 활성화
			
			// 게임 내에 존재하는 모든 적과 총알 삭제
			for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
			{
				if ((*iter)->m_Tag == BULLETE || (*iter)->m_Tag == ENEMY)
					(*iter)->b_IsLive = false;
			}

			m_NowStatus = Status::Event;	// 이벤트 활성화

			// 보스 생성
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

		// 플레이어 상호작용
		if (m_Player)
		{
			if (m_Player->GetIsFire())						// 플레이어가 총알을 발사하는 타이밍에
				AddObject(m_Player->Fire());				// 플레이어의 총알을 오브젝트에 추가한다.
			if (m_Player->GetIsBomb())						// 플레이어가 폭탄을 발사하는 타이밍에
			{
				AddObject(m_Player->Bomb());				// 플레이어의 폭탄을 오브젝트에 추가하고

				// 모든 적들에게 폭탄 데미지를 입힌다.
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
			if (m_Player->GetIsChange() && !b_ChangeCard)	// 플레이어가 카드를 변경하는 타이밍에
			{
				OnChangeCard();								// 카드 변경 UI를 생성
				b_ChangeCard = true;
			}

			if (m_Player->GetGracePeriod())					// 플레이어가 무적시간일 때
			{
				if (m_GPTime.Time(2))						// 플레이어의 무적 시간이 끝난다면
					m_Player->SetGracePeriod(false);		// 플레이어의 무적을 해제시킨다.
			}

			if (m_Player->GetHp() <= 0)						// 플레이어의 체력이 0 이하일 때
			{
				OnGameover();								// Gameover 상태 활성화
				m_Player->b_IsLive = false;					// 플레이어 오브젝트 제거
			}
		}

		// 보스 상호작용
		if (b_OnBoss)
		{
			// 보스의 공격 타이밍일 때
			if (m_Boss->GetAttack())
				m_Boss->Attack(&m_Objects);					// 보스의 공격 함수 실행

			// 보스가 플레이어랑 부딪힌 경우
			if (RectCrashCheck(m_Player->GetRect(), m_Boss->GetRect()))
			{
				// 무적시간이 아니라면
				if (!m_Player->GetGracePeriod())
				{
					m_Player->MinusHp(1);					// 체력 감소
					m_Player->SetGracePeriod(true);			// 무적 활성화
					m_GPTime.Reset();						// 무적 타이머 초기화
				}
			}

			if (m_Boss->GetHp() <= 0)						// 보스의 체력이 0 이하일 때
			{
				m_NowStatus = Status::Event;
				m_Score += m_Boss->GetScore();				// 점수 추가
				m_Boss->SetControl(false);					// 보스의 행동 제한

				// 모든 적 총알과 적 에너미를 제거
				for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
				{
					if ((*iter)->m_Tag == BULLETE || (*iter)->m_Tag == ENEMY)
						(*iter)->b_IsLive = false;
				}
			}
		}

		for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		{
			// 플레이어의 총알
			if ((*iter)->m_Tag == BULLETP)
			{
				for (auto iter2 = m_Objects.begin(); iter2 != m_Objects.end(); iter2++)
				{
					// 에너미
					if ((*iter2)->m_Tag == ENEMY || (*iter2)->m_Tag == BOSS)
					{
						// 총알과 에너미의 충돌 시
						if (RectCrashCheck((*iter)->GetRect(), (*iter2)->GetRect()))
						{
							// 에너미의 속성별 상성데미지
							switch (((cEnemy*)(*iter2))->GetEnemyState())
							{
							case EnemyState::The_Hierophant:	// 교황 타입 상성
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _Judgement:		((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _The_Sun:			((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								}
								break;
							case EnemyState::The_Hermit:		// 은둔자 타입 상성
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _Judgement:		((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _The_Sun:			((cEnemy*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								}
								break;
							case EnemyState::The_Magician:		// 마법사 타입 상성
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
							case EnemyState::The_Hierophant:	// 교황 타입 상성
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								}
								break;
							case EnemyState::The_Hermit:		// 은둔자 타입 상성
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								}
								break;
							case EnemyState::The_Magician:		// 마법사 타입 상성
								switch (m_Player->GetPlayerState())
								{
								case _Wheel_of_Fortune: ((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage());		break;
								case _Judgement:		((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() + 1);	break;
								case _The_Sun:			((cBoss*)(*iter2))->MinusHp(((cBullet*)(*iter))->GetDamage() - 1);	break;
								}
								break;
							}
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
						m_GPTime.Reset();				// 무적 타이머 초기화
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
					// 무적시간이 아니라면
					if (!m_Player->GetGracePeriod())
					{
						m_Player->MinusHp(1);			// 체력 감소
						m_Player->SetGracePeriod(true);	// 무적 활성화
						m_GPTime.Reset();				// 무적 타이머 초기화
					}
					(*iter)->b_IsLive = false;	// 에너미 삭제
				}

				// 에너미의 체력이 0 이하로 낮아진 경우
				if (((cEnemy*)(*iter))->GetHp() <= 0)
				{
					if (Random(0, 99) < 30)		// 30% 확률
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
					m_Score += ((cEnemy*)(*iter))->GetScore();
				}

				// 에너미가 총알을 발사하는 타이밍에
				if (((cEnemy*)(*iter))->GetIsFire())
					((cEnemy*)(*iter))->Attack(&m_Objects);	// 총알의 오브젝트를 에너미에 추가한다.
			}
		}
	}


	// 모든 오브젝트의 Update()를 실행시킨다.
	UpdateAllObject();


	// ESC를 누르고, Pause창을 띄울 수 있는 상태인 경우
	if (INPUTMANAGER->KeyDown(VK_ESCAPE) && m_NowStatus != Status::Pause && m_NowStatus != Status::GameOver)
		OnPause();		// Pause 활성화

	// Pause상태에서 b_Pause가 false가 될 경우
	if (!b_Pause && m_NowStatus == Status::Pause)
	{
		m_NowStatus = m_PauseStatus;	// Pause상태가 되기 전의 상태로 복구
		// 타이머 재개
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
		b_Time = false;	// Pause상태나 Gameover상태인 경우, 플레이어가 카드를 바꾸는 경우엔 씬의 시간을 정지시키고,
		// 모든 타이머를 정지시킨다.
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
		b_Time = true;	// 그 외에는 시간을 활성화 시킨다.
		// 타이머도 재개시킨다
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
	// 모든 오브젝트의 Render()를 실행시킨다.
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

	@brief	조건에 맞는 에너미 5개체 중 랜덤으로 하나의 개체를 추가한다.

	@param	Pos		- 에너미가 소환될 위치
	@param	Angle	- 에너미가 날아갈 방향
	@param	State	- 에너미의 속성값
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

	@brief	일시정지 상태의 UI를 생성하고, Pause상태를 활성화시킨다.
*/
void cIngameScene::OnPause()
{
	cGameObject* Temp;

	// 현재 씬의 상태를 임시로 저장
	m_PauseStatus = m_NowStatus;
	//m_PauseTime = timeGetTime();
	// 현재 씬의 상태를 Pause로 전환
	m_NowStatus = Status::Pause;
	b_Pause = true;

	// Pause상태의 UI 생성
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

	// GameOver상태의 UI 생성
	Temp = new cUI_Gameover_Background(POINT{ 0, 0 }, UI, m_Score);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Restart(POINT{ WinSizeX / 2, 600 }, UI);
	AddObject(Temp);
	Temp = new cUI_Button_Ingame_Title(POINT{ WinSizeX / 2, 750 }, UI);
	AddObject(Temp);
}

/**
	@fn		OnChangeCard()

	@brief	카드 교체 상태의 UI를 생성한다.
*/
void cIngameScene::OnChangeCard()
{
	cGameObject* Temp;

	// 모든 타이머 중단
	m_PlayTime.Pause();
	m_MobSpawn.Pause();
	m_GPTime.Pause();
	if (m_Boss)
		m_Boss->Pause(true);
	for (auto iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		if ((*iter)->m_Tag == ENEMY)
			((cEnemy*)(*iter))->Pause(true);


	// 카드 교체 상태의 UI를 생성
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

	@brief	게임클리어 상태의 UI를 생성한다.
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

	@brief	현재 스테이지에서 다음 스테이지로 넘어가는 함수

	@param	NextStage	- 전환할 스테이지
*/
void cIngameScene::ChangeStage(Stage NextStage)
{
	cPlayer Temp = *m_Player; // 플레이어의 데이터를 임시로 저장
	cGameObject* UI_Temp;

	// 바꾸고자 하는 스테이지가 현재 스테이지일 경우
	if (m_NowStage == NextStage)
		return;	// 변환 없이 함수 종료

	// 다음 스테이지에 따라 배경과 BGM이 달라짐
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

	// 플레이 타이머 리셋
	m_PlayTime.Reset();

	// 스테이지 변경
	m_NowStage = NextStage;
}
