#pragma once
/**
	@brief	인게임에서 사용될 UI중, 버튼 형식인 UI의 기본 기능을 갖는 클래스
*/
class cUI_Button : public cGameObject
{
protected:
	bool b_IsCenter = true;		// 버튼의 출력을 중앙을 기준으로 하는지 확인
	bool b_IsOnMouseUp = true;	// 버튼의 위에 마우스를 올렸을 때 버튼이 커지는 효과를 적용할 것 인지 확인

public:
	cUI_Button(POINT Pos, int tag);
	virtual ~cUI_Button();

	virtual void Update() override;
	virtual void Render() override;
	virtual void ClickButton() PURE; // 버튼을 클릭했을 때 동작할 함수

	bool CheckMouseOnButton(); // 버튼 위에 마우스가 올라갔는지 확인하는 함수
};

