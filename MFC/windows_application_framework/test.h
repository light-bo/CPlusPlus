#include <windows.h>
#include <commctrl.h>

#define dim(x) (sizeof(x)/sizeof(x[0]))

//消息映射结构体
typedef struct {
	UINT uCode;
	LRESULT (*funtionName) (HWND, UINT, WPARAM, LPARAM);
}MessageProc;

typedef struct {
	UINT uCode;
	LRESULT (*funtionName) (HWND, HWND, WORD, WORD);
}CommandProc;


#define IDC_CMDBAR 1
 
int registerWnd(HINSTANCE);

int showMainWnd(HINSTANCE, LPWSTR, int);

int quitMainWnd(HINSTANCE, int);


LRESULT CALLBACK mainWndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT goCreateMain(HWND, UINT, WPARAM, LPARAM);

LRESULT goPaintMain(HWND, UINT, WPARAM, LPARAM);

LRESULT goDestoryMain(HWND, UINT, WPARAM, LPARAM);

LRESULT goCloseMain(HWND, UINT, WPARAM, LPARAM);