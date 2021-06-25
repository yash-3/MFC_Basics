#include <afxwin.h>
#include<string.h>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags); // On Key Pressed
	//afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags); //On key Released
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);  // Mouse leftbutton pressed
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);  // Mouse righttbutton release
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point); //mouse moving
	//afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point); // right double click
	DECLARE_MESSAGE_MAP()
};
CMainFrame::CMainFrame()
{
	// Create the window's frame
	Create(NULL, _T("Windows Application"), WS_OVERLAPPEDWINDOW, CRect(120, 100, 700, 480), NULL);
}
class CExerciseApp : public CWinApp
{
public:
	BOOL InitInstance();
};
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

void CMainFrame::OnRButtonUp(UINT nFlags, CPoint point)
{
	
	CString MsgCoord;
	MsgCoord.Format(L"Right Button at P(%d, %d)", point.x, point.y);

	MessageBox(MsgCoord);

	/*
	//demo of send message Anytime
	const char* Msg = "This message was sent using sendmessage() function";
	SendMessage(WM_SETTEXT, 0, (LPARAM)(LPCTSTR)Msg);
	*/
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RETURN:
		MessageBox(_T("You pressed Enter"));
		break;
	case VK_F1:
		MessageBox(_T("You pressed F1"));
		break;
	case VK_DELETE:
		MessageBox(_T("You pressed Delete"));
		break;
	default:
		MessageBox(_T("Whatever"));
	}
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{

	CString MsgCoord;
	MsgCoord.Format(L"Left Button at P(%d, %d)", point.x, point.y);

	MessageBox(MsgCoord);
}

BOOL CExerciseApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CExerciseApp theApp;