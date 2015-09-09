//������ SDK ���α׷� �ۼ� - HelloSDK
#include	<windows.h>

LRESULT CALLBACK WndProc/**/(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

//WinMain -> 
int	WINAPI	WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//����ü���� �����Ͻð�
	WNDCLASS	wndclass;
	HWND		hwnd;
	MSG			msg;

	//1. ������ Ŭ������ ����(�ʱ�ȭ)�ϰ� �ü���� �����
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName="woongbini";
	wndclass.lpfnWndProc=WndProc; //�޼��� �ڵ鷯�� ��Ƶδ� �Լ� 
	
	//Win API - RegisterClass
	if(!RegisterClass(&wndclass)) return 1;

	//2. �����츦 �����ϰ� ȭ�鿡 ���̰� ��
	hwnd= CreateWindow("woongbini", "HelloSDK", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	hwnd= CreateWindow("woongbini", "HelloSDK", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	//�޼����� �������� �ٸ޼��� API
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
		MessageBox(hwnd, "���繮 ����", "Mouse Message", MB_OK);
		return 0;
	case	WM_PAINT:
		hdc= BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 100, str, lstrlen(str)); //������ ��ġ�� str����
		EndPaint(hwnd, &ps);
		return 0;
	case	WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	DefWindowProc(hwnd, message, wParam, lParam);
}