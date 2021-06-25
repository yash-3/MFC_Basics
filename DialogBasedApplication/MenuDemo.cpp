//#include <afxwin.h>
//#include "resource1.h"
//
//class CResApp : public CWinApp
//{
//public:
//	BOOL InitInstance();
//};
//class CResFrame : public CFrameWnd
//{
//public:
//	HACCEL m_hAccel;
//	CResFrame()
//	{
//		// for Accelerator Table
//		m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_ACCELERATOR1));
//
//
//		Create(NULL, _T("Main Menu Demo"), WS_OVERLAPPEDWINDOW, CRect(200, 120, 640, 400),
//			NULL, MAKEINTRESOURCE(IDR_MAINMENU1));
//	}
//};
//BOOL CResApp::InitInstance()
//{
//	m_pMainWnd = new CResFrame;
//	m_pMainWnd->ShowWindow(SW_SHOW);
//	m_pMainWnd->UpdateWindow();
//
//	return TRUE;
//}
//CResApp theApp;