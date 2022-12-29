
// MFCGUIDrawingView.h : CMFCGUIDrawingView 클래스의 인터페이스
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
protected: // serialization에서만 만들어집니다.
	CMFCGUIDrawingView();
	DECLARE_DYNCREATE(CMFCGUIDrawingView)

// 특성입니다.
public:
	CMFCGUIDrawingDoc* GetDocument() const;

// 작업입니다.
public:
	CPdb* m_pPdb = NULL;
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	void vOnPDBChange(CPdb* pdb);
	void vDrawLine(CLine* pLine, CDC* pDC, int nR, int nG, int nB, CTur * pTur = NULL);
	void vDrawArc(CArc* pArc, CDC* pDC, int nR, int nG, int nB, CTur * pTur = NULL);
	void vDrawPt(CPt* pPt, CDC* pDC, CTur* pTurret, int nR, int nG, int nB, double dCopperHoleRadius = 0);
	int * vGetRGB(int nLibArtworkLayNo);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFCGUIDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // MFCGUIDrawingView.cpp의 디버그 버전
inline CMFCGUIDrawingDoc* CMFCGUIDrawingView::GetDocument() const
   { return reinterpret_cast<CMFCGUIDrawingDoc*>(m_pDocument); }
#endif

