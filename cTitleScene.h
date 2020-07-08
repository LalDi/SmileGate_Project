#pragma once
class cTitleScene : public cScene
{
private:

public:
	cTitleScene();
	~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};

