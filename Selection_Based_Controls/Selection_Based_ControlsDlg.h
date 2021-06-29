
// Selection_Based_ControlsDlg.h : header file
//

#pragma once


// CSelectionBasedControlsDlg dialog
class CSelectionBasedControlsDlg : public CDialogEx
{
// Construction
public:
	CSelectionBasedControlsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTION_BASED_CONTROLS_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	CButton m_RadioMale;
	CButton m_RadioFemale;
	CButton m_RadioOther;
	CString m_DisplaySelected;
	afx_msg void OnBnClickedButtonSubmit();
	afx_msg void OnBnClickedStaticCbSport();
	CString m_DisplaySport;
};
