
// List_Based_ControlsDlg.h : header file
//

#pragma once


// CListBasedControlsDlg dialog
class CListBasedControlsDlg : public CDialogEx
{
// Construction
public:
	CListBasedControlsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIST_BASED_CONTROLS_DIALOG };
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
	CListBox m_ListCountry;
	CString m_DisplayCountry;
	CString m_DisplayState;
	afx_msg void OnBnClickedBtnSubmit();
	const CString Country[9] = { L"India", L"USA", L"UK",L"China", L"Nepal", L"Pakistan", L"Korea", L"Rassia",L"Bhutan" };
	CComboBox m_cbState;
};
