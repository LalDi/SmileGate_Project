#pragma once
class cUI_Slider_Volume : public cUI_Slider
{
private:
	int m_SoundTag;

public:
	cUI_Slider_Volume(POINT Pos, int tag, int SoundTag);
	~cUI_Slider_Volume();

	virtual void Update() override;
};

