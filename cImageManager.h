#pragma once
/**
	@brief ���α׷��� ȭ�� ��� ������ �����ϴ� �Ŵ���
	@brief �̹��������� ����, �̹��� �� �ؽ�Ʈ�� ����� �Ѵ�.
*/
class cImageManager
{
private:
	LPD3DXSPRITE m_sprite;
	map<std::string, cTexture*> m_images;			// �̹��� ���Ͽ� �̸��� �ٿ� ����
	map<string, vector<cTexture*>*> m_Animations;	// �ִϸ��̼� ���Ͽ� �̸��� �ٿ� ����
	LPD3DXFONT m_Fonts[33];							// ���� ��Ʈ
	LPD3DXFONT m_FontsKor[33];						// �ѱ� ��Ʈ
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

	void Render(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot = 0, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void Render(cTexture* texturePtr, float x, float y, float rot = 0);
	//�»���� �������� �̹��� ������

	void CenterRender(cTexture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, POINT size, float rot, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, RECT rect, POINT size, float rot = 0, D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRender(cTexture* texturePtr, float x, float y, float rot = 0);
	//����� �������� �̹��� ������

	void RenderText(wstring Text, int Size, POINT Pos, float Scale = 1, bool Kor = false, D3DCOLOR Color = D3DCOLOR_RGBA(255, 255, 255, 255));
	void CenterRenderText(wstring Text, int Size, POINT Pos, float Scale = 1, bool Kor = false, D3DCOLOR Color = D3DCOLOR_RGBA(255, 255, 255, 255));
	// �ؽ�Ʈ ������

	void LostDevice();
	void ResetDevice();
};