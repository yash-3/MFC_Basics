
// Progress_Based_ControlsDlg.h : header file
//

#pragma once
#include "CPROGCTRL_1.h"


// CProgressBasedControlsDlg dialog
class CProgressBasedControlsDlg : public CDialogEx
{
// Construction
public:
	CProgressBasedControlsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESS_BASED_CONTROLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void OnTimer(UINT nIDEvent);
	DECLARE_MESSAGE_MAP()
public:
	CString m_CompTime;
	CString m_AppTime;
	unsigned int CompTime;
	afx_msg void OnBnClickedBtnKilltimer();
	CProgressCtrl m_ProgressHours;
	CProgressCtrl m_ProgressMinute;
	CProgressCtrl m_ProgressSecond;
	CString m_ValueHours;
	CString m_ValueMinute;
	CString m_ValueSecond;
	CPROGCTRL_1 m_ProgBarTime;
	CString m_ValueTime;
};
