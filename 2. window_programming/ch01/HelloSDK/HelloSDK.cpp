//간단한 SDK 프로그램 작성 - HelloSDK
#include	<windows.h>

LRESULT CALLBACK WndProc/**/(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

//WinMain -> 
int	WINAPI	WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//구조체변수 선언하시고
	WNDCLASS	wndclass;
	HWND		hwnd;
	MSG			msg;

	//1. 윈도우 클래스를 정의(초기화)하고 운영체제에 등록함
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName="woongbini";
	wndclass.lpfnWndProc=WndProc; //메세지 핸들러를 담아두는 함수 
	
	//Win API - RegisterClass
	if(!RegisterClass(&wndclass)) return 1;

	//2. 윈도우를 생성하고 화면에 보이게 함
	hwnd= CreateWindow("woongbini", "HelloSDK", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	hwnd= CreateWindow("woongbini", "HelloSDK", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	//메세지를 가져오는 겟메세지 API
	while(GetMessage(&msg, NULL, 0, 0)>0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;
	char	*str= "Hello SDK";

	switch(message)	{
		//WM -> Window Message
	case	WM_CREATE:
		return 0;

	case	WM_LBUTTONDOWN:
		MessageBox(hwnd, "Click Mouse", "Mouse Message", MB_OK);
		return 0;
	case	WM_RBUTTONDOWN:
		MessageBox(hwnd, "이재문 만세", "Mouse Message", MB_OK);
		return 0;
	case	WM_PAINT:
		hdc= BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 100, str, lstrlen(str)); //지정된 위치에 str찍어라
		EndPaint(hwnd, &ps);
		return 0;
	case	WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	DefWindowProc(hwnd, message, wParam, lParam);
}