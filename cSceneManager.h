#pragma once
/**
	@brief 게임의 씬들을 관리하는 매니저.
	@brief 현재 씬의 작동, 씬 전환 등의 기능을 한다.
*/
class cSceneManager
{
private:
	cScene* m_nowScene;		// 현재 씬
	cScene* m_nextScene;	// 새로 전환될 씬의 예약
	std::map<std::string, cScene*> m_scenes;	// 씬이 저장될 변수

	void Release();
public:
	cSceneManager();
	~cSceneManager();

	cScene* AddScene(const std::string& key, cScene* scenePtr);
	cScene* ChangeScene(const std::string& key);

	void Update();
	void Render();
};