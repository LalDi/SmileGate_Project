#pragma once
class cCreditScene : public cScene
{
private:

public:
	cCreditScene();
	~cCreditScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

