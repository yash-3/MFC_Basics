//#include <afxwin.h>
//#include<afx.h>
//#include <afxwin2.inl>
//#include "resource.h"
//class CSimpleFrame : public CFrameWnd
//{
//public:
//	CSimpleFrame()
//	{
//		//Create(NULL, _T("Windows Application"),WS_BORDER | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
//		
//		// default maximize window open
//		//Create(NULL, _T("Windows Application"), WS_MINIMIZEBOX | WS_MAXIMIZE | WS_SYSMENU);
//
//		//resizable window
//		Create(NULL, _T("MFC Windows Application Demo"), WS_OVERLAPPEDWINDOW, CRect(120, 100, 700, 480));
//		
//	}
//};
//struct CSimpleApp : public CWinApp
//{
//	BOOL InitInstance()
//	{
//		// Use a pointer to the window's frame for the application to use the window
//		CSimpleFrame* Tester = new CSimpleFrame();
//		m_pMainWnd = Tester;
//
//		/*
//		// other way to create pointer of CWnd and assign Window object. It is same as above..
//		CWnd* ptr;
//		ptr = Tester;
//		*/
//
//		// Show the window
//		m_pMainWnd->ShowWindow(SW_SHOW);
//		m_pMainWnd->UpdateWindow();
//		return TRUE;
//	}
//};
//CSimpleApp theApp;