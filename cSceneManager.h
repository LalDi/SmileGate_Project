#pragma once
class cSceneManager
{
private:
	//cScene temp; //Ŭ���� ���漱��ÿ��� Ŭ������ �����͸� ����Ҽ� �ִ�
	cScene* m_nowScene;
	cScene* m_nextScene;
	std::map<std::string, cScene*> m_scenes;

	void Release();
public:
	cSceneManager();
	~cSceneManager();

	cScene* AddScene(const std::string& key, cScene* scenePtr);
	cScene* ChangeScene(const std::string& key);

	void Update();
	void Render();
};