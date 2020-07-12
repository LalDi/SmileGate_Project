#pragma once
class cScene abstract
{
protected:
	std::list<cGameObject*> m_Objects;
	bool b_Time;

public:
	cScene();
	virtual ~cScene();

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;

	void AddObject(cGameObject* p_pObject);
	void RemoveObject(cGameObject* p_pOjbect);

	void UpdateAllObject();
	void RenderAllObject();
	void RemoveAllObject();
};

