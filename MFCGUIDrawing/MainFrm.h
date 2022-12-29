
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#include "Propertys.h"
#include <string>
#include <cstdlib> // �� ������Ͽ��� ���α׷��ֽÿ� ���������� ���Ǵ� �������� �Լ����� ��� ���� �ִµ�, ���� ��� ���� �Ҵ� ���� �Լ�, ���� ���� �Լ�, ������ ���� �Լ�, �˻� �� ���� �Լ�
#include <iostream>
#include <fstream> // ���� �б� ���̺귯��
#include<sstream> // ��Ʈ�� ���ۿ� ���ڿ� ��ü ���� ��ȣ �ۿ�
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
// GDI+�� ����ϱ� ���� ��� ����
#pragma comment(lib, "gdiplus") // GDI+�� ����ϱ� ���� ���̺귯�� ����
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
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
public:
	CMFCGUIDrawingView* pOldOriginalActiveView;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

// ������ �޽��� �� �Լ�
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


