
// Tree_and_List_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Tree_and_List_Controls.h"
#include "Tree_and_List_ControlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTreeandListControlsDlg dialog



CTreeandListControlsDlg::CTreeandListControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TREE_AND_LIST_CONTROLS_DIALOG, pParent)
	, m_strTree(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeandListControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_TXT, m_strTree);
	DDX_Control(pDX, IDC_TREE1, m_treeCtrl);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}

BEGIN_MESSAGE_MAP(CTreeandListControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CTreeandListControlsDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTreeandListControlsDlg message handlers

BOOL CTreeandListControlsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	HTREEITEM hCountry, hState;
	hCountry = m_treeCtrl.InsertItem(L"Country", TVI_ROOT);
	hState = m_treeCtrl.InsertItem(L"Western State", hCountry);  // node inside Country
	m_treeCtrl.InsertItem(L"Gujarat", hState);
	m_treeCtrl.InsertItem(L"Goa", hState);
	m_treeCtrl.InsertItem(L"Maharastra", hState);
	m_treeCtrl.InsertItem(L"Rajasthan", hState);

	hState = m_treeCtrl.InsertItem(L"Union Territory", hCountry);
	m_treeCtrl.InsertItem(L"Daman & Diu", hState);
	m_treeCtrl.InsertItem(L"Andaman & Nikobar", hState);

	hState = m_treeCtrl.InsertItem(L"South State", hCountry);
	m_treeCtrl.InsertItem(L"Andhra Pradesh", hState);
	m_treeCtrl.InsertItem(L"Telangana", hState);
	m_treeCtrl.InsertItem(L"Karnataka", hState);
	m_treeCtrl.InsertItem(L"Kerla", hState);

	//List Control
	m_listCtrl.InsertColumn(
		0,              // Rank/order of item 
		L"ID",          // Caption for this header 
		LVCFMT_LEFT,    // Relative position of items under header 
		100);           // Width of items under header

	m_listCtrl.InsertColumn(1, L"Name", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(3, L"Address", LVCFMT_LEFT, 80);

	int nItem;

	nItem = m_listCtrl.InsertItem(0, L"1");
	m_listCtrl.SetItemText(nItem, 1, L"Yash");
	m_listCtrl.SetItemText(nItem, 2, L"20");
	m_listCtrl.SetItemText(nItem, 3, L"Jamnagar");

	nItem = m_listCtrl.InsertItem(0, L"2");
	m_listCtrl.SetItemText(nItem, 1, L"Harsh");
	m_listCtrl.SetItemText(nItem, 2, L"29");
	m_listCtrl.SetItemText(nItem, 3, L"Bhavnagar");

	nItem = m_listCtrl.InsertItem(0, L"3");
	m_listCtrl.SetItemText(nItem, 1, L"Karan");
	m_listCtrl.SetItemText(nItem, 2, L"37");
	m_listCtrl.SetItemText(nItem, 3, L"Rajkot");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTreeandListControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTreeandListControlsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTreeandListControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeandListControlsDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
