
// MFCGUIDrawingView.h : CMFCGUIDrawingView Ŭ������ �������̽�
//
#include "Pdb.h"
#include "Comp.h"
#include "Via.h"
#include "Copper.h"
#include<math.h>  
#include "Text.h"
#pragma once


class CMFCGUIDrawingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCGUIDrawingView();
	DECLARE_DYNCREATE(CMFCGUIDrawingView)

// Ư���Դϴ�.
public:
	CMFCGUIDrawingDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	CPdb* m_pPdb = NULL;
// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	void vOnPDBChange(CPdb* pdb);
	void vDrawLine(CLine* pLine, CDC* pDC, int nR, int nG, int nB, CTur * pTur = NULL);
	void vDrawArc(CArc* pArc, CDC* pDC, int nR, int nG, int nB, CTur * pTur = NULL);
	void vDrawPt(CPt* pPt, CDC* pDC, CTur* pTurret, int nR, int nG, int nB, double dCopperHoleRadius = 0);
	int * vGetRGB(int nLibArtworkLayNo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMFCGUIDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // MFCGUIDrawingView.cpp�� ����� ����
inline CMFCGUIDrawingDoc* CMFCGUIDrawingView::GetDocument() const
   { return reinterpret_cast<CMFCGUIDrawingDoc*>(m_pDocument); }
#endif

