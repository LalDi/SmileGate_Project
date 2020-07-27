#include "Framework.h"

cScene::cScene()
{
}

cScene::~cScene()
{
	RemoveAllObject();
}

/**
	@fn		AddObject(cGameObject*)

	@brief	오브젝트를 저장하는 변수에 새로운 오브젝트를 추가

	@param	p_pObject	- 추가될 오브젝트
*/
void cScene::AddObject(cGameObject* p_pObject)
{
	m_Objects.push_back(p_pObject);
}

/**
	@fn		RemoveObject(cGameObject*)

	@brief	오브젝트를 저장하는 변수에서 지정된 오브젝트를 제거

	@param	p_pObject	- 제거될 오브젝트
*/
void cScene::RemoveObject(cGameObject* p_pObject)
{
	std::list<cGameObject*>::iterator iter;
	for (iter = m_Objects.begin(); iter != m_Objects.end(); iter++) {
		if ((*iter) == p_pObject)
		{
			m_Objects.erase(iter);
			delete(&iter);
			break;
		}
	}
}

/**
	@fn		UpdateAllObject()

	@brief	저장된 모든 오브젝트의 기능을 실행시킨다.

	@remark	시간이 흐른다면 모든 오브젝트의 Update()를 실행시키고, 그 이후 UI의 Update()를 실행시킨다.
	@remark	오브젝트가 죽어있다면, 그 오브젝트를 삭제시킨다.
*/
void cScene::UpdateAllObject()
{
	if (b_Time)
		for (auto iter : m_Objects)
			if (iter->m_Tag != UI)
				iter->Update();

	for (auto iter : m_Objects)
		if (iter->m_Tag == UI)
			iter->Update();

	for (auto iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		if ((*iter)->b_IsLive == false)
		{
			if (*iter)
			{
				delete* iter;
				*iter = nullptr;
			}
			iter = m_Objects.erase(iter);
		}
		if (iter != m_Objects.end())
			iter++;
	}
}

/**
	@fn		RenderAllObject()

	@brief	저장된 모든 오브젝트를 화면에 출력시킨다.

	@remark	모든 오브젝트의 Render()를 실행시키고, 그 이후 ITEM의 Render()를 실행시키며, 마지막으로 UI의 Render()를 실행시킨다.
*/
void cScene::RenderAllObject()
{
	for (auto iter : m_Objects)
		if (iter->m_Tag != UI && iter->m_Tag != ITEM)
			iter->Render();
	for (auto iter : m_Objects)
		if (iter->m_Tag == ITEM)
			iter->Render();
	for (auto iter : m_Objects)
		if (iter->m_Tag == UI)
			iter->Render();
}

/**
	@fn		RenderAllObject()

	@brief	저장된 모든 오브젝트를 삭제시킨다.
*/
void cScene::RemoveAllObject()
{
	for (auto iter : m_Objects) 
	{
		if (iter) 
		{
			delete iter;
			iter = nullptr;
		}
	}
	m_Objects.clear();
}
