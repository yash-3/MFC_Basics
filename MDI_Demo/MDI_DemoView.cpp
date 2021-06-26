
// MDI_DemoView.cpp : implementation of the CMDIDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MDI_Demo.h"
#endif

#include "MDI_DemoDoc.h"
#include "MDI_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDIDemoView

IMPLEMENT_DYNCREATE(CMDIDemoView, CView)

BEGIN_MESSAGE_MAP(CMDIDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMDIDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMDIDemoView construction/destruction

CMDIDemoView::CMDIDemoView() noexcept
{
	// TODO: add construction code here

}

CMDIDemoView::~CMDIDemoView()
{
}

BOOL CMDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMDIDemoView drawing

void CMDIDemoView::OnDraw(CDC* /*pDC*/)
{
	CMDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMDIDemoView printing


void CMDIDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMDIDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMDIDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMDIDemoView diagnostics

#ifdef _DEBUG
void CMDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIDemoDoc* CMDIDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIDemoDoc)));
	return (CMDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDIDemoView message handlers
