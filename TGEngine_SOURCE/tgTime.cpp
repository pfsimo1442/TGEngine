#include "tgTime.h"

namespace tg
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;
	
	void Time::Initialize()
	{
		QueryPerformanceFrequency(&CpuFrequency);
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str1[50] = L"";
		wchar_t str2[50] = L"";
		wchar_t str3[50] = L"";
		swprintf_s(str1, 50, L"Time: %f", time);
		swprintf_s(str2, 50, L"DeltaTime: %f", DeltaTimeValue);
		swprintf_s(str3, 50, L"FPS: %d", (int)fps);
		size_t len1 = wcsnlen_s(str1, 50);
		size_t len2 = wcsnlen_s(str2, 50);
		size_t len3 = wcsnlen_s(str3, 50);

		TextOut(hdc, 0, 0, str1, (int)len1);
		TextOut(hdc, 0, 20, str2, (int)len2);
		TextOut(hdc, 0, 40, str3, (int)len3);
	}
}