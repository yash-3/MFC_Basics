
// Strings_FundamentalsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Strings_Fundamentals.h"
#include "Strings_FundamentalsDlg.h"
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


// CStringsFundamentalsDlg dialog



CStringsFundamentalsDlg::CStringsFundamentalsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STRINGS_FUNDAMENTALS_DIALOG, pParent)
	, txtEdit1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStringsFundamentalsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT1, txtEdit1);
}

BEGIN_MESSAGE_MAP(CStringsFundamentalsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CStringsFundamentalsDlg message handlers

BOOL CStringsFundamentalsDlg::OnInitDialog()
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

	CString str1 = _T("This is String1");
	CString str2("This is String2");
	txtEdit1.Append(str1 + "\n");
	txtEdit1.Append(str2 + "\n\n");

	//string empty or not
	CString str3 = _T("");
	CString str4;
	if (str3.IsEmpty())
	{
		txtEdit1.Append(L"String3 is Empty\n\n");
	}
	
	//length
	CString strlen;
	int len = str1.GetLength();
	strlen.Format(L"String1 length is = %d", len);
	txtEdit1.Append(strlen + "\n\n");

	if (str1 == str2)
	{
		txtEdit1.Append(L"String1 and String2 are Equal\n\n");
	}
	else
	{
		txtEdit1.Append(L"String1 and String2 are not Equal\n\n");
	}

	//substring
	CString mainStr = L"This is the Main String";
	CString Sub(mainStr, 11);
	txtEdit1.Append(L"MainString = "+mainStr + "\n");
	txtEdit1.Append(L"SubString = "+Sub + "\n");
	//left right
	CString subLeft = mainStr.Left(6);
	CString subRight = mainStr.Right(6);
	txtEdit1.Append(L"Sub Left = " + subLeft + "\n");
	txtEdit1.Append(L"Sub Right = " + subRight);


	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStringsFundamentalsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStringsFundamentalsDlg::OnPaint()
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
HCURSOR CStringsFundamentalsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

