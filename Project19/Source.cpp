#include <Windows.h>
#include <tchar.h>
#include "resource.h"

HWND hB, hStatic;
TCHAR str[4];

const short pizza = 25;
const short sushi = 35;
const short burger = 15;
const short shaurma = 10;
const short water = 5;
const short cola = 7;
const short sprite = 6;
short overall = NULL;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		hB = GetDlgItem(hWnd, IDC_BUTTON3);
		hStatic = GetDlgItem(hWnd, IDC_STATIC);
	}
	case WM_COMMAND:
		if (overall == NULL)
		{
			EnableWindow(hB, FALSE);
		}
		else if (overall != NULL)
		{
			EnableWindow(hB, TRUE);
		}
		else
		{
			return(TRUE);
		}
		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			overall = NULL;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO1)
		{
			overall += pizza;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO2)
		{
			overall += sushi;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO3)
		{
			overall += burger;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO4)
		{
			overall += shaurma;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO5)
		{
			overall += water;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO6)
		{
			overall += cola;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_RADIO7)
		{
			overall += sprite;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_BUTTON2)
		{
			overall = NULL;
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_BUTTON3)
		{
			EndDialog(hWnd, NULL);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DLGPROC(DlgProc));
		}
		else if (LOWORD(wParam) == IDC_BUTTON4)
		{
			wsprintf(str, TEXT("%d"), overall);
			SendMessage(hStatic, WM_SETTEXT, NULL, LPARAM(str));
			Sleep(3000);
			EndDialog(hWnd, NULL);
		}
		else
		{
			return(TRUE);
		}
		return(TRUE);
	case WM_CLOSE:
		EndDialog(hWnd, NULL);
		return(TRUE);
	}
	return(FALSE);
}