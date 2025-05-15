/*
	1. 윈도우 클래스 속성 설정 WNDCLASS
	2. 윈도우 클래스 등록 RegisterClass
	3. 윈도우 인스턴스 생성 CreateWindow
	4. 윈도우 인스턴스 시각화 ShowWindow
	5. 메세지 루프 MSG Message; While(GetMessage) DispatchMessage;
*/

#include <Windows.h>

#define ID_BUTTON 1001

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = L"MyWindowClass";

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		L"CreateWindowEx",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
		NULL, NULL, hInstance, NULL
	);

	if (hwnd == NULL) return 0;

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}