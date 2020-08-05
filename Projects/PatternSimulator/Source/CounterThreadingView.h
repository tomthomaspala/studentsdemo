
// CounterThreadingView.h : interface of the CCounterThreadingView class
#include "CounterThreadingDoc.h"

#pragma once

#define X_OFFSET	100
#define Y_OFFSET	60

#define WIDTH		40
#define HEIGHT		40


class CCounterThreadingView : public CView
{
protected: // create from serialization only
	CCounterThreadingView();
	DECLARE_DYNCREATE(CCounterThreadingView)
	CWinThread *pThread;
// Attributes
public:
	CCounterThreadingDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCounterThreadingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	long m_iCounter;
	long m_iMaxMatrixSize;
	afx_msg void OnThreadStart();
	afx_msg void OnThreadPause();
	afx_msg void OnThreadResume();
	afx_msg void OnGridsize4();
	afx_msg void OnGridsize5();
	afx_msg void OnGridsize6();
	afx_msg void OnGridsize7();
	afx_msg void OnGridsizeCustom();
};

#ifndef _DEBUG  // debug version in CounterThreadingView.cpp
inline CCounterThreadingDoc* CCounterThreadingView::GetDocument() const
   { return reinterpret_cast<CCounterThreadingDoc*>(m_pDocument); }
#endif

