#include "Framework.h"

cMainGame::cMainGame()
{
	ImageManager = nullptr;
	SceneManager = nullptr;
	InputManager = nullptr;
	SoundManager = nullptr;
}

cMainGame::~cMainGame()
{
	Release();
}

void cMainGame::Init()
{
	srand(time(NULL));

	ImageManager = new cImageManager();
	SceneManager = new cSceneManager();
	InputManager = new cInputManager();
	SoundManager = new cSoundManager();

	InputManager->Create(DXUTGetHWND());

	cGameManager::Init(ImageManager, SceneManager, InputManager, SoundManager);

	SCENEMANAGER->AddScene("Title", new cTitleScene());
	SCENEMANAGER->AddScene("Ingame", new cIngameScene());

	SCENEMANAGER->ChangeScene("Title");
}

void cMainGame::Update()
{
	INPUTMANAGER->Update();
	SCENEMANAGER->Update();
}

void cMainGame::Render()
{
	IMAGEMANAGER->Begin();
	SCENEMANAGER->Render();
	IMAGEMANAGER->End();
}

void cMainGame::Release()
{
	if (ImageManager) {
		delete ImageManager;
		ImageManager = nullptr;
	}

	if (SceneManager)
	{
		delete SceneManager;
		SceneManager = nullptr;
	}
	if (InputManager)
	{
		delete InputManager;
		InputManager = nullptr;
	}
	if (SoundManager)
	{
		delete SoundManager;
		SoundManager = nullptr;
	}
}

void cMainGame::LostDevice()
{
	
}

void cMainGame::ResetDevice()
{
}
