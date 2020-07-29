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
	ifstream Data;
	Data.open("Data.ini");
	if (Data.is_open())
	{
		string arr;
		getline(Data, arr);
		m_BGM_Volume = atoi(arr.c_str());
		getline(Data, arr);
		m_SE_Volume = atoi(arr.c_str());
	}
	else
	{
		m_BGM_Volume = DSBVOLUME_MAX;
		m_SE_Volume = DSBVOLUME_MAX;
	}
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

//LPDIRECTSOUNDBUFFER cSoundManager::Play(string key, int Volume, bool Loop)
//{
//	LPDIRECTSOUNDBUFFER temp;
//	m_Manager.GetDirectSound()->DuplicateSoundBuffer(m_Sounds[key]->GetBuffer(0), &temp);
//	temp->Play(0, 0, Loop ? DSBPLAY_LOOPING : 0);
//	temp->SetVolume(Volume);
//	m_Channels.push_back(temp);
//	return temp;
//}

LPDIRECTSOUNDBUFFER cSoundManager::Play(string key, int tag, bool Loop)
{
	LPDIRECTSOUNDBUFFER temp;
	m_Manager.GetDirectSound()->DuplicateSoundBuffer(m_Sounds[key]->GetBuffer(0), &temp);
	temp->Play(0, 0, Loop ? DSBPLAY_LOOPING : 0);
	if (tag == BGM)
		temp->SetVolume(m_BGM_Volume);
	else if (tag == SE)
		temp->SetVolume(m_SE_Volume);
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

int cSoundManager::GetVolume(int tag)
{
	int temp = 0;
	switch (tag)
	{
	case BGM:	temp = m_BGM_Volume;	break;
	case SE:	temp = m_SE_Volume;		break;
	default:							break;
	}
	return temp;
}

void cSoundManager::SetVolume(int value, int tag)
{
	switch (tag)
	{
	case BGM:	m_BGM_Volume = value;	break;
	case SE:	m_SE_Volume  = value;	break;
	default:							break;
	}
}
