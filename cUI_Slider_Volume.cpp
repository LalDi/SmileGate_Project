#include "Framework.h"

cUI_Slider_Volume::cUI_Slider_Volume(POINT Pos, int tag, int SoundTag)
	:cUI_Slider(Pos, tag)
{
	m_Sprite = IMAGEMANAGER->AddImage("Option_Volume", "./Images/Option/Option_Volume.png");
	m_BgSprite = IMAGEMANAGER->AddImage("Option_Volume_Background", "./Images/Option/Option_Volume_Background.png");
	m_HandleSprite = IMAGEMANAGER->AddImage("Option_Volume_Handle", "./Images/Option/Option_Volume_Handle.png");

	m_Max = 10000;
	m_Min = 7000;
	b_IsInteger = true;

	m_HandlePos = Pos;
	m_SoundTag = SoundTag;

	LONG Width = m_BgSprite->info.Width / 2;
	LONG Height = m_BgSprite->info.Height / 2;
	m_Rect = { Pos.x - Width, Pos.y - Height, Pos.x + Width, Pos.y + Height };

	float temp;
	temp = (float)((SOUNDMANAGER->GetVolume(m_SoundTag) + 10000) - m_Min) / (m_Max - m_Min);

	m_HandlePos.x = (Pos.x - Width) + temp * m_BgSprite->info.Width;
}

cUI_Slider_Volume::~cUI_Slider_Volume()
{
}

void cUI_Slider_Volume::Update()
{
	cUI_Slider::Update();

	if (m_Amount == m_Min)
		m_Amount = DSBVOLUME_MIN;
	else
		m_Amount -= 10000;

	SOUNDMANAGER->SetVolume(m_Amount, m_SoundTag);
}
