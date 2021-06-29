
// List_Based_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "List_Based_Controls.h"
#include "List_Based_ControlsDlg.h"
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


// CListBasedControlsDlg dialog



CListBasedControlsDlg::CListBasedControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIST_BASED_CONTROLS_DIALOG, pParent)
	, m_DisplayCountry(_T(""))
	, m_DisplayState(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBasedControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_COUNTRY, m_ListCountry);
	DDX_Text(pDX, IDC_STATIC_COUNTRY, m_DisplayCountry);
	DDX_Text(pDX, IDC_STATIC_STATE, m_DisplayState);
	DDX_Control(pDX, IDC_COMBO_STATE, m_cbState);
}

BEGIN_MESSAGE_MAP(CListBasedControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BTN_SUBMIT, &CListBasedControlsDlg::OnBnClickedBtnSubmit)
END_MESSAGE_MAP()


// CListBasedControlsDlg message handlers

BOOL CListBasedControlsDlg::OnInitDialog()
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
	
	for(int i = 0;i < 9;i++)
	{
		m_ListCountry.AddString(Country[i]);
	}

	/*m_ListCountry.AddString(L"India");
	m_ListCountry.AddString(L"USA");
	m_ListCountry.AddString(L"UK");
	m_ListCountry.AddString(L"China");
	m_ListCountry.AddString(L"Nepal");
	m_ListCountry.AddString(L"Pakistan");
	m_ListCountry.AddString(L"Korea");
	m_ListCountry.AddString(L"Rassia");
	m_ListCountry.InsertString(5, L"Bhutan");*/
	//m_ListCountry.DeleteString(6);
	int total = m_ListCountry.GetCount();   //return number of items
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListBasedControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBasedControlsDlg::OnPaint()
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
HCURSOR CListBasedControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBasedControlsDlg::OnBnClickedBtnSubmit()
{
	int selected = 0;
	selected = m_ListCountry.GetCurSel();
	CString selectedCountry = Country[selected];
	m_DisplayCountry = L"Selected Country = "+ selectedCountry;
	CString selectedState;
	m_cbState.GetWindowTextW(selectedState);
	m_DisplayState = L"Selected State = " + selectedState;
	UpdateData(FALSE);
}
