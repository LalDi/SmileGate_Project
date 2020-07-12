#include "Framework.h"

BOOL Math::IsPointInRect(const RECT rt, const POINT pt)
{
	if ((rt.left <= pt.x && rt.right >= pt.x) &&
		(rt.top <= pt.y && rt.bottom >= pt.y))
	{
		return TRUE;
	}

	return FALSE;
}

BOOL Math::IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt)
{
	float dx = ptCircle.x - pt.x;
	float dy = ptCircle.y - pt.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= cr) return TRUE;

	return FALSE;
}

RECT* Math::rtIntersectRect(const RECT rt1, const RECT rt2)
{
	RECT* pIntersect = new RECT();
	*pIntersect = RECT{ 0,0,0,0 };

	if (rt1.left < rt2.right && rt1.right > rt2.left)
	{
		pIntersect->left = max(rt1.left, rt2.left);
		pIntersect->right = min(rt1.right, rt2.right);
	}
	if (rt1.top < rt2.bottom && rt1.bottom > rt2.top)
	{
		pIntersect->top = max(rt1.top, rt2.top);
		pIntersect->bottom = min(rt1.bottom, rt2.bottom);
	}

	return pIntersect;
}

BOOL Math::RectCrashCheck(const RECT rt1, const RECT rt2)
{
	if (rt1.left < rt2.right &&
		rt1.top < rt2.bottom &&
		rt1.right > rt2.left&&
		rt1.bottom > rt2.top)
		return TRUE;
	return FALSE;
}

BOOL Math::CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2)
{
	float dx = ptCircle1.x - ptCircle2.x;
	float dy = ptCircle1.y - ptCircle2.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= (r1 + r2)) return TRUE;

	return FALSE;
}

BOOL Math::RectCircleCrashCheck(POINT ptCircle, int r, const RECT Rect)
{
	if (IsPointInRect(Rect, ptCircle))
	{
		RECT temp = {
			Rect.left - r,
			Rect.top - r,
			Rect.right + r,
			Rect.bottom + r
		};
		if (IsPointInRect(temp, ptCircle))
			return TRUE;
	}
	else
	{
		if (IsPointInCircle(ptCircle, r, POINT{ Rect.left,	Rect.top }))	return TRUE;
		if (IsPointInCircle(ptCircle, r, POINT{ Rect.left,	Rect.bottom }))	return TRUE;
		if (IsPointInCircle(ptCircle, r, POINT{ Rect.right, Rect.top }))	return TRUE;
		if (IsPointInCircle(ptCircle, r, POINT{ Rect.right, Rect.bottom })) return TRUE;
	}
	return FALSE;
}

int Math::Random(int _Min, int _Max)
{
	return _Min + rand() % (_Max - _Min + 1);
}

float Math::Random(float _Min, float _Max)
{
	return _Min + (rand() | (rand() << 16)) % (int)(_Max * 10000 - _Min * 10000 + 1) * 0.0001;
}

float Math::Clamp(float _Val, float _Min, float _Max)
{
	return min(_Max, max(_Val, _Min));
}