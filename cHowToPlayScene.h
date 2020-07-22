#pragma once
class cHowToPlayScene : public cScene
{
private:
	cGameObject* m_Background;
	Page m_NowPage;

public:
	cHowToPlayScene();
	~cHowToPlayScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

