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
	
	@brief	����� ������ ���ο� ���� �̸����� ����.

	@remark	������ ���ο� ���� �����ϴ� ����. �ٸ�, ������ ���Ҹ��� �ñ� ������ ���� ��ȯ�� �̷������ �ʴ´�.

	@param	key			- ���� ������ �̸�.
	@param	scenePtr	- ������ ���� Ŭ����
*/
cScene* cSceneManager::AddScene(const std::string& key, cScene* scenePtr)
{
	if (!scenePtr)//� ������ ���� ���� �־����� �߰����� �ʴ´�
		return nullptr;

	if (m_scenes.find(key) != m_scenes.end())//�̸��� ��ġ�� �ص� �߰����� �ʴ´�
		return nullptr;

	m_scenes.insert(make_pair(key, scenePtr));//���� ������ ������� ������ �߰��Ѵ�
	return scenePtr;
}

/**
	@fn		ChangeScene(string&)

	@brief	���� ���� �ٸ� ������ ��ȯ

	@remark	����� �������� �̸��� ã�� �� ������ ���� ��ȯ. ���� �����δ� ��ȯ���� �ʴ´�.

	@param	key			- ���� ã�� �̸�.
*/
cScene* cSceneManager::ChangeScene(const std::string& key)
{
	auto find = m_scenes.find(key);
	if (find == m_scenes.end())
		return nullptr;//���� �����δ� �ٲ��� �ʴ´�

	m_nextScene = find->second;//�ٲ� ���� �����صд�
	return m_nextScene;
}

void cSceneManager::Update()
{
	if (m_nextScene)//������� ���� �ִ��� Ȯ���غ���
	{
		if (m_nowScene)//���� ���� ������
			m_nowScene->Release();//����ְ�
		m_nextScene->Init();
		m_nowScene = m_nextScene;//���� �ٲ��ش�
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
