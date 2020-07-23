#pragma once
class cTimer
{
private:
	DWORD m_StartTime;
	DWORD m_PauseTime;
	DWORD m_ResumeTime;
	DWORD m_NowTime;

	bool b_IsPause;

public:
	cTimer();
	~cTimer();

	void Init();
	void Update();

	void Pause();
	void Resume();
	void Reset();

	bool GetPause() { return b_IsPause; }

	DWORD Time() { return m_NowTime; }
	bool Time(float Time) { return m_NowTime >= (Time * 1000.f); }
	bool Time(int Time) { return m_NowTime >= (Time * 1000); }
};

