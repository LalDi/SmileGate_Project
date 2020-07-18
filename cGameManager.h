#pragma once
/**
	@brief	게임 내에서 사용되는 매니저를 생성하고 관리하는 매니저

	@remark	매니저는 프로그램 내에 하나만 생성되어야 한다.
	@remark	그러나 싱글톤 패턴은 객체지향 프로그램에 부적절하기도 하고, 오류를 유발하기도 쉬워서 사용하지 않는다.
	@remark	싱글톤 역할을 하기 위해 모든 매니저를 cGameManager클래스에 선언하여 여기서 받아 사용한다.
*/
class cGameManager
{
private:
	static cImageManager* m_ImageManager;
	static cSceneManager* m_SceneManager;
	static cInputManager* m_InputManager;
	static cSoundManager* m_SoundManager;

public:
	cGameManager();
	~cGameManager();

	static void Init(cImageManager* ImageMgr, cSceneManager* SceneMgr, cInputManager* InputMgr, cSoundManager* SoundMgr);

	static cImageManager* GetImageManager() { return m_ImageManager; }
	static cSceneManager* GetSceneManager() { return m_SceneManager; }
	static cInputManager* GetInputManager() { return m_InputManager; }
	static cSoundManager* GetSoundManager() { return m_SoundManager; }
};