#include<afxwin.h>
#include<string.h>
#include<iostream>
class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);  //Window Creation
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);  //window showing state
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);  // see action of Activate and Deactivate 
	afx_msg void OnPaint();  //paint a window
	afx_msg void OnSize(UINT nType, int cx, int cy); // when window size changed
	afx_msg void OnMove(int x, int y);  // when window has moved


	DECLARE_MESSAGE_MAP()
};

CMainFrame::CMainFrame()
{
	Create(NULL, _T("Message Map Demo"), WS_OVERLAPPEDWINDOW, CRect(100, 100, 720, 480), NULL);
}
class CMainApp : public CWinApp
{
public:
	BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SHOWWINDOW()
	ON_WM_ACTIVATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOVE()
END_MESSAGE_MAP()

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	/*
	CMainFrame::OnSize(nType, cx, cy);

	CString MsgToShow;
	switch(nType)
	{
	case SIZE_MINIMIZED:
		MsgToShow = "Minimized ";
		break;
	case SIZE_MAXIMIZED:
		MsgToShow = "Maximized ";
		break;
	case SIZE_RESTORED:
		MsgToShow = "Restored ";
		break;
	case SIZE_MAXHIDE:
		MsgToShow = "Maximized Not Me  ";
		break;
	case SIZE_MAXSHOW:
		MsgToShow = "Restored Not Me  ";
		break;
	}
	
	MessageBox(MsgToShow);

	*/
}


void CMainFrame::OnMove(int x, int y)
{
	CFrameWnd::OnMove(x, y);

	//char* MsgCoord = new char[20];
	CString MsgCoord;
	MsgCoord.Format(L"Left = %d | Top = %d", x, y);

	MessageBox(MsgCoord);
}


void CMainFrame::OnPaint()
{
	CFrameWnd::OnPaint();
	MessageBox(_T("Window has been Painted.."));
}

void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
	/*
	switch (nState)
	{
	case WA_ACTIVE:
		MessageBox(_T("This Window Activated without using Mouse..."));
		break;
	case WA_INACTIVE:
		MessageBox(_T("This Window has been DeActivated..."));
		break;
	case WA_CLICKACTIVE:
		MessageBox(_T("This Window Activated using Mouse..."));
		break;
	}
	*/
}

void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFrameWnd::OnShowWindow(bShow, nStatus);

	//ShowWindow(SW_MAXIMIZE);  //maximize window
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == 0)
	{
		MessageBox(_T("Window Created Successfully"));  //if return 0
		return 0;
	}

	return -1;
}

BOOL CMainApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return true;
}

CMainApp myApp;