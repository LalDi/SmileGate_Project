#pragma once
/**
	@brief	씬의 기본적인 기능과 함수를 포함하는 클래스
	@brief	각 씬에 생성될 오브젝트를 모두 관리하는 변수와 함께 모든 오브젝트의 기능을 작동시킨다.
*/
class cScene abstract
{
protected:
	std::list<cGameObject*> m_Objects;	//  각 씬별로 생성되는 오브젝트가 저장되는 리스트
	bool b_Time = true;					//	씬 내에 시간이 흘러가는지 확인

public:
	cScene();
	virtual ~cScene();

	/**
		@fn		Init()

		@brief	게임의 기본 UI나 배경 등의 오브젝트를 생성시킴.
	*/
	virtual void Init() PURE;

	/**
		@fn		Update()
	
		@brief	그 씬의 내부 기능을 실행시킨다.
	
		@remark	각 태그별로 오브젝트의 세부적인 기능을 실행시킨다.
		@remark	주로 각 오브젝트별로 상호작용 기능을 작성하여 실행시킨다.
		@remark	일시정지같은 씬의 내부적인 기능도 포함한다.
	*/
	virtual void Update() PURE;

	/**
		@fn		Render()
	
		@brief	씬 내의 모든 오브젝트를 화면에 출력시킨다.
	*/
	virtual void Render() PURE;

	/**
		@fn		Release()
	
		@brief	그 씬 내부의 데이터를 삭제 시킨다.
	*/
	virtual void Release() PURE;

	void AddObject(cGameObject* p_pObject);
	void RemoveObject(cGameObject* p_pOjbect);

	void UpdateAllObject();
	void RenderAllObject();
	void RemoveAllObject();
};

