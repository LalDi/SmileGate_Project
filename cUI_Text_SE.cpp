#include "Framework.h"

cUI_Text_SE::cUI_Text_SE(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Option_Text_SE", "./Images/Option/Option_Sound Effect.png");
}

cUI_Text_SE::~cUI_Text_SE()
{
}

void cUI_Text_SE::Update()
{
}

void cUI_Text_SE::Render()
{
	m_Sprite->CenterRender(m_Pos);
}
