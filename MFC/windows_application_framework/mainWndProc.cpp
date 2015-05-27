#include "test.h"

const TCHAR mainClassName[] = TEXT("myFirst");

HINSTANCE hInst;

//窗口响应的消息
const MessageProc mainMessages[] = {
	WM_CREATE, goCreateMain, 
	WM_PAINT, goPaintMain,
	WM_DESTROY, goDestoryMain,
	WM_CLOSE, goCloseMain, 
};

/*注册窗口，注册成功返回 1， 否则返回 0*/
int registerWnd(HINSTANCE hInstance) {

	//配置窗口
	WNDCLASS wc;
	wc.hInstance = hInstance;

	wc.lpszClassName = mainClassName;//窗口类型名称
	wc.lpfnWndProc = mainWndProc;//窗口过程（重要）

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.style = CS_DBLCLKS;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	//注册窗口，系统调用
	if(!RegisterClass(&wc))
		return 0;

	return 1;
}

/*显示窗口*/
int showMainWnd(HINSTANCE hInstance, LPWSTR lpCmdLine, int nShowCmd) {
	HWND hWnd;
	hInst = hInstance;
	
	hWnd = CreateWindow(
		mainClassName,

		TEXT("light"),//窗口标题
		WS_VISIBLE,
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	
	if(!IsWindow(hWnd))
		return 0;
	
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);

	return 1;
}

int quitMainWnd(HINSTANCE hInstance, int nExitCode) {
	return nExitCode;
}

//窗口过程，分析相应的消息，调用相应的消息处理函数
LRESULT CALLBACK mainWndProc(HWND hWnd, UINT msgCode, WPARAM wParam,
		LPARAM lParam) {
	int i;
	for(i=0; i<dim(mainMessages); ++i) {
		if(msgCode == mainMessages[i].uCode)
			return (*mainMessages[i].funtionName) (hWnd, msgCode, wParam, lParam);
	}

	//找不到用户自定义的消息处理函数，调用系统默认处理函数
	return DefWindowProc(hWnd, msgCode, wParam, lParam);
}


LRESULT goCreateMain(HWND hWnd, UINT msgCode, WPARAM wParam, LPARAM lParam) {
	HWND wndCB;
	wndCB = CommandBar_Create(hInst, hWnd, IDC_CMDBAR);

	CommandBar_AddAdornments(wndCB, 0, 0);
	return 0;
}


//当窗口发生改变时，WM_PAINT 消息的响应函数
LRESULT goPaintMain(HWND hWnd, UINT msgCode, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	RECT rect;
	HDC hdc;
	GetClientRect(hWnd, &rect);

	rect.top += CommandBar_Height(GetDlgItem(hWnd, IDC_CMDBAR));

	hdc = BeginPaint(hWnd, &ps);
	
	DrawText(hdc, TEXT("windows CE"), -1, &rect,
		DT_CENTER | DT_VCENTER|DT_SINGLELINE); EndPaint(hWnd, &ps); 

	EndPaint(hWnd, &ps);
	return 0;
}


LRESULT goDestoryMain(HWND hWnd, UINT msgCode, WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(1);
	return 0;
}


LRESULT goCloseMain(HWND hWnd, UINT msgCode, WPARAM wParam, LPARAM lParam) {
	int idCode;

	idCode = MessageBox(hWnd, TEXT("确定退出程序吗？"), TEXT("退出"), MB_YESNO | MB_ICONQUESTION);
	if(idCode == IDNO)
		return 0;

	//PostDestroyMessage(1);
	PostQuitMessage(1);
	return 0;

}
