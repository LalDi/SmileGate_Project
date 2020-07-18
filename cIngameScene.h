#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;		//	������ �÷��̾�� ���� ���� ���� ������� �����ϹǷ� ����ȭ�Ͽ� �����Ѵ�.
	time_t m_GPTime;		//	GP = Grace Period ���� �ð�

	int m_Score;			// ����
	bool b_Pause = false;	// ������ �Ͻ����� �������� Ȯ��

	bool DEBUGMODE = false;

public:
	cIngameScene();
	~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void OnPause();
};

