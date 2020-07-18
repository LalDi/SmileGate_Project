#pragma once

// DXUT 파일
#include "DXUT.h"
#include "SDKsound.h"
#include "SDKwavefile.h"

// C 런타임 헤더 파일
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <wchar.h>

// 라이브러리 파일
#pragma comment (lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "dsound.lib")

#include "cUtility.h"

// 네임스페이스 생략
using namespace std;
using namespace Math;

// 추가 파일
#include "cTexture.h"

// 게임 오브젝트
#include "cGameObject.h"
#include "cUI_Button.h"
#include "cUI_Gauge.h"

// 타이틀씬 오브젝트
#include "cTitleBackground.h"
#include "cUI_Logo.h"
#include "cUI_Button_Gamestart.h"
#include "cUI_Button_HowToPlay.h"
#include "cUI_Button_Option.h"
#include "cUI_Button_Credit.h"
#include "cUI_Button_Quit.h"

// 크레딧씬 오브젝트
#include "cCreditBackground.h"
#include "cUI_Button_Back.h"

// 인게임씬 오브젝트
#include "cIngameBackground.h"

#include "cPlayer.h"
#include "cEnemy.h"
#include "cEnemy1.h"
#include "cBoss.h"
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
#include "cUI_Score.h"

#include "cUI_Pause_Background.h"
#include "cUI_Button_Pause_Resume.h"
#include "cUI_Button_Pause_Reset.h"
#include "cUI_Button_Pause_Title.h"

#include "cUI_Gameover_Background.h"
#include "cUI_Button_Gameover_Restart.h"
#include "cUI_Button_Gameover_Title.h"


// 게임 씬
#include "cScene.h"
#include "cTitleScene.h"
#include "cCreditScene.h"
#include "cIngameScene.h"

// 게임 매니저
#include "cImageManager.h"
#include "cSceneManager.h"
#include "cInputManager.h"
#include "cSoundManager.h"
#include "cGameManager.h"

// 게임 메인
#include "cMainGame.h"


// 매크로 생성
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
#define SOUNDMANAGER cGameManager::GetSoundManager()

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
