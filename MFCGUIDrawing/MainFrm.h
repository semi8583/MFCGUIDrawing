
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#include "Propertys.h"
#include <string>
#include <cstdlib> // 이 헤더파일에는 프로그래밍시에 범용적으로 사용되는 여러가지 함수들을 모아 놓고 있는데, 예를 들면 동적 할당 관련 함수, 난수 생성 함수, 정수의 연산 함수, 검색 및 정렬 함수
#include <iostream>
#include <fstream> // 파일 읽기 라이브러리
#include<sstream> // 스트림 버퍼와 문자열 개체 간의 상호 작용
#include "Pdb.h"
#include "Via.h"
#include "Line.h"
#include "Pt.h"
#include "Comp.h"
#include "Arc.h"
#include "Polyline.h"
#include "Material.h"
#include "Polygon.h"
#include "Void.h"
#include "Pt.h"
#include "PadDefinition.h"
#include <Gdiplus.h>    
#include "MFCGUIDrawing.h"
#include "MFCGUIDrawingDoc.h"
#include "MFCGUIDrawingView.h"
#include <iostream>
// GDI+를 사용하기 위한 헤더 파일
#pragma comment(lib, "gdiplus") // GDI+를 사용하기 위한 라이브러리 파일
#pragma once

using namespace std;
using namespace Gdiplus;

class CLine; // Predefine
class CArc;
class CPt;
class CComp;
class CVia;
class CMFCGUIDrawingView;

class CMainFrame : public CFrameWndEx
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:
	CMFCGUIDrawingView* pOldOriginalActiveView;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	//BOOL CreateDockingWindows();
	//void SetDockingWindowIcons(BOOL bHiColorIcons);
public:
	void vAddMaterial(CMaterialArray* pPcbMaterial, CMaterial* pMaterial);
	afx_msg void OnOpenPDBA();
};


