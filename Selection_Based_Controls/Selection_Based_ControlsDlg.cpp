
// Selection_Based_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Selection_Based_Controls.h"
#include "Selection_Based_ControlsDlg.h"
#include "afxdialogex.h"
#include "resource.h"

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


// CSelectionBasedControlsDlg dialog



CSelectionBasedControlsDlg::CSelectionBasedControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECTION_BASED_CONTROLS_DIALOG, pParent)
	
	, m_DisplaySelected(_T(""))
	, m_DisplaySport(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSelectionBasedControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_MALE, m_RadioMale);
	DDX_Control(pDX, IDC_RADIO_FEMALE, m_RadioFemale);
	DDX_Control(pDX, IDC_RADIO_OTHER, m_RadioOther);
	DDX_Text(pDX, IDC_STATIC_DISPLAY, m_DisplaySelected);
	DDX_Text(pDX, IDC_STATIC_DISPLAY_SPORT, m_DisplaySport);
}

BEGIN_MESSAGE_MAP(CSelectionBasedControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &CSelectionBasedControlsDlg::OnBnClickedButtonSubmit)
	ON_BN_CLICKED(IDC_STATIC_CB_SPORT, &CSelectionBasedControlsDlg::OnBnClickedStaticCbSport)
END_MESSAGE_MAP()


// CSelectionBasedControlsDlg message handlers

BOOL CSelectionBasedControlsDlg::OnInitDialog()
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

	//Radio Button
	//m_RadioMale.SetCheck(1);  // 1-> uncheck, 0->check
	/*
	int selectedRadio = m_RadioMale.GetCheckedRadioButton(IDC_RADIO_MALE, IDC_RADIO_OTHER);
	CString gender;
	if (selectedRadio == 1000)
	{
		gender = "Male";
	}
	else if (selectedRadio == 1001)
	{
		gender = "Female";
	}
	else if (selectedRadio == 1002)
	{
		gender = "Other";
	}
	m_DisplaySelected = L"Selected Gender = " + gender;
	//MessageBox(gender);
	UpdateData(FALSE);
	*/
	//gender.Format(L"Selected Gender: %d", selectedRadio);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSelectionBasedControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSelectionBasedControlsDlg::OnPaint()
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
HCURSOR CSelectionBasedControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSelectionBasedControlsDlg::OnBnClickedButtonSubmit()
{
	int selectedRadio = 0;
	selectedRadio = GetCheckedRadioButton(IDC_RADIO_MALE, IDC_RADIO_OTHER);
	CString gender;
	if (selectedRadio == 1000)
	{
		gender = "Male";
	}
	else if (selectedRadio == 1001)
	{
		gender = "Female";
	}
	else if (selectedRadio == 1002)
	{
		gender = "Other";
	}
	m_DisplaySelected = L"Selected Gender = " + gender;
	/*gender.Format(L"Selected Gender: %d", selectedRadio);
	MessageBox(gender);*/

	int isCricket, isBasket, isVolly, isFoot, isHockey = 0;
	isCricket = IsDlgButtonChecked(IDC_CHECK_CRICKET);
	isBasket = IsDlgButtonChecked(IDC_CHECK_BASKET);
	isVolly = IsDlgButtonChecked(IDC_CHECK_VOLLY);
	isFoot = IsDlgButtonChecked(IDC_CHECK_FOOTBALL);
	isHockey = IsDlgButtonChecked(IDC_CHECK_HOCKEY);
	CString selected = _T("");
	if (isCricket == 1)
	{
		selected += "Cricket, ";
	}
	if (isBasket == 1)
	{
		selected += "Basketball, ";
	}
	if (isVolly == 1)
	{
		selected += "Vollyball, ";
	}
	if (isFoot == 1)
	{
		selected += "Football, ";
	}
	if (isHockey == 1)
	{
		selected += "Hockey, ";
	}
	m_DisplaySport = selected;
	//Check box Sport
	UpdateData(FALSE);
}



void CSelectionBasedControlsDlg::OnBnClickedStaticCbSport()
{
	
}
