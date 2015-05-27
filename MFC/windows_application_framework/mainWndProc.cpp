#include "test.h"

const TCHAR mainClassName[] = TEXT("myFirst");

HINSTANCE hInst;

//������Ӧ����Ϣ
const MessageProc mainMessages[] = {
	WM_CREATE, goCreateMain, 
	WM_PAINT, goPaintMain,
	WM_DESTROY, goDestoryMain,
	WM_CLOSE, goCloseMain, 
};

/*ע�ᴰ�ڣ�ע��ɹ����� 1�� ���򷵻� 0*/
int registerWnd(HINSTANCE hInstance) {

	//���ô���
	WNDCLASS wc;
	wc.hInstance = hInstance;

	wc.lpszClassName = mainClassName;//������������
	wc.lpfnWndProc = mainWndProc;//���ڹ��̣���Ҫ��

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.style = CS_DBLCLKS;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	//ע�ᴰ�ڣ�ϵͳ����
	if(!RegisterClass(&wc))
		return 0;

	return 1;
}

/*��ʾ����*/
int showMainWnd(HINSTANCE hInstance, LPWSTR lpCmdLine, int nShowCmd) {
	HWND hWnd;
	hInst = hInstance;
	
	hWnd = CreateWindow(
		mainClassName,

		TEXT("light"),//���ڱ���
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

//���ڹ��̣�������Ӧ����Ϣ��������Ӧ����Ϣ������
LRESULT CALLBACK mainWndProc(HWND hWnd, UINT msgCode, WPARAM wParam,
		LPARAM lParam) {
	int i;
	for(i=0; i<dim(mainMessages); ++i) {
		if(msgCode == mainMessages[i].uCode)
			return (*mainMessages[i].funtionName) (hWnd, msgCode, wParam, lParam);
	}

	//�Ҳ����û��Զ������Ϣ������������ϵͳĬ�ϴ�����
	return DefWindowProc(hWnd, msgCode, wParam, lParam);
}


LRESULT goCreateMain(HWND hWnd, UINT msgCode, WPARAM wParam, LPARAM lParam) {
	HWND wndCB;
	wndCB = CommandBar_Create(hInst, hWnd, IDC_CMDBAR);

	CommandBar_AddAdornments(wndCB, 0, 0);
	return 0;
}


//�����ڷ����ı�ʱ��WM_PAINT ��Ϣ����Ӧ����
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

	idCode = MessageBox(hWnd, TEXT("ȷ���˳�������"), TEXT("�˳�"), MB_YESNO | MB_ICONQUESTION);
	if(idCode == IDNO)
		return 0;

	//PostDestroyMessage(1);
	PostQuitMessage(1);
	return 0;

}
