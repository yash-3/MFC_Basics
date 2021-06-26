
// Array_OperationsDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Array_Operations.h"
#include "Array_OperationsDlg.h"
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


// CArrayOperationsDlg dialog



CArrayOperationsDlg::CArrayOperationsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ARRAY_OPERATIONS_DIALOG, pParent)
	, lblDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CArrayOperationsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_DISPLAY, lblDisplay);
}

BEGIN_MESSAGE_MAP(CArrayOperationsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CArrayOperationsDlg message handlers

BOOL CArrayOperationsDlg::OnInitDialog()
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

	//Array
	// CArray class have methods like: Add, Append(array to other array), Copy(array to other array), InsertAt, GetSize, IsEmpty
	// RemoveAll, RemoveAt
	lblDisplay.Append(L"**Insert Operation: **\n");
	CArray<CString, CString> strArray;
	strArray.Add(L"Yash");
	strArray.Add(L"Meet");
	strArray.Add(L"Jay");
	strArray.Add(L"Karan");
	strArray.Add(L"Ayush");

	/*CString display;
	display.Format(L"Insert Operation: %s", strArray);*/
	for (int i = 0;i < strArray.GetSize();i++)
	{
		lblDisplay.Append(strArray[i] + L", ");
	}

	//InsertAt and GetAt
	lblDisplay.Append(L"\n\n\n\n**Insert At Given Position: **\n");
	strArray.InsertAt(2, L"Harsh");

	for (int i = 0;i < strArray.GetSize();i++)
	{
		lblDisplay.Append(strArray.GetAt(i) + L", ");
	}

	//SetAt (Update)
	lblDisplay.Append(L"\n\n\n\n**Update Operation: **\n");
	strArray.SetAt(2, L"Hit");

	for (int i = 0;i < strArray.GetSize();i++)
	{
		lblDisplay.Append(strArray.GetAt(i) + L", ");
	}

	//copy one array to another array
	lblDisplay.Append(L"\n\n\n\n**Copy Array to Other Array: **\n");
	CArray<CString, CString>strArray2;
	strArray2.Copy(strArray);

	for (int i = 0;i < strArray2.GetSize();i++)
	{
		lblDisplay.Append(strArray2.GetAt(i) + L", ");
	}
	//Remove Element
	lblDisplay.Append(L"\n\n\n\n**Remove Particular elements: **\n");
	strArray2.RemoveAt(2);
	for (int i = 0;i < strArray2.GetSize();i++)
	{
		lblDisplay.Append(strArray2.GetAt(i) + L", ");
	}

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CArrayOperationsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CArrayOperationsDlg::OnPaint()
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
HCURSOR CArrayOperationsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

