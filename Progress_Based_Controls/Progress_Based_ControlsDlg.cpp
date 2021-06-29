
// Progress_Based_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Progress_Based_Controls.h"
#include "Progress_Based_ControlsDlg.h"
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


// CProgressBasedControlsDlg dialog



CProgressBasedControlsDlg::CProgressBasedControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROGRESS_BASED_CONTROLS_DIALOG, pParent)
	, m_CompTime(_T(""))
	, m_AppTime(_T(""))
	, m_ValueHours(_T(""))
	, m_ValueMinute(_T(""))
	, m_ValueSecond(_T(""))
	, m_ValueTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgressBasedControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_1, m_CompTime);
	DDX_Text(pDX, IDC_STATIC_2, m_AppTime);
	DDX_Control(pDX, IDC_PROG_HOUR, m_ProgressHours);
	DDX_Control(pDX, IDC_PROG_MINUTE, m_ProgressMinute);
	DDX_Control(pDX, IDC_PROG_SECOND, m_ProgressSecond);
	DDX_Text(pDX, IDC_STATIC_HOUR, m_ValueHours);
	DDX_Text(pDX, IDC_STATIC_MINUTE, m_ValueMinute);
	DDX_Text(pDX, IDC_STATIC_SECOND, m_ValueSecond);
	DDX_Control(pDX, IDC_PROGCTRL_1, m_ProgBarTime);
	DDX_Text(pDX, IDC_STATIC_SECOND2, m_ValueTime);
}

BEGIN_MESSAGE_MAP(CProgressBasedControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(ID_BTN_KILLTIMER, &CProgressBasedControlsDlg::OnBnClickedBtnKilltimer)
END_MESSAGE_MAP()


// CProgressBasedControlsDlg message handlers

BOOL CProgressBasedControlsDlg::OnInitDialog()
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

	CompTime = GetTickCount();
	SetTimer(1, 100, NULL);  //1 arg -> counter ID, 2 arg-> count Up to that millisecond

	//Progress control
	m_ProgressHours.SetRange(0,23);
	m_ProgressMinute.SetRange(0, 59);
	m_ProgressSecond.SetRange(0, 59);
	m_ProgressHours.SetStep(1);
	m_ProgressMinute.SetStep(1);
	m_ProgressSecond.SetStep(1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProgressBasedControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProgressBasedControlsDlg::OnPaint()
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
HCURSOR CProgressBasedControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProgressBasedControlsDlg::OnTimer(UINT nIDEvent)
{
	unsigned long CurTickValue = GetTickCount();  //it provide millisecond from computer started.
	unsigned int Difference = CurTickValue - CompTime;

	unsigned int ComputerHours, ComputerMinutes, ComputerSeconds;
	unsigned int ApplicationHours, ApplicationMinutes, ApplicationSeconds;

	ComputerHours = (CurTickValue / (3600 * 999)) % 24;
	ComputerMinutes = (CurTickValue / (60 * 999)) % 60;
	ComputerSeconds = (CurTickValue / 999) % 60;
	ApplicationHours = (Difference / (3600 * 999)) % 24;
	ApplicationMinutes = (Difference / (60 * 999)) % 60;
	ApplicationSeconds = (Difference / 999) % 60;

	m_CompTime.Format(L"This computer has been ON for %d hours, %d minutes, %d seconds", ComputerHours, ComputerMinutes, ComputerSeconds);
	m_AppTime.Format(L"This application has been running for %d hours, %d minutes, % d seconds", ApplicationHours, ApplicationMinutes, ApplicationSeconds);

	//Progress control
	// Get the current time of the computer
	CTime CurTime = CTime::GetCurrentTime();
	// Find the hour, the minute, and the second values of the time
	int ValHours = CurTime.GetHour();
	int ValMinutes = CurTime.GetMinute();
	int ValSeconds = CurTime.GetSecond();
	// Change each progress bar accordingly
	m_ProgressHours.SetPos(ValHours);
	m_ProgressMinute.SetPos(ValMinutes);
	m_ProgressSecond.SetPos(ValSeconds);
	// Display the position of the progress in the right label
	m_ValueHours.Format(L"%d", m_ProgressHours.GetPos());
	m_ValueMinute.Format(L"%d", m_ProgressMinute.GetPos());
	m_ValueSecond.Format(L"%d", m_ProgressSecond.GetPos());

	//Prograss Bar
	m_ProgBarTime.put_Value(ValHours);
	m_ValueTime.Format(L"%f", m_ProgBarTime.get_Value());

	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}


void CProgressBasedControlsDlg::OnBnClickedBtnKilltimer()
{
	MessageBox(L"Timer Killed..");
	KillTimer(1);
	m_CompTime.Format(L"Timer Has been Killed!!");
	m_AppTime.Format(L"Timer Has been Killed!!");
	//SetTimer(1, 100, NULL);
	UpdateData(FALSE);
}
