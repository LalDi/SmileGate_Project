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

	@brief	������Ʈ�� �����ϴ� ������ ���ο� ������Ʈ�� �߰�

	@param	p_pObject	- �߰��� ������Ʈ
*/
void cScene::AddObject(cGameObject* p_pObject)
{
	m_Objects.push_back(p_pObject);
}

/**
	@fn		RemoveObject(cGameObject*)

	@brief	������Ʈ�� �����ϴ� �������� ������ ������Ʈ�� ����

	@param	p_pObject	- ���ŵ� ������Ʈ
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

	@brief	����� ��� ������Ʈ�� ����� �����Ų��.

	@remark	�ð��� �帥�ٸ� ��� ������Ʈ�� Update()�� �����Ű��, �� ���� UI�� Update()�� �����Ų��.
	@remark	������Ʈ�� �׾��ִٸ�, �� ������Ʈ�� ������Ų��.
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

	@brief	����� ��� ������Ʈ�� ȭ�鿡 ��½�Ų��.

	@remark	��� ������Ʈ�� Render()�� �����Ű��, �� ���� ITEM�� Render()�� �����Ű��, ���������� UI�� Render()�� �����Ų��.
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

	@brief	����� ��� ������Ʈ�� ������Ų��.
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
