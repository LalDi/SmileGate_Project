#include "Framework.h"

cSceneManager::cSceneManager()
	:m_nowScene(nullptr), m_nextScene(nullptr)
{
}

cSceneManager::~cSceneManager()
{
	Release();
}

/**
	@fn		AddScene(string&, cScene*)
	
	@brief	저장된 변수에 새로운 씬을 이름으로 저장.

	@remark	변수에 새로운 씬을 저장하는 역할. 다만, 저장의 역할만을 맡기 때문에 씬의 변환은 이루어지지 않는다.

	@param	key			- 씬을 저장할 이름.
	@param	scenePtr	- 저장할 씬의 클래스
*/
cScene* cSceneManager::AddScene(const std::string& key, cScene* scenePtr)
{
	if (!scenePtr)//어떤 이유로 없는 씬을 넣었을땐 추가하지 않는다
		return nullptr;

	if (m_scenes.find(key) != m_scenes.end())//이름이 겹치려 해도 추가하지 않는다
		return nullptr;

	m_scenes.insert(make_pair(key, scenePtr));//위의 사항이 적용되지 않으면 추가한다
	return scenePtr;
}

/**
	@fn		ChangeScene(string&)

	@brief	현재 씬을 다른 씬으로 전환

	@remark	저장된 변수에서 이름을 찾아 그 씬으로 씬을 전환. 없는 씬으로는 전환되지 않는다.

	@param	key			- 씬을 찾을 이름.
*/
cScene* cSceneManager::ChangeScene(const std::string& key)
{
	auto find = m_scenes.find(key);
	if (find == m_scenes.end())
		return nullptr;//없는 씬으로는 바꾸지 않는다

	m_nextScene = find->second;//바꿀 씬을 예약해둔다
	return m_nextScene;
}

void cSceneManager::Update()
{
	if (m_nextScene)//대기중인 씬이 있는지 확인해본다
	{
		if (m_nowScene)//현재 씬이 있으면
			m_nowScene->Release();//비워주고
		m_nextScene->Init();
		m_nowScene = m_nextScene;//씬을 바꿔준다
		m_nextScene = nullptr;
	}
	if (m_nowScene)
		m_nowScene->Update();
}

void cSceneManager::Render()
{
	if (m_nowScene)
		m_nowScene->Render();
}

void cSceneManager::Release()
{
	if (m_nowScene)
		m_nowScene->Release();

	for (auto iter : m_scenes)
	{
		SAFE_DELETE(iter.second);
	}
	m_scenes.clear();
}
