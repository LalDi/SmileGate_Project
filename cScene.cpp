#include "Framework.h"

cScene::cScene()
{
}

cScene::~cScene()
{
	RemoveAllObject();
}

void cScene::AddObject(cGameObject* p_pObject)
{
	m_Objects.push_back(p_pObject);
}

void cScene::RemoveObject(cGameObject* p_pObject)
{
	std::list<cGameObject*>::iterator iter;
	for (iter = m_Objects.begin(); iter != m_Objects.end(); iter++) {
		if ((*iter) == p_pObject)
		{
			m_Objects.erase(iter);
			break;
		}
	}
}

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
