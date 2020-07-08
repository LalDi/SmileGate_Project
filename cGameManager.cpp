#include "Framework.h"

cImageManager* cGameManager::m_ImageManager = NULL;
cSceneManager* cGameManager::m_SceneManager = NULL;
cInputManager* cGameManager::m_InputManager = NULL;

cGameManager::cGameManager()
{
}

cGameManager::~cGameManager()
{
}

void cGameManager::Init(cImageManager* ImageMgr, cSceneManager* SceneMgr, cInputManager* InputMgr)
{
	m_ImageManager = ImageMgr;
	m_SceneManager = SceneMgr;
	m_InputManager = InputMgr;
}
