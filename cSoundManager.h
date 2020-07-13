#pragma once
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

