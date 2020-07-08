#pragma once
class cMainGame
{
private:
	cImageManager* ImageManager;
	cSceneManager* SceneManager;
	cInputManager* InputManager;

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