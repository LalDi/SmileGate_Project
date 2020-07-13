#include "Framework.h"

cCreditBackground::cCreditBackground(POINT Pos, int tag)
	:cGameObject(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Credit_Background", "./Images/Credit/Title_Credit_Background.png");
}

cCreditBackground::~cCreditBackground()
{
}

void cCreditBackground::Update()
{
}

void cCreditBackground::Render()
{
	m_Sprite->Render(m_Pos);
}
