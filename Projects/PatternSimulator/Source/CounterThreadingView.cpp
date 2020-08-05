
// CounterThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CounterThreading.h"
#endif

#include "CounterThreadingDoc.h"
#include "CounterThreadingView.h"
#include "TestThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_THREAD_START, &CCounterThreadingView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CCounterThreadingView::OnThreadPause)
	ON_COMMAND(ID_THREAD_RESUME, &CCounterThreadingView::OnThreadResume)
	ON_COMMAND(ID_GRIDSIZE_4, &CCounterThreadingView::OnGridsize4)
	ON_COMMAND(ID_GRIDSIZE_5, &CCounterThreadingView::OnGridsize5)
	ON_COMMAND(ID_GRIDSIZE_6, &CCounterThreadingView::OnGridsize6)
	ON_COMMAND(ID_GRIDSIZE_7, &CCounterThreadingView::OnGridsize7)
	ON_COMMAND(ID_GRIDSIZE_CUSTOM, &CCounterThreadingView::OnGridsizeCustom)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction

CCounterThreadingView::CCounterThreadingView()
	
{
	m_iCounter = 2;
	m_iMaxMatrixSize = 3;
}

CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCounterThreadingView drawing

void CCounterThreadingView::OnDraw(CDC* pDC)
{
	CCounterThreadingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//m_iCounter++;
	CString strSize;
	strSize.Format(L"Max Grid Size %d", m_iMaxMatrixSize);
	pDC->TextOut(200, 20, strSize);

	int iX = 10;
	int iY = 30;

	int iIndex;
	for (iIndex = 0; iIndex <= m_iCounter; iIndex++)
	{
		pDC->MoveTo(X_OFFSET + (iIndex*WIDTH), Y_OFFSET);
		pDC->LineTo(X_OFFSET + (iIndex*WIDTH), Y_OFFSET + (HEIGHT*m_iCounter));
	}
	for (iIndex = 0; iIndex <= m_iCounter; iIndex++)
	{
		pDC->MoveTo(X_OFFSET, Y_OFFSET + (iIndex*HEIGHT));
		pDC->LineTo(X_OFFSET + (WIDTH*m_iCounter), Y_OFFSET + (iIndex*HEIGHT));
	}


}


// CCounterThreadingView printing

BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG


// CCounterThreadingView message handlers


void CCounterThreadingView::OnThreadStart()
{
	pThread = AfxBeginThread(CTestThread::RunThreadFunction, this);
}


void CCounterThreadingView::OnThreadPause()
{
	pThread -> SuspendThread();
}


void CCounterThreadingView::OnThreadResume()
{
	pThread->ResumeThread();
}


void CCounterThreadingView::OnGridsize4()
{
	// TODO: Add your command handler code here
	m_iMaxMatrixSize = 4;
	Invalidate();
}


void CCounterThreadingView::OnGridsize5()
{
	// TODO: Add your command handler code here
	m_iMaxMatrixSize = 5;
	Invalidate();
}


void CCounterThreadingView::OnGridsize6()
{
	// TODO: Add your command handler code here
	m_iMaxMatrixSize = 6;
	Invalidate();
}


void CCounterThreadingView::OnGridsize7()
{
	// TODO: Add your command handler code here
	m_iMaxMatrixSize = 7;
	Invalidate();
}


void CCounterThreadingView::OnGridsizeCustom()
{
	// TODO: Add your command handler code here
}
