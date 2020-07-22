#pragma once
class cTitleScene : public cScene
{
private:
	static bool b_IsPlayBgm;

public:
	cTitleScene();
	~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void SetPlayBgm(bool value) { b_IsPlayBgm = value; }
};

