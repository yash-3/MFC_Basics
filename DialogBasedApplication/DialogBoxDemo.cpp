//#include <afxwin.h>
//#include<afx.h>
//#include "resource1.h"
//
//class CExampleDlg : public CDialog
//{
//public:
//	enum { IDD = IDD_EXAMPLE_DLG };
//
//	CExampleDlg();
//	~CExampleDlg();
//	DECLARE_MESSAGE_MAP()
//	afx_msg void OnBnClickedBtnclose();
//};
//
//CExampleDlg::CExampleDlg() : CDialog(CExampleDlg::IDD) {
//
//}
//
//CExampleDlg :: ~CExampleDlg() {
//
//}
//
//class CExample : public CWinApp
//{
//public:
//	BOOL InitInstance();
//};
//
//BOOL CExample::InitInstance()
//{
//	CExampleDlg myDlg;
//	m_pMainWnd = &myDlg;
//	myDlg.DoModal();
//
//	return TRUE;
//}
//CExample MyApp;
//
//BEGIN_MESSAGE_MAP(CExampleDlg, CDialog)
//	ON_BN_CLICKED(ID_BTNCLOSE, &CExampleDlg::OnBnClickedBtnclose)
//END_MESSAGE_MAP()
//
//
//void CExampleDlg::OnBnClickedBtnclose()
//{
//	//EndDialog(2);
//	CDialog::OnCancel();
//}
//
