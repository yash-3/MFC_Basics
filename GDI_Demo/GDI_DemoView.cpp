
// GDI_DemoView.cpp : implementation of the CGDIDemoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GDI_Demo.h"
#endif

#include "GDI_DemoDoc.h"
#include "GDI_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIDemoView

IMPLEMENT_DYNCREATE(CGDIDemoView, CView)

BEGIN_MESSAGE_MAP(CGDIDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGDIDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGDIDemoView construction/destruction

CGDIDemoView::CGDIDemoView() noexcept
{
	// TODO: add construction code here

}

CGDIDemoView::~CGDIDemoView()
{
}

BOOL CGDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGDIDemoView drawing

void CGDIDemoView::OnDraw(CDC* pDC)
{
	pDC->MoveTo(30, 30);
	pDC->LineTo(230, 30);
	//polylines
	CPoint pts[7];
	pts[0] = CPoint(20, 280);
	pts[1] = CPoint(120, 280);
	pts[2] = CPoint(120, 130);
	pDC->Polyline(pts, 3);
	//rectangle with color
	//pDC->Rectangle(180, 100, 300, 280);
	CBrush NewBrush(RGB(0, 2, 255));
	CBrush* pBrush = pDC->SelectObject(&NewBrush);
	pDC->Rectangle(180, 100, 300, 280);
	pDC->SelectObject(pBrush);

	//multi polygon
	CPoint Pt[12];
	int lpPts[] = { 3, 3, 3, 3 };
	// Top Triangle
	Pt[0] = CPoint(385, 10);
	Pt[1] = CPoint(355, 70);
	Pt[2] = CPoint(415, 70);
	
	// Bottom Triangle
	Pt[6] = CPoint(355, 85);
	Pt[7] = CPoint(385, 145);
	Pt[8] = CPoint(415, 85);

	pDC->PolyPolygon(Pt, lpPts, 4);

	// Ellipse
	pDC->Ellipse(350, 200, 500, 290);

	

	CGDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}


// CGDIDemoView printing


void CGDIDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGDIDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGDIDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGDIDemoView diagnostics

#ifdef _DEBUG
void CGDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIDemoDoc* CGDIDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIDemoDoc)));
	return (CGDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIDemoView message handlers
