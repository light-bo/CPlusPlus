#include "test.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, 
					LPWSTR lpCmdLine, int nShowCmd) {
	MSG msg;

	//注册窗口
	if(!registerWnd(hInstance))
		return 1;

	//显示窗口
	if(!showMainWnd(hInstance, lpCmdLine, nShowCmd))
		return 2;

	//消息循环
	while( GetMessage(&msg, NULL, 0, 0) ) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	//退出窗口
	return quitMainWnd(hInstance, msg.wParam);
}

