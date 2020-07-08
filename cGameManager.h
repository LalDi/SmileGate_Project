#pragma once
class cGameManager
{
private:
	static cImageManager* m_ImageManager;
	static cSceneManager* m_SceneManager;
	static cInputManager* m_InputManager;

public:
	cGameManager();
	~cGameManager();

	static void Init(cImageManager* ImageMgr, cSceneManager* SceneMgr, cInputManager* InputMgr);

	static cImageManager* GetImageManager() { return m_ImageManager; }
	static cSceneManager* GetSceneManager() { return m_SceneManager; }
	static cInputManager* GetInputManager() { return m_InputManager; }
};