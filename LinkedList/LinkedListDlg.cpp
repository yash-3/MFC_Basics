
// LinkedListDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "LinkedList.h"
#include "LinkedListDlg.h"
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


// CLinkedListDlg dialog



CLinkedListDlg::CLinkedListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LINKEDLIST_DIALOG, pParent)
	, lblDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLinkedListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_DISPLAY, lblDisplay);
}

BEGIN_MESSAGE_MAP(CLinkedListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CLinkedListDlg message handlers

BOOL CLinkedListDlg::OnInitDialog()
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

	//LinkedList  ->  CList Class
	//Methods: AddHead, AddTail, Find, GetAt, GetCount, GetHead, GetNext, GetPrev, GetSize, GetTail, InsertAfter, InsertBefore
	// IsEmpty, RemoveAll, RemoveAt, SetAt
	CList<int, int>list;
	lblDisplay.Append(L"*Add element at Head*\n");
	list.AddHead(20);
	list.AddHead(10);
	POSITION pos = list.GetHeadPosition();
	while (pos)
	{
		int data = list.GetNext(pos);
		CString output;
		output.Format(L"%d ", data);
		lblDisplay.Append(output);
	}

	lblDisplay.Append(L"\n\n\n*Add element at Tail*\n");
	list.AddTail(30);
	list.AddTail(40);
	pos = list.GetHeadPosition();
	while (pos)
	{
		int data = list.GetNext(pos);
		CString output;
		output.Format(L"%d ", data);
		lblDisplay.Append(output);
	}
	lblDisplay.Append(L"\n\n\n*Insert Before and After(element: 30)*\n");
	POSITION position = list.Find(30);
	list.InsertBefore(position, 50);
	list.InsertAfter(position, 60);
	pos = list.GetHeadPosition();
	while (pos)
	{
		int data = list.GetNext(pos);
		CString output;
		output.Format(L"%d ", data);
		lblDisplay.Append(output);
	}
	lblDisplay.Append(L"\n\n\n*Update element: 50 to 80*\n");
	position = list.Find(50);
	list.SetAt(position,80);
	pos = list.GetHeadPosition();
	while (pos)
	{
		int data = list.GetNext(pos);
		CString output;
		output.Format(L"%d ", data);
		lblDisplay.Append(output);
	}
	lblDisplay.Append(L"\n\n\n*Delete element: 60*\n");
	position = list.Find(60);
	list.RemoveAt(position);
	pos = list.GetHeadPosition();
	while (pos)
	{
		int data = list.GetNext(pos);
		CString output;
		output.Format(L"%d ", data);
		lblDisplay.Append(output);
	}

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLinkedListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLinkedListDlg::OnPaint()
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
HCURSOR CLinkedListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

