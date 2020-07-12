#pragma once

// DXUT ����
#include "DXUT.h"

// C ��Ÿ�� ��� ����
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// ���̺귯�� ����
#pragma comment (lib, "legacy_stdio_definitions.lib")

// �߰� ����
#include "cTexture.h"
#include "cUtility.h"

// ���� ������Ʈ
#include "cGameObject.h"
#include "cUI_Button.h"
#include "cUI_Gauge.h"

// Ÿ��Ʋ�� ������Ʈ
#include "cTitleBackground.h"
#include "cUI_Logo.h"
#include "cUI_Button_Gamestart.h"
#include "cUI_Button_HowToPlay.h"
#include "cUI_Button_Option.h"
#include "cUI_Button_Credit.h"
#include "cUI_Button_Quit.h"

// �ΰ��ӽ� ������Ʈ
#include "cIngameBackground.h"

#include "cPlayer.h"
#include "cEnemy.h"
#include "cEnemy1.h"
#include "cBullet.h"

#include "cItem.h"
#include "cItem_Hp.h"
#include "cItem_Power.h"
#include "cItem_Bomb.h"

#include "cUI_Background.h"
#include "cUI_Character.h"
#include "cUI_PlayerHp.h"
#include "cUI_Bomb.h"
#include "cUI_Taro.h"

// ���� ��
#include "cScene.h"
#include "cTitleScene.h"
#include "cIngameScene.h"

// ���� �Ŵ���
#include "cImageManager.h"
#include "cSceneManager.h"
#include "cInputManager.h"
#include "cGameManager.h"

// ���� ����
#include "cMainGame.h"


// ��ũ�� ����
using namespace std;
using namespace Math;

#define g_device DXUTGetD3D9Device()

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

#define LEFTCLICK 0
#define RIGHTCLICK 1

#define IMAGEMANAGER cGameManager::GetImageManager()
#define SCENEMANAGER cGameManager::GetSceneManager()
#define INPUTMANAGER cGameManager::GetInputManager()

enum TAGS 
{
	TEXTURE,
	PLAYER,
	ENEMY,
	BULLETP,
	BULLETE,
	ITEM,
	UI
};

const int WinSizeX = 1600;
const int WinSizeY = 900;
