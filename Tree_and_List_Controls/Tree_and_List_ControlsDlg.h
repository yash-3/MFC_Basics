
// Tree_and_List_ControlsDlg.h : header file
//

#pragma once


// CTreeandListControlsDlg dialog
class CTreeandListControlsDlg : public CDialogEx
{
// Construction
public:
	CTreeandListControlsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREE_AND_LIST_CONTROLS_DIALOG };
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
	CString m_strTree;
	CTreeCtrl m_treeCtrl;
	afx_msg void OnBnClickedCancel();
	CListCtrl m_listCtrl;
};
