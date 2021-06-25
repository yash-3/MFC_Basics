#include<afxwin.h>
#include<afx.h>

class CResFrame : public CFrameWnd
{
public:
	CResFrame()
	{
		HCURSOR hCursor;
		HICON hIcon;

		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZEALL);
		hIcon = AfxGetApp()->LoadStandardIcon(IDI_INFORMATION);


		LPCTSTR window = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, hCursor, (HBRUSH)::GetStockObject(BLACK_BRUSH),hIcon);

		Create(window, _T("Standard Window"), WS_OVERLAPPEDWINDOW, CRect(150, 120, 600, 400), NULL);
	}
};

class CResApp : public CWinApp
{
public:
	BOOL InitInstance();
};

BOOL CResApp::InitInstance()
{
	m_pMainWnd = new CResFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	
	return TRUE;
}
CResApp myApp;