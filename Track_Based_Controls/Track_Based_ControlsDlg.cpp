
// Track_Based_ControlsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Track_Based_Controls.h"
#include "Track_Based_ControlsDlg.h"
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


// CTrackBasedControlsDlg dialog



CTrackBasedControlsDlg::CTrackBasedControlsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRACK_BASED_CONTROLS_DIALOG, pParent)
	, m_Rating(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrackBasedControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PREVIEW, m_Preview);
	DDX_Control(pDX, IDC_SPIN_RED, m_SpinRed);
	DDX_Control(pDX, IDC_SPIN_GREEN, m_SpinGreen);
	DDX_Control(pDX, IDC_SPIN_BLUE, m_SpinBlue);
	DDX_Control(pDX, IDC_SLIDER_RATING, m_SliderRating);
	DDX_Text(pDX, IDC_STATIC_RATING, m_Rating);
}

BEGIN_MESSAGE_MAP(CTrackBasedControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_RED, &CTrackBasedControlsDlg::OnDeltaposSpinRed)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_GREEN, &CTrackBasedControlsDlg::OnDeltaposSpinGreen)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BLUE, &CTrackBasedControlsDlg::OnDeltaposSpinBlue)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RATING, &CTrackBasedControlsDlg::OnNMCustomdrawSliderRating)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_RATING, &CTrackBasedControlsDlg::OnTRBNThumbPosChangingSliderRating)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_RATING, &CTrackBasedControlsDlg::OnNMReleasedcaptureSliderRating)
END_MESSAGE_MAP()


// CTrackBasedControlsDlg message handlers

BOOL CTrackBasedControlsDlg::OnInitDialog()
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

	PreviewColor = RGB(192, 192, 192);

	//create spin button programmatically
	CSpinButtonCtrl* SpinCtrl = new CSpinButtonCtrl;
	//SpinCtrl->Create(WS_CHILD | WS_VISIBLE | UDS_SETBUDDYINT, CRect(60, 10, 80, 35), this, 0x128);

	//SpinCtrl->SetRange(-12, 1244); // set range of spin button

	UDACCEL udAccel;
	int SizeOfAccel = sizeof(UDACCEL);
	udAccel.nSec = 100;
	udAccel.nInc = 5;  //increment by 5
	m_SpinRed.SetAccel(SizeOfAccel, &udAccel);


	m_SpinRed.SetRange(0, 255);
	m_SpinGreen.SetRange(0, 255);
	m_SpinBlue.SetRange(0, 255);
	m_SpinRed.SetPos(192);  //desplay default value
	m_SpinGreen.SetPos(192);
	m_SpinBlue.SetPos(192);
	PreviewColor = RGB(192, 192, 192);  //set color of Image Box

	//slider
	m_SliderRating.SetRangeMin(0);
	m_SliderRating.SetRangeMax(10);
	m_SliderRating.SetPos(3);
	/*int pos  = m_SliderRating.GetPos();
	CString rate;
	rate.Format(L"%d", pos);
	m_Rating = rate;*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrackBasedControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTrackBasedControlsDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect RectPreview;
	CBrush BrushGray(PreviewColor);
	m_Preview.GetWindowRect(&RectPreview);
	CBrush* pOldBrush = dc.SelectObject(&BrushGray);
	ScreenToClient(&RectPreview);
	dc.Rectangle(RectPreview);
	dc.SelectObject(pOldBrush);


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
HCURSOR CTrackBasedControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTrackBasedControlsDlg::UpdatePreview()
{
	CClientDC dc(this); // device context for painting

	CBrush BrushBG(PreviewColor);
	CRect RectPreview;
	m_Preview.GetWindowRect(&RectPreview);
	CBrush* pOldBrush = dc.SelectObject(&BrushBG);
	ScreenToClient(&RectPreview);
	dc.Rectangle(RectPreview);
	dc.SelectObject(pOldBrush);

}

void CTrackBasedControlsDlg::OnDeltaposSpinRed(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	int RColor = m_SpinRed.GetPos();
	int GColor = m_SpinGreen.GetPos();
	int BColor = m_SpinBlue.GetPos();
	PreviewColor = RGB(RColor, GColor, BColor);
	UpdatePreview();

	*pResult = 0;
}


void CTrackBasedControlsDlg::OnDeltaposSpinGreen(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	int RColor = m_SpinRed.GetPos();
	int GColor = m_SpinGreen.GetPos();
	int BColor = m_SpinBlue.GetPos();
	PreviewColor = RGB(RColor, GColor, BColor);
	UpdatePreview();

	*pResult = 0;
}


void CTrackBasedControlsDlg::OnDeltaposSpinBlue(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	int RColor = m_SpinRed.GetPos();
	int GColor = m_SpinGreen.GetPos();
	int BColor = m_SpinBlue.GetPos();
	PreviewColor = RGB(RColor, GColor, BColor);
	UpdatePreview();
	*pResult = 0;
}

//
//void CTrackBasedControlsDlg::OnNMCustomdrawSliderRating(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	
//
//	*pResult = 0;
//}


void CTrackBasedControlsDlg::OnTRBNThumbPosChangingSliderRating(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING* pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING*>(pNMHDR);
	// TODO: Add your control notification handler code here
	int pos = m_SliderRating.GetPos();
		CString rate;
		rate.Format(L"%d", pos);
		m_Rating = rate;
		MessageBox(L"pos");
	*pResult = 0;
}


void CTrackBasedControlsDlg::OnNMReleasedcaptureSliderRating(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int pos = m_SliderRating.GetPos();
	CString rate;
	rate.Format(L"Slider Value = %d", pos);
	m_Rating = rate;
	UpdateData(FALSE);
	//MessageBox(L"release");
	*pResult = 0;
}
