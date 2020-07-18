#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;		//	������ �÷��̾�� ���� ���� ���� ������� �����ϹǷ� ����ȭ�Ͽ� �����Ѵ�.
	time_t m_GPTime;		//	GP = Grace Period ���� �ð�
	time_t m_MobSpawn;		//	���ʹ̰� �����Ǵ� �ð��� ����
	float m_MobDelay;		//	���ʹ̰� �����Ǵ� �ֱ� (1000�� 1��)

	enum class Status
	{
		Playing,
		Pause,
		GameOver
	};

	int m_Score;			// ����
	bool b_Pause = false;	// ������ �Ͻ����� �������� Ȯ��
	Status m_NowStatus;		// ������ ���� ����	

	bool DEBUGMODE = false;

public:
	cIngameScene();
	~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void OnPause();
	void OnGameover();
};

