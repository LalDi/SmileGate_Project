#pragma once

class cImageManager
{
private:
	LPD3DXSPRITE m_sprite;
	std::map<std::string, cTexture*> m_images;

private:
	void Init();
	void Release();

public:
	cImageManager();
	~cImageManager();

	cTexture* AddImage(const std::string& key, const std::string& path);
	cTexture* FindImage(const std::string& key);

	void Begin();
	void End();

	void Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, float rot = 0);
	//�»���� �������� �̹��� ������

	void CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, float rot = 0);
	//����� �������� �̹��� ������

	void LostDevice();
	void ResetDevice();
	//�Լ��� ���ڴ� �⺻������ 4������ ����ϴ°��� ����.(4���� �Ѿ�� �ް��� ��������)
	//�ڼ��� ������ ���߿� �������Ϳ� �ý��� ĳ�ø� �����Ҷ� �˾ƺ��� ����
};