#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;		//	������ �÷��̾�� ���� ���� ���� ������� �����ϹǷ� ����ȭ�Ͽ� �����Ѵ�.
	cBoss* m_Boss;			//	������ ������ ���� ���� ���� ������� �����ϹǷ� ����ȭ�Ͽ� �����Ѵ�.
	time_t m_GPTime;		//	GP = Grace Period ���� �ð�
	time_t m_MobSpawn;		//	���ʹ̰� �����Ǵ� �ð��� ����
	float m_MobDelay;		//	���ʹ̰� �����Ǵ� �ֱ� (1000�� 1��)

	time_t m_PlayTime;		//	timeGetTime() - m_PlayTime = ������ �÷��� �� �ð�. (1000�� 1��)

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

	int m_Score;			// ����
	bool b_Pause = false;	// ������ �Ͻ����� �������� Ȯ��
	bool b_OnBoss = false;	// �������� ���������� Ȯ��
	Status m_NowStatus;		// ������ ���� ����	
	Status m_PauseStatus;	// ������ �Ͻ����� �Ǳ� ���� ����	
	Stage m_NowStage;		// ������ ���� ��������

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
};

