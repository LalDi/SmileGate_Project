#pragma once
class cSceneManager
{
private:
	//cScene temp; //클래스 전방선언시에는 클래스의 포인터만 사용할수 있다
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