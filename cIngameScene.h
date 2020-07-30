#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;		//	게임의 플레이어는 게임 내에 여러 방면으로 간섭하므로 변수화하여 저장한다.
	cBoss* m_Boss;			//	게임의 보스는 게임 내에 여러 방면으로 간섭하므로 변수화하여 저장한다.

	cIngameBlackScene* m_BlackScreen;

	float m_MobDelay;		//	에너미가 스폰되는 주기
	cTimer m_MobSpawn;		//	에너미가 스폰되는 시간 타이머

	cTimer m_GPTime;		//	GP = Grace Period 무적 시간
	cTimer m_PlayTime;		//	게임을 플레이 한 시간.
	time_t m_PauseTime;

	enum class Status
	{
		Playing,
		Pause,
		Event,
		GameOver
	};

	enum class Stage
	{
		Stage1,
		Stage2,
		Stage3
	};

	int m_Score;				// 점수
	float m_DelayBoss;			// 보스가 나오기 전 까지의 시간(초)
	bool b_Pause = false;		// 게임이 일시정지 상태인지 확인
	bool b_ChangeCard = false;	// 플레이어가 카드를 바꾸는 중인지 확인
	bool b_OnBoss = false;		// 보스전이 진행중인지 확인
	Status m_NowStatus;			// 게임의 현재 상태	
	Status m_PauseStatus;		// 게임이 일시정지 되기 전의 상태	
	Stage m_NowStage;			// 게임의 현재 스테이지

	bool DEBUGMODE = false;

public:
	cIngameScene();
	~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void AddEnemy(POINT Pos, int Angle, EnemyState State);
	void OnPause();
	void OnGameover();
	void OnChangeCard();
	void OnGameClear();

	void ChangeStage(Stage NextStage);
};

