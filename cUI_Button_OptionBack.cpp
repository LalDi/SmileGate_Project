#include "Framework.h"

cUI_Button_OptionBack::cUI_Button_OptionBack(POINT Pos, int tag)
	:cUI_Button(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Title_Button_Back", "./Images/Title/Title_Back.png");
	b_IsCenter = true;
}

cUI_Button_OptionBack::~cUI_Button_OptionBack()
{
}

void cUI_Button_OptionBack::ClickButton()
{
	ofstream Data;
	Data.open("Data.ini");
	if (Data.is_open())
	{
		string str;
		str = to_string(SOUNDMANAGER->GetVolume(BGM));
		Data.write(str.c_str(), str.size());
		Data.write("\n", 1);
		str = to_string(SOUNDMANAGER->GetVolume(SE));
		Data.write(str.c_str(), str.size());
	}

	SOUNDMANAGER->StopAll();
	SCENEMANAGER->ChangeScene("Title");
}

void cUI_Button_OptionBack::Update()
{
	cUI_Button::Update();
}

void cUI_Button_OptionBack::Render()
{
	cUI_Button::Render();
}
