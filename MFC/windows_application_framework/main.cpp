#include "test.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, 
					LPWSTR lpCmdLine, int nShowCmd) {
	MSG msg;

	//ע�ᴰ��
	if(!registerWnd(hInstance))
		return 1;

	//��ʾ����
	if(!showMainWnd(hInstance, lpCmdLine, nShowCmd))
		return 2;

	//��Ϣѭ��
	while( GetMessage(&msg, NULL, 0, 0) ) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	//�˳�����
	return quitMainWnd(hInstance, msg.wParam);
}

