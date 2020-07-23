#include "Framework.h"

cTimer::cTimer()
{
}

cTimer::~cTimer()
{
}

void cTimer::Init()
{
	m_StartTime = timeGetTime();
	m_NowTime = m_StartTime;
	m_ResumeTime = 0;
	m_PauseTime = 0;
	b_IsPause = false;
}

void cTimer::Update()
{
	if (!b_IsPause)
		m_NowTime = timeGetTime() - m_StartTime - (m_ResumeTime - m_PauseTime);
}

void cTimer::Pause()
{
	if (!b_IsPause)
	{
		m_PauseTime = timeGetTime();
		b_IsPause = true;
	}
}

void cTimer::Resume()
{
	if (b_IsPause)
	{
		m_ResumeTime = timeGetTime();
		b_IsPause = false;
	}
}

void cTimer::Reset()
{
	Init();
}
