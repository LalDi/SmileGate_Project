#pragma once
/**
	@brief	���� �⺻���� ��ɰ� �Լ��� �����ϴ� Ŭ����
	@brief	�� ���� ������ ������Ʈ�� ��� �����ϴ� ������ �Բ� ��� ������Ʈ�� ����� �۵���Ų��.
*/
class cScene abstract
{
protected:
	std::list<cGameObject*> m_Objects;	//  �� ������ �����Ǵ� ������Ʈ�� ����Ǵ� ����Ʈ
	bool b_Time = true;					//	�� ���� �ð��� �귯������ Ȯ��

public:
	cScene();
	virtual ~cScene();

	/**
		@fn		Init()

		@brief	������ �⺻ UI�� ��� ���� ������Ʈ�� ������Ŵ.
	*/
	virtual void Init() PURE;

	/**
		@fn		Update()
	
		@brief	�� ���� ���� ����� �����Ų��.
	
		@remark	�� �±׺��� ������Ʈ�� �������� ����� �����Ų��.
		@remark	�ַ� �� ������Ʈ���� ��ȣ�ۿ� ����� �ۼ��Ͽ� �����Ų��.
		@remark	�Ͻ��������� ���� �������� ��ɵ� �����Ѵ�.
	*/
	virtual void Update() PURE;

	/**
		@fn		Render()
	
		@brief	�� ���� ��� ������Ʈ�� ȭ�鿡 ��½�Ų��.
	*/
	virtual void Render() PURE;

	/**
		@fn		Release()
	
		@brief	�� �� ������ �����͸� ���� ��Ų��.
	*/
	virtual void Release() PURE;

	void AddObject(cGameObject* p_pObject);
	void RemoveObject(cGameObject* p_pOjbect);

	void UpdateAllObject();
	void RenderAllObject();
	void RemoveAllObject();
};

