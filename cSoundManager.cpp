#include "Framework.h"

cSoundManager::cSoundManager()
{
}

cSoundManager::~cSoundManager()
{
}

void cSoundManager::Init()
{
	m_Manager.Initialize(DXUTGetHWND(), 2);
}

void cSoundManager::Update()
{
	DWORD Status;

	for (auto& iter = m_Channels.begin(); iter != m_Channels.end();)
	{
		(*iter)->GetStatus(&Status);
		if ((Status & DSBSTATUS_PLAYING) == false)
		{
			(*iter)->Release();
			iter = m_Channels.erase(iter);
		}
		else
			iter++;
	}
}

void cSoundManager::Render()
{
}

void cSoundManager::Release()
{
	for (auto& iter : m_Channels)
	{
		iter->Release();
	}
	for (auto& iter : m_Sounds)
	{
		SAFE_DELETE(iter.second);
	}
}

void cSoundManager::AddSound(string Key, LPWSTR Path)
{
	CSound** a = new CSound*();
	m_Manager.Create(a, Path, DSBCAPS_CTRLVOLUME);
	m_Sounds.insert(make_pair(Key, (*a)));
	delete a;
}

LPDIRECTSOUNDBUFFER cSoundManager::Play(string key, int Volume, bool Loop)
{
	LPDIRECTSOUNDBUFFER temp;
	m_Manager.GetDirectSound()->DuplicateSoundBuffer(m_Sounds[key]->GetBuffer(0), &temp);
	temp->Play(0, 0, Loop ? DSBPLAY_LOOPING : 0);
	temp->SetVolume(Volume);
	m_Channels.push_back(temp);
	return temp;
}

void cSoundManager::StopAll()
{
	for (auto& iter : m_Channels)
	{
		iter->Release();
	}
	m_Channels.clear();
}
