#pragma once
enum class Page
{
	Page1,
	Page2,
};
class cHTPBackground : public cGameObject
{
private:
	Page* m_Page;
	cTexture* m_Sprite2;

public:
	cHTPBackground(POINT Pos, int tag, Page* Page);
	~cHTPBackground();

	virtual void Update() override;
	virtual void Render() override;
};

