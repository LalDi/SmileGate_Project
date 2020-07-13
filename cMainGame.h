#pragma once
class cMainGame
{
private:
	cImageManager* ImageManager;
	cSceneManager* SceneManager;
	cInputManager* InputManager;
	cSoundManager* SoundManager;

public:
	cMainGame();
	~cMainGame();

	void Init();
	void Update();
	void Render();
	void Release();

	void LostDevice();
	void ResetDevice();
};