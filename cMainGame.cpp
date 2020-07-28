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

	// ������ �Ŵ����� cGameManager�� ����
	cGameManager::Init(ImageManager, SceneManager, InputManager, SoundManager);	

	// INPUTMANAGER ����
	INPUTMANAGER->Create(DXUTGetHWND());

	// SOUNDMANAGER ����
	SOUNDMANAGER->Init();

	// ���� ���� ���� ���� �̸� �߰�
	SCENEMANAGER->AddScene("Title", new cTitleScene());
	SCENEMANAGER->AddScene("Ingame", new cIngameScene());

	// ���� ���� ���� ���带 �̸� �߰�
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
