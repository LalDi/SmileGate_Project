#pragma once
/**
	@brief	���� ������ ���Ǵ� �Ŵ����� �����ϰ� �����ϴ� �Ŵ���

	@remark	�Ŵ����� ���α׷� ���� �ϳ��� �����Ǿ�� �Ѵ�.
	@remark	�׷��� �̱��� ������ ��ü���� ���α׷��� �������ϱ⵵ �ϰ�, ������ �����ϱ⵵ ������ ������� �ʴ´�.
	@remark	�̱��� ������ �ϱ� ���� ��� �Ŵ����� cGameManagerŬ������ �����Ͽ� ���⼭ �޾� ����Ѵ�.
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