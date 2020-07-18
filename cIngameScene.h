#pragma once
class cIngameScene : public cScene
{
private:
	cPlayer* m_Player;		//	게임의 플레이어는 게임 내에 여러 방면으로 간섭하므로 변수화하여 저장한다.
	time_t m_GPTime;		//	GP = Grace Period 무적 시간

	int m_Score;			// 점수
	bool b_Pause = false;	// 게임이 일시정지 상태인지 확인

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

