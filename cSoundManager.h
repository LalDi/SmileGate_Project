#pragma once
/**
	@brief	프로그램의 사운드를 관리하는 매니저
	@brief	사운드의 재생과 중지 등의 기능을 한다.
*/
class cSoundManager
{
private:
	list<LPDIRECTSOUNDBUFFER> m_Channels;
	map<string, CSound*> m_Sounds;
	CSoundManager m_Manager;

public:
	cSoundManager();
	~cSoundManager();

	void Init();
	void Update();
	void Render();
	void Release();

	void AddSound(string Key, LPWSTR Path);
	LPDIRECTSOUNDBUFFER Play(string key, int Volume, bool Loop = false);
	void StopAll();
};

