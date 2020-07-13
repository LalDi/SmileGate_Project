#pragma once

class cImageManager
{
private:
	LPD3DXSPRITE m_sprite;
	map<std::string, cTexture*> m_images;
	map<string, vector<cTexture*>*> m_Animations;
	LPD3DXFONT m_Fonts[33];
	LPD3DXFONT m_FontsKor[33];
	D3DXMATRIX m_Mat;

private:
	void Init();
	void Release();

public:
	cImageManager();
	~cImageManager();

	cTexture* AddImage(const string& key, const string& path);
	cTexture* FindImage(const string& key);
	vector<cTexture*>* AddAnimation(string key, const string& path, int amount);
	vector<cTexture*>* FindAnimation(string key);


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

	void RenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRenderText(wstring Text, int Size, POINT Pos, float Scale, bool Kor, D3DCOLOR Color = D3DCOLOR_XRGB(255, 255, 255));
	// �ؽ�Ʈ ������

	void LostDevice();
	void ResetDevice();
	//�Լ��� ���ڴ� �⺻������ 4������ ����ϴ°��� ����.(4���� �Ѿ�� �ް��� ��������)
	//�ڼ��� ������ ���߿� �������Ϳ� �ý��� ĳ�ø� �����Ҷ� �˾ƺ��� ����
};