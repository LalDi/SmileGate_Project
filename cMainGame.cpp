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

	// 선언한 매니저를 cGameManager에 전달
	cGameManager::Init(ImageManager, SceneManager, InputManager, SoundManager);	

	// INPUTMANAGER 생성
	INPUTMANAGER->Create(DXUTGetHWND());

	// SOUNDMANAGER 생성
	SOUNDMANAGER->Init();

	// 게임 내에 사용될 씬을 미리 추가
	SCENEMANAGER->AddScene("Title", new cTitleScene());
	SCENEMANAGER->AddScene("Ingame", new cIngameScene());

	// 게임 내에 사용될 사운드를 미리 추가
	SOUNDMANAGER->AddSound("Title", L"./Sounds/BGM/Title.wav");
	SOUNDMANAGER->AddSound("Stage1", L"./Sounds/BGM/Stage1.wav");
	SOUNDMANAGER->AddSound("Stage2", L"./Sounds/BGM/Stage2.wav");
	SOUNDMANAGER->AddSound("Stage3", L"./Sounds/BGM/Stage3.wav");

	SOUNDMANAGER->AddSound("Warning", L"./Sounds/SE/Warning.wav");
	SOUNDMANAGER->AddSound("ShootP", L"./Sounds/SE/PlayerShoot.wav");
	SOUNDMANAGER->AddSound("ShootE", L"./Sounds/SE/EnemyShoot.wav");
	SOUNDMANAGER->AddSound("Broken", L"./Sounds/SE/Broken.wav");

	SCENEMANAGER->ChangeScene("Title");
}

void cMainGame::Update()
{
	INPUTMANAGER->Update();
	SCENEMANAGER->Update();
	SOUNDMANAGER->Update();
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
