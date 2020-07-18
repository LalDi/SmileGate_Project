#pragma once
class cItem : public cGameObject
{
protected:
	cPlayer* m_Player;	// �������� ȿ���� �����ų �÷��̾��� ������
	int* m_Score;		// �������� ȿ���� �����ų �������� ������	

	float m_Speed;		

public:
	cItem(POINT Pos, int tag, cPlayer* Player, int* Score);
	virtual ~cItem();

	virtual void Update() override;
	virtual void Render() override;

	bool CheckOutMap();				// �������� �� ������ �������� Ȯ���ϴ� �Լ�
	virtual void GetItem() PURE;	// �÷��̾ �������� ȹ���Ͽ��� �� �۵��ϴ� �Լ�
};

