#pragma once
/**
	@brief ������ ������ �����ϴ� �Ŵ���.
	@brief ���� ���� �۵�, �� ��ȯ ���� ����� �Ѵ�.
*/
class cSceneManager
{
private:
	cScene* m_nowScene;		// ���� ��
	cScene* m_nextScene;	// ���� ��ȯ�� ���� ����
	std::map<std::string, cScene*> m_scenes;	// ���� ����� ����

	void Release();
public:
	cSceneManager();
	~cSceneManager();

	cScene* AddScene(const std::string& key, cScene* scenePtr);
	cScene* ChangeScene(const std::string& key);

	void Update();
	void Render();
};