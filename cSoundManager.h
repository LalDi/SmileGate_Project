#pragma once
/**
	@brief	���α׷��� ���带 �����ϴ� �Ŵ���
	@brief	������ ����� ���� ���� ����� �Ѵ�.
*/
class cSoundManager
{
private:
	list<LPDIRECTSOUNDBUFFER> m_Channels;
	map<string, CSound*> m_Sounds;
	CSoundManager m_Manager;

	int m_BGM_Volume;
	int m_SE_Volume;

public:
	cSoundManager();
	~cSoundManager();

	void Init();
	void Update();
	void Render();
	void Release();

	void AddSound(string Key, LPWSTR Path);
	//LPDIRECTSOUNDBUFFER Play(string key, int Volume, bool Loop = false);
	LPDIRECTSOUNDBUFFER Play(string key, int tag, bool Loop = false);
	void StopAll();

	int GetVolume(int tag);
	void SetVolume(int value, int tag);
};

