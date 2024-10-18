#include "Time.h"
#include "pTime.h"
namespace p {
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;
	void Time::Initialize()
	{
		//cpu�� ����������
		QueryPerformanceFrequency(&CpuFrequency);
		//���α׷��� ���� ���� �� ���� ���� ��
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		// Update�Ǿ�����/������ -> deltaTime
		QueryPerformanceCounter(&CurrentFrequency);
		float differenceFrequency = static_cast<float> (CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		//���̸� cpu������������ ������ �ð� ����
		DeltaTimeValue = differenceFrequency / static_cast<float> (CpuFrequency.QuadPart);

		//���� �������� ���� �������� ������Ʈ
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render()
	{
		static float time = 0.0f;
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		

		//TextOutW(, 0, 0, str, len);
	}
}