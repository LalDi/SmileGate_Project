#include "Framework.h"

/**
	@fn		Math::IsPointInRect(const RECT, const POINT)

	@brief	점과 사각형의 충돌 체크.

	@param	rt		- 충돌 여부를 확인할 사각형
	@param	pt		- 충돌 여부를 확인할 점

	@return	받아온 점과 사각형이 충돌한다면 true를 반환, 그 외의 경우에는 false를 반환.
*/
BOOL Math::IsPointInRect(const RECT rt, const POINT pt)
{
	if ((rt.left <= pt.x && rt.right >= pt.x) &&
		(rt.top <= pt.y && rt.bottom >= pt.y))
	{
		return TRUE;
	}

	return FALSE;
}

/**
	@fn		Math::IsPointInCircle(const POINT, const int, const POINT)

	@brief	점과 원의 충돌 체크.

	@param	ptCircle	- 충돌 여부를 확인할 원의 좌표
	@param	cr			- 충돌 여부를 확인할 원의 반지름
	@param	pt			- 충돌 여부를 확인할 점

	@return	받아온 점과 원이 충돌한다면 true를 반환, 그 외의 경우에는 false를 반환.
*/
BOOL Math::IsPointInCircle(const POINT ptCircle, const int cr, const POINT pt)
{
	float dx = ptCircle.x - pt.x;
	float dy = ptCircle.y - pt.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= cr) return TRUE;

	return FALSE;
}

/**
	@fn		Math::rtIntersectRect(const RECT, const RECT)

	@brief	사각형끼리의 충돌 범위.

	@param	rt1		- 충돌 여부를 확인할 사각형 1
	@param	rt2		- 충돌 여부를 확인할 사각형 2

	@return	받아온 두 사각형이 충돌한다면 충돌하는 범위의 RECT값을 반환
*/
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

/**
	@fn		Math::RectCrashCheck(const RECT, const RECT)

	@brief	사각형끼리의 충돌 체크.

	@param	rt1		- 충돌 여부를 확인할 사각형 1
	@param	rt2		- 충돌 여부를 확인할 사각형 2

	@return	받아온 두 사각형이 충돌한다면 true를 반환, 그 외의 경우에는 false를 반환.
*/
BOOL Math::RectCrashCheck(const RECT rt1, const RECT rt2)
{
	if (rt1.left < rt2.right &&
		rt1.top < rt2.bottom &&
		rt1.right > rt2.left&&
		rt1.bottom > rt2.top)
		return TRUE;
	return FALSE;
}

/**
	@fn		Math::CircleCrashCheck(POINT, int, POINT, int)

	@brief	원끼리의 충돌 체크.

	@param	ptCircle1	- 충돌 여부를 확인할 원의 좌표 1
	@param	r1			- 충돌 여부를 확인할 원의 반지름 1
	@param	ptCircle2	- 충돌 여부를 확인할 원의 좌표 2
	@param	r2			- 충돌 여부를 확인할 원의 반지름 2

	@return	받아온 두 원이 충돌한다면 true를 반환, 그 외의 경우에는 false를 반환.
*/
BOOL Math::CircleCrashCheck(POINT ptCircle1, int r1, POINT ptCircle2, int r2)
{
	float dx = ptCircle1.x - ptCircle2.x;
	float dy = ptCircle1.y - ptCircle2.y;
	float l = sqrt(dx * dx + dy * dy);

	if (l <= (r1 + r2)) return TRUE;

	return FALSE;
}

/**
	@fn		Math::RectCircleCrashCheck(POINT, int, const RECT)

	@brief	사각형과 원의 충돌 체크.

	@param	ptCircle	- 충돌 여부를 확인할 원의 좌표
	@param	r			- 충돌 여부를 확인할 원의 반지름
	@param	Rect		- 충돌 여부를 확인할 사각형

	@return	받아온 사각형과 원이 충돌한다면 true를 반환, 그 외의 경우에는 false를 반환.
*/
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

/**
	@fn		Math::Random(int, int)

	@brief	받아온 두 값을 각각 최소값과 최대값으로 하는 랜덤한 수를 반환

	@param	_Min	- 랜덤한 값의 최소값
	@param	_Max	- 랜덤한 값의 최대값
*/
int Math::Random(int _Min, int _Max)
{
	return _Min + rand() % (_Max - _Min + 1);
}

/**
	@fn		Math::Random(float, float)

	@brief	받아온 두 값을 각각 최소값과 최대값으로 하는 랜덤한 수를 반환

	@param	_Min	- 랜덤한 값의 최소값
	@param	_Max	- 랜덤한 값의 최대값
*/
float Math::Random(float _Min, float _Max)
{
	return _Min + (rand() | (rand() << 16)) % (int)(_Max * 10000 - _Min * 10000 + 1) * 0.0001;
}

/**
	@fn		Math::Random(float, float, float)

	@brief	어떤 값을 정해진 범위 내의 값으로 변경시켜줌

	@param	_Val	- 수치를 조절할 값
	@param	_Min	- 정해진 범위의 최소값
	@param	_Max	- 정해진 범위의 최대값
*/
float Math::Clamp(float _Val, float _Min, float _Max)
{
	return min(_Max, max(_Val, _Min));
}