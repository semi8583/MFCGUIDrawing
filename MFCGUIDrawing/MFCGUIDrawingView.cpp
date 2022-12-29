
// MFCGUIDrawingView.cpp : CMFCGUIDrawingView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCGUIDrawing.h"
#endif

#include "MFCGUIDrawingDoc.h"
#include "MFCGUIDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DrawSize 20
// CMFCGUIDrawingView

IMPLEMENT_DYNCREATE(CMFCGUIDrawingView, CView)

BEGIN_MESSAGE_MAP(CMFCGUIDrawingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCGUIDrawingView 생성/소멸

CMFCGUIDrawingView::CMFCGUIDrawingView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCGUIDrawingView::~CMFCGUIDrawingView()
{
	delete m_pPdb;
}

BOOL CMFCGUIDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCGUIDrawing2View 그리기

void CMFCGUIDrawingView::vDrawLine(CLine* pLine, CDC* pDC, int nR, int nG, int nB, CTur * pTur)
{
	//CMFCGUIDrawing2Doc* pDoc = GetDocument();	
	//pDC->SetMapMode(MM_TEXT); // MM_TEXT : 단위 픽셀, X축 증가 오른쪽, Y축 증가 아래쪽
	//pDC->SetViewportOrg(7DrawSize0, DrawSize0);

	Graphics graphics(*pDC);
	Pen PenColor(Color(nR, nG, nB), 0.1);

	if (pTur)
	{
		PenColor.SetWidth(pTur->m_dOuterSize * DrawSize);
		if (pTur->m_dInnerSize)
			cout << "m_dInnerSize 존재" << endl;
	}

	graphics.DrawLine(&PenColor, Point(pLine->m_dStartPtX * DrawSize, -(pLine->m_dStartPtY * DrawSize)), Point(pLine->m_dEndPtX * DrawSize, -(pLine->m_dEndPtY * DrawSize)));

}

void CMFCGUIDrawingView::vDrawArc(CArc* pArc, CDC* pDC, int nR, int nG, int nB, CTur * pTur)
{
	Graphics graphics(*pDC);

	Pen PenColor(Color(nR, nG, nB), 0.1);
	if (pTur)
	{
		PenColor.SetWidth(pTur->m_dOuterSize * DrawSize);
		if (pTur->m_dInnerSize)
			cout << "m_dInnerSize 존재" << endl;
	}

	Rect Rectangle = Rect(pArc->m_dCenterPtX * DrawSize - (pArc->m_dRadius * DrawSize), -pArc->m_dCenterPtY * DrawSize - (pArc->m_dRadius * DrawSize), pArc->m_dRadius * DrawSize * 2, pArc->m_dRadius * DrawSize * 2);

	if (pArc->m_sDirection == "CW")//시계 방향-> 폴렉스에서 각도 반대로/ MFC에서 각도 정상
	{
		if (pArc->m_dStartAngle > pArc->m_dEndAngle)
			graphics.DrawArc(&PenColor, Rectangle, 360 - pArc->m_dStartAngle, fabs(pArc->m_dStartAngle - pArc->m_dEndAngle));
		else if (pArc->m_dStartAngle < pArc->m_dEndAngle)
			graphics.DrawArc(&PenColor, Rectangle, 360 - pArc->m_dStartAngle, fabs(360 - pArc->m_dStartAngle - pArc->m_dEndAngle));
		else
			graphics.DrawArc(&PenColor, Rectangle, pArc->m_dStartAngle, 360);
	}
	else if (pArc->m_sDirection == "CCW") // 반시계 방향 -> 폴렉스에서 각도 정상 / mfc에서 각도 반대로 
	{
		if (pArc->m_dStartAngle > pArc->m_dEndAngle)
			graphics.DrawArc(&PenColor, Rectangle, 360 - pArc->m_dStartAngle, pArc->m_dStartAngle - pArc->m_dEndAngle - 360);
		else if (pArc->m_dStartAngle < pArc->m_dEndAngle)
			graphics.DrawArc(&PenColor, Rectangle, 360 - pArc->m_dEndAngle, pArc->m_dEndAngle - pArc->m_dStartAngle);
		else
			graphics.DrawArc(&PenColor, Rectangle, pArc->m_dStartAngle, 360);
	}
}

void CMFCGUIDrawingView::vDrawPt(CPt* pPt, CDC* pDC, CTur* pTurret, int nR, int nG, int nB, double dCopperHoleRadius)
{
	Graphics graphics(*pDC);

	Pen PenColor(Color(nR, nG, nB), pTurret->m_dOuterSize * DrawSize);

	if (pTurret->m_dInnerSize)
	{
		Rect Rectangle = Rect(pPt->m_dPtX * DrawSize - (dCopperHoleRadius * DrawSize), -(pPt->m_dPtY * DrawSize) - (dCopperHoleRadius * DrawSize), pTurret->m_dInnerSize * DrawSize, pTurret->m_dInnerSize * DrawSize);

		if (pTurret->m_sTurretType == "CIR") // circular
			graphics.DrawArc(&PenColor, Rectangle, 0, 360);
		else if (pTurret->m_sTurretType == "SQR") // square
			graphics.DrawRectangle(&PenColor, Rectangle);
		else if (pTurret->m_sTurretType == "THE") //  thermal
			cout << "값이 없다" << endl;
		else if (pTurret->m_sTurretType == "DOU") // don't
			cout << "값이 없다" << endl;
		else if (pTurret->m_sTurretType == "THS") // square thermal 
			cout << "값이 없다" << endl;
	}

	Rect Rectangle = Rect(pPt->m_dPtX * DrawSize - (dCopperHoleRadius * DrawSize), -(pPt->m_dPtY * DrawSize) - (dCopperHoleRadius * DrawSize), pTurret->m_dOuterSize * DrawSize, pTurret->m_dOuterSize * DrawSize);


	if (pTurret->m_sTurretType == "CIR") // circular
		graphics.DrawArc(&PenColor, Rectangle, 0, 360);
	else if (pTurret->m_sTurretType == "SQR") // square
		graphics.DrawRectangle(&PenColor, Rectangle);
	else if (pTurret->m_sTurretType == "THE") //  thermal
		cout << "값이 없다" << endl;
	else if (pTurret->m_sTurretType == "DOU") // don't
		cout << "값이 없다" << endl;
	else if (pTurret->m_sTurretType == "THS") // square thermal 
		cout << "값이 없다" << endl;

	if (pTurret->m_Wing.m_dWingDistance || pTurret->m_Wing.m_dWingAngle)
		cout << "값이 없다" << endl;
}

int*  CMFCGUIDrawingView::vGetRGB(int nLibArtworkLayNo)
{
	int nRGB[3];
	if (nLibArtworkLayNo == 0)
		nRGB[0] = 0, nRGB[1] = 0, nRGB[2] = 0;
	else if (nLibArtworkLayNo == 1)
		nRGB[0] = 193, nRGB[1] = 243, nRGB[2] = 107;
	else if (nLibArtworkLayNo == 2)
		nRGB[0] = 255, nRGB[1] = 191, nRGB[2] = 102;
	else if (nLibArtworkLayNo == 3)
		nRGB[0] = 202, nRGB[1] = 247, nRGB[2] = 253;
	else if (nLibArtworkLayNo == 4)
		nRGB[0] = 255, nRGB[1] = 244, nRGB[2] = 222;
	else if (nLibArtworkLayNo == 5)
		nRGB[0] = 255, nRGB[1] = 222, nRGB[2] = 244;
	else if (nLibArtworkLayNo == 6)
		nRGB[0] = 202, nRGB[1] = 147, nRGB[2] = 153;
	else if (nLibArtworkLayNo == 7)
		nRGB[0] = 202, nRGB[1] = 222, nRGB[2] = 144;
	else if (nLibArtworkLayNo == 8)
		nRGB[0] = 151, nRGB[1] = 222, nRGB[2] = 159;
	else if (nLibArtworkLayNo == 9)
		nRGB[0] = 160, nRGB[1] = 222, nRGB[2] = 131;
	else if (nLibArtworkLayNo == 10)
		nRGB[0] = 255, nRGB[1] = 255, nRGB[2] = 155;
	else if (nLibArtworkLayNo == 11)
		nRGB[0] = 0, nRGB[1] = 121, nRGB[2] = 61;
	else if (nLibArtworkLayNo == 12)
		nRGB[0] = 252, nRGB[1] = 215, nRGB[2] = 165;
	else if (nLibArtworkLayNo == 13)
		nRGB[0] = 154, nRGB[1] = 185, nRGB[2] = 190;
	else if (nLibArtworkLayNo == 14)
		nRGB[0] = 255, nRGB[1] = 216, nRGB[2] = 210;
	else if (nLibArtworkLayNo == 15)
		nRGB[0] = 171, nRGB[1] = 238, nRGB[2] = 207;
	else if (nLibArtworkLayNo == 16)
		nRGB[0] = 181, nRGB[1] = 104, nRGB[2] = 112;
	else if (nLibArtworkLayNo == 17)
		nRGB[0] = 222, nRGB[1] = 207, nRGB[2] = 171;
	else if (nLibArtworkLayNo == 18)
		nRGB[0] = 124, nRGB[1] = 202, nRGB[2] = 222;
	else if (nLibArtworkLayNo == 19)
		nRGB[0] = 58, nRGB[1] = 151, nRGB[2] = 222;
	else if (nLibArtworkLayNo == 21)
		nRGB[0] = 248, nRGB[1] = 57, nRGB[2] = 57;
	else if (nLibArtworkLayNo == 22)
		nRGB[0] = 64, nRGB[1] = 64, nRGB[2] = 64;
	else if (nLibArtworkLayNo == 23)
		nRGB[0] = 190, nRGB[1] = 169, nRGB[2] = 163;
	else if (nLibArtworkLayNo == 24)
		nRGB[0] = 236, nRGB[1] = 132, nRGB[2] = 255;
	else if (nLibArtworkLayNo == 25)
		nRGB[0] = 210, nRGB[1] = 214, nRGB[2] = 174;
	else if (nLibArtworkLayNo == 26)
		nRGB[0] = 241, nRGB[1] = 144, nRGB[2] = 201;
	else if (nLibArtworkLayNo == 27)
		nRGB[0] = 233, nRGB[1] = 241, nRGB[2] = 187;
	else if (nLibArtworkLayNo == 28)
		nRGB[0] = 166, nRGB[1] = 235, nRGB[2] = 179;
	else if (nLibArtworkLayNo == 29)
		nRGB[0] = 135, nRGB[1] = 219, nRGB[2] = 188;
	else if (nLibArtworkLayNo == 30)
		nRGB[0] = 153, nRGB[1] = 140, nRGB[2] = 190;
	else if (nLibArtworkLayNo == 31)
		nRGB[0] = 141, nRGB[1] = 164, nRGB[2] = 222;
	else if (nLibArtworkLayNo == 32)
		nRGB[0] = 183, nRGB[1] = 156, nRGB[2] = 134;
	else if (nLibArtworkLayNo == 33)
		nRGB[0] = 179, nRGB[1] = 199, nRGB[2] = 222;
	else if (nLibArtworkLayNo == 34)
		nRGB[0] = 200, nRGB[1] = 146, nRGB[2] = 205;
	else if (nLibArtworkLayNo == 35)
		nRGB[0] = 139, nRGB[1] = 195, nRGB[2] = 187;
	else if (nLibArtworkLayNo == 36)
		nRGB[0] = 131, nRGB[1] = 166, nRGB[2] = 159;
	else if (nLibArtworkLayNo == 37)
		nRGB[0] = 137, nRGB[1] = 218, nRGB[2] = 253;
	else if (nLibArtworkLayNo == 38)
		nRGB[0] = 159, nRGB[1] = 184, nRGB[2] = 165;
	else if (nLibArtworkLayNo == 39)
		nRGB[0] = 203, nRGB[1] = 221, nRGB[2] = 212;
	else if (nLibArtworkLayNo == 40)
		nRGB[0] = 245, nRGB[1] = 252, nRGB[2] = 150;
	else if (nLibArtworkLayNo == 41)
		nRGB[0] = 147, nRGB[1] = 197, nRGB[2] = 187;
	else if (nLibArtworkLayNo == 42)
		nRGB[0] = 138, nRGB[1] = 141, nRGB[2] = 137;
	else if (nLibArtworkLayNo == 81)
		nRGB[0] = 255, nRGB[1] = 207, nRGB[2] = 128;
	else if (nLibArtworkLayNo == 82)
		nRGB[0] = 255, nRGB[1] = 193, nRGB[2] = 112;
	else if (nLibArtworkLayNo == 83)
		nRGB[0] = 255, nRGB[1] = 179, nRGB[2] = 96;
	else if (nLibArtworkLayNo == 84)
		nRGB[0] = 255, nRGB[1] = 165, nRGB[2] = 80;
	else if (nLibArtworkLayNo == 201)
		nRGB[0] = 255, nRGB[1] = 255, nRGB[2] = 0;
	else if (nLibArtworkLayNo == 203)
		nRGB[0] = 203, nRGB[1] = 179, nRGB[2] = 139;
	else if (nLibArtworkLayNo == 204)
		nRGB[0] = 222, nRGB[1] = 161, nRGB[2] = 144;
	else if (nLibArtworkLayNo == 211)
		nRGB[0] = 255, nRGB[1] = 255, nRGB[2] = 0;
	else
		cout << "다른 컬러 없음" << endl;
	return nRGB;
}

void CMFCGUIDrawingView::OnDraw(CDC* pDC)
{
	CMFCGUIDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SetMapMode(MM_TEXT); // MM_TEXT : 단위 픽셀, X축 증가 오른쪽, Y축 증가 아래쪽
	pDC->SetViewportOrg(750, 350);
	pDC->SetBkColor(RGB(0, 0, 0));
	if (m_pPdb)
	{
		Graphics graphics(*pDC);
		double dCopperHoleRadius = 0;
		// 그대로 쓰고 Y만 부호 변경 그리고 X10
		//Pen BlackPen(Color(128, 0, 0, 0), 5.0f);
		//graphics.DrawLine(&BluePen, Point(10, 10), Point(200, 200));

		//Pen BluePen(Color(255, 0, 0, 255), 1.0f);
		//graphics.DrawLine(&BluePen, Point(283 ,-85.1091) , Point(322 , -47.1092));
		//graphics.DrawLine(&BluePen, Point(322 ,-47.1092), Point(322, 228));

		for (int i = 0; i < m_pPdb->m_Board.m_BoardOutline.m_aBoardOutline.GetSize(); i++) // Board
		{
			CPolyline* pPolyline;
			if (pPolyline = dynamic_cast<CPolyline*>(m_pPdb->m_Board.m_BoardOutline.m_aBoardOutline.GetAt(i))) // BoardOutLine
			{
				int* nRGB = vGetRGB(pPolyline->m_nLibArtworkLayNo);
				int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };
				for (int j = 0; j < pPolyline->m_aDrawObj.GetSize(); j++)
				{
					CLine * pLine;
					CArc* pArc;
					if (pLine = dynamic_cast<CLine*>(pPolyline->m_aDrawObj.GetAt(j)))
					{
						if (pLine->m_nLibTurretNo == 0)
						{
							vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
						}
						else
						{
							for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
							{
								if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
								{
									vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
									break;
								}
							}
						}
					}
					else if (pArc = dynamic_cast<CArc*>(pPolyline->m_aDrawObj.GetAt(j)))
					{
						if (pArc->m_nLibTurretNo == 0)
						{
							vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
						}
						else
						{
							for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
							{
								if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
								{
									vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
									break;
								}
							}
						}

					}
					else
						cout << "부족함" << endl;
				}
			}
		}

		//for (int i = 0; i < m_pPdb->m_LibComponent.m_aPart.GetSize(); i++)
		//{
		//	for (int j = 0; j < m_pPdb->m_LibComponent.m_aPart[i]->m_aPinDefinition.GetSize(); j++)
		//	{
		//		CPinDefinition * cPinDefinition = m_pPdb->m_LibComponent.m_aPart[i]->m_aPinDefinition[j];
		//		for (int k = 0; k < m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetSize(); k++)
		//		{
		//			/*if (m_pPdb->m_LibPadStack.m_aPadStackDefinition[k]->m_nLibPadStackNo == cPinDefinition->m_nLibPadStackNo)
		//			{
		//				m_pPdb->m_LibPadStack.m_aPadStackDefinition[k]->m_
		//			}*/
		//		}
		//	}
		//	for (int j = 0; j < m_pPdb->m_LibComponent.m_aPart[i]->m_SilkScreenDefinition.m_aDrawObj.GetSize(); j++)
		//	{
		//		CPolyline* pPolyline;
		//		CPolygon *pPolygon;
		//		CLine * pLine;
		//		CArc * pArc;
		//		if (pPolyline = dynamic_cast<CPolyline*>(m_pPdb->m_LibComponent.m_aPart[i]->m_SilkScreenDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pPolyline->m_nLibArtworkLayNo);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

		//			for (int k = 0; k < pPolyline->m_aDrawObj.GetSize(); k++)
		//			{
		//				CLine * pLine;
		//				CArc* pArc;
		//				if (pLine = dynamic_cast<CLine*>(pPolyline->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pLine->m_nLibTurretNo == 0)
		//					{
		//						vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else if (pArc = dynamic_cast<CArc*>(pPolyline->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pArc->m_nLibTurretNo == 0)
		//					{
		//						vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else
		//					cout << "부족함" << endl;
		//			}
		//		}
		//		else if (pPolygon = dynamic_cast<CPolygon*>(m_pPdb->m_LibComponent.m_aPart[i]->m_SilkScreenDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pPolygon->m_nLibArtworkLayNo);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };
		//			for (int k = 0; k < pPolygon->m_aDrawObj.GetSize(); k++)
		//			{
		//				if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pLine->m_nLibTurretNo == 0)
		//					{
		//						vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pArc->m_nLibTurretNo == 0)
		//					{
		//						vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else
		//					cout << "부족함" << endl;
		//			}
		//		}
		//		else
		//			cout << "부족함" << endl;
		//	}
		//	for (int j = 0; j < m_pPdb->m_LibComponent.m_aPart[i]->m_FigureDefinition.m_aDrawObj.GetSize(); j++)
		//	{
		//		CPolyline* pPolyline;
		//		CPolygon * pPolygon;
		//		CVoid * pVoid;
		//		CPt * pPt;
		//		if (pPolyline = dynamic_cast<CPolyline*>(m_pPdb->m_LibComponent.m_aPart[i]->m_FigureDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pPolyline->m_nLibArtworkLayNo);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

		//			for (int k = 0; k < pPolyline->m_aDrawObj.GetSize(); k++)
		//			{
		//				CLine * pLine;
		//				CArc* pArc;
		//				if (pLine = dynamic_cast<CLine*>(pPolyline->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pLine->m_nLibTurretNo == 0)
		//					{
		//						vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else if (pArc = dynamic_cast<CArc*>(pPolyline->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pArc->m_nLibTurretNo == 0)
		//					{
		//						vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else
		//					cout << "부족함" << endl;
		//			}
		//		}
		//		else if (pPolygon = dynamic_cast<CPolygon*>(m_pPdb->m_LibComponent.m_aPart[i]->m_FigureDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pPolygon->m_nLibArtworkLayNo);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

		//			for (int k = 0; k < pPolygon->m_aDrawObj.GetSize(); k++)
		//			{
		//				CLine * pLine;
		//				CArc* pArc;
		//				if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pLine->m_nLibTurretNo == 0)
		//					{
		//						vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj.GetAt(k)))
		//				{
		//					if (pArc->m_nLibTurretNo == 0)
		//					{
		//						vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
		//					}
		//					else
		//					{
		//						for (int l = 0; l < m_pPdb->m_LibTurret.m_aTur.GetSize(); l++)
		//						{
		//							if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[l]->m_nLibTurretNo)
		//							{
		//								vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[l]);
		//								break;
		//							}
		//						}
		//					}
		//				}
		//				else
		//					cout << "부족함" << endl;
		//			}
		//		}
		//		else if (pVoid = dynamic_cast<CVoid*>(m_pPdb->m_LibComponent.m_aPart[i]->m_FigureDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pVoid->m_nLibArtworkLayNo);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

		//			for (int k = 0; k < pVoid->m_aDrawObj.GetSize(); k++)
		//			{
		//				CPt * pPt;
		//				if (pPt = dynamic_cast<CPt*>(pVoid->m_aDrawObj.GetAt(k)))
		//				{
		//					for (int ㅣ = 0; ㅣ < m_pPdb->m_LibTurret.m_aTur.GetSize(); ㅣ++)
		//					{
		//						if (m_pPdb->m_LibTurret.m_aTur[ㅣ]->m_nLibTurretNo == pPt->m_nLibTurretNum)
		//						{
		//							vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[ㅣ], naRGB[0], naRGB[1], naRGB[2]);
		//							break;
		//						}
		//					}
		//				}
		//			}
		//		}
		//		else if (pPt = dynamic_cast<CPt*>(m_pPdb->m_LibComponent.m_aPart[i]->m_FigureDefinition.m_aDrawObj[j]))
		//		{
		//			int* nRGB = vGetRGB(pPt->m_nLibArtworkLayNum);
		//			int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

		//			for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
		//			{
		//				if (m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo == pPt->m_nLibTurretNum)
		//				{
		//					vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[k], naRGB[0], naRGB[1], naRGB[2]);
		//					break;
		//				}
		//			}
		//		}
		//		else
		//			cout << "부족함" << endl;
		//	}
		//}

		for (int i = 0; i < m_pPdb->m_Route.m_aRnet.GetSize(); i++)//Route
		{
			for (int j = 0; j < m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetSize(); j++)
			{
				CComp * pComp;
				CLine * pLine;
				CArc * pArc;
				CVia * pVia;
				CCopper * pCopper;
				CPolygon * pPolygon;
				CVoid * pVoid;
				if (pComp = dynamic_cast<CComp*>(m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetAt(j))) // (DCM 
				{
					for (int k = 0; k < m_pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.GetSize(); k++)
					{
						if (pComp->m_sReferenceName == m_pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.GetAt(k)->m_sReferenceName)
						{
							for (int l = 0; l < m_pPdb->m_LibComponent.m_aPart.GetSize(); l++)
							{
								if (m_pPdb->m_LibComponent.m_aPart.GetAt(l)->m_nLibPartNo == m_pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.GetAt(k)->m_nLibPartNo)
								{
									for (int n = 0; n < m_pPdb->m_LibComponent.m_aPart.GetAt(l)->m_aPinDefinition.GetSize(); n++)
									{
										for (int m = 0; m < m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetSize(); m++)
										{
											if (m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_nLibPadStackNo == m_pPdb->m_LibComponent.m_aPart.GetAt(l)->m_aPinDefinition.GetAt(n)->m_nLibPadStackNo)
											{
												for (int o = 0; o < m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetSize(); o++)
												{
													for (int p = 0; p < m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetSize(); p++)
													{
														for (int q = 0; q < m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetAt(p)->m_aDrawObj.GetSize(); q++)
														{
															CPolygon* pPolygon;
															CLine* pLine;
															CVoid* pVoid;
															CPt* pPt;
															if (pPolygon = dynamic_cast<CPolygon*>(m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetAt(p)->m_aDrawObj.GetAt(q)))
															{
																int* nRGB = vGetRGB(pPolygon->m_nLibArtworkLayNo);
																int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

																for (int r = 0; r < pPolygon->m_aDrawObj.GetSize(); r++)
																{
																	CLine * pLine;
																	CArc* pArc;
																	if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj.GetAt(r)))
																	{
																		if (pLine->m_nLibTurretNo == 0)
																		{
																			vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
																		}
																		else
																		{
																			for (int s = 0; s < m_pPdb->m_LibTurret.m_aTur.GetSize(); s++)
																			{
																				if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[s]->m_nLibTurretNo)
																				{
																					vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[s]);
																					break;
																				}
																			}
																		}
																	}
																	else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj.GetAt(r)))
																	{
																		if (pArc->m_nLibTurretNo == 0)
																		{
																			vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
																		}
																		else
																		{
																			for (int s = 0; s < m_pPdb->m_LibTurret.m_aTur.GetSize(); s++)
																			{
																				if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[s]->m_nLibTurretNo)
																				{
																					vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[s]);
																					break;
																				}
																			}
																		}
																	}
																	else
																		cout << "부족함" << endl;
																}
															}
															else if (pLine = dynamic_cast<CLine*>(m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetAt(p)->m_aDrawObj.GetAt(q)))
															{
																int* nRGB = vGetRGB(pLine->m_nLibArtworkLayNo);
																int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

																if (pLine->m_nLibTurretNo == 0)
																{
																	vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
																}
																else
																{
																	for (int r = 0; r < m_pPdb->m_LibTurret.m_aTur.GetSize(); r++)
																	{
																		if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[r]->m_nLibTurretNo)
																		{
																			vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[r]);
																			break;
																		}
																	}
																}
															}
															else if (pVoid = dynamic_cast<CVoid*>(m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetAt(p)->m_aDrawObj.GetAt(q)))
															{
																int* nRGB = vGetRGB(pVoid->m_nLibArtworkLayNo);
																int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

																for (int r = 0; r < pVoid->m_aDrawObj.GetSize(); r++)
																{
																	CPolygon * pPolygon;
																	CPt* pPt;
																	if (pPt = dynamic_cast<CPt*>(pVoid->m_aDrawObj.GetAt(r)))
																	{
																		for (int s = 0; s < m_pPdb->m_LibTurret.m_aTur.GetSize(); s++)
																		{
																			if (m_pPdb->m_LibTurret.m_aTur[s]->m_nLibTurretNo == pPt->m_nLibTurretNum)
																			{
																				vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[s], naRGB[0], naRGB[1], naRGB[2]);
																				break;
																			}
																		}
																	}
																	else if (pPolygon = dynamic_cast<CPolygon*>(pVoid->m_aDrawObj.GetAt(r)))
																	{
																		for (int s = 0; s < pPolygon->m_aDrawObj.GetSize(); s++)
																		{
																			CLine * pLine;
																			CArc* pArc;
																			if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj.GetAt(s)))
																			{
																				if (pLine->m_nLibTurretNo == 0)
																				{
																					vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);

																				}
																				else
																				{
																					for (int t = 0; t < m_pPdb->m_LibTurret.m_aTur.GetSize(); t++)
																					{
																						if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[t]->m_nLibTurretNo)
																						{
																							vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[t]);
																							break;
																						}
																					}
																				}
																			}
																			else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj.GetAt(s)))
																			{
																				if (pArc->m_nLibTurretNo == 0)
																				{
																					vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
																				}
																				else
																				{
																					for (int t = 0; t < m_pPdb->m_LibTurret.m_aTur.GetSize(); t++)
																					{
																						if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[t]->m_nLibTurretNo)
																						{
																							vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[t]);
																							break;
																						}
																					}
																				}
																			}
																			else
																				cout << "부족함" << endl;
																		}
																	}
																	else
																		cout << "부족함" << endl;
																}
															}
															else if (pPt = dynamic_cast<CPt*>(m_pPdb->m_LibPadStack.m_aPadStackDefinition.GetAt(m)->m_aLayerTypeName.GetAt(o)->m_aConnectionType.GetAt(p)->m_aDrawObj.GetAt(q)))
															{
																int* nRGB = vGetRGB(pPt->m_nLibArtworkLayNum);
																int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

																for (int r = 0; r < m_pPdb->m_LibTurret.m_aTur.GetSize(); r++)
																{
																	if (m_pPdb->m_LibTurret.m_aTur[r]->m_nLibTurretNo == pPt->m_nLibTurretNum)
																	{
																		vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[r], naRGB[0], naRGB[1], naRGB[2]);
																		break;
																	}
																}
															}
															else
																cout << "부족함" << endl;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else if (pLine = dynamic_cast<CLine*>(m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetAt(j)))
				{
					int* nRGB = vGetRGB(pLine->m_nLibArtworkLayNo);
					int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };
					if (pLine->m_nLibTurretNo == 0)
					{
						vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
					}
					else
					{
						for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
						{
							if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
							{
								vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
								break;
							}
						}
					}
				}
				else if (pArc = dynamic_cast<CArc*>(m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetAt(j)))
				{
					int* nRGB = vGetRGB(pArc->m_nLibArtworkLayNo);
					int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

					if (dCopperHoleRadius < pArc->m_dRadius && pArc->m_dStartAngle == pArc->m_dEndAngle)
						dCopperHoleRadius = pArc->m_dRadius;

					if (pArc->m_nLibTurretNo == 0)
					{
						vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
					}
					else
					{
						for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
						{
							if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
							{
								vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
								break;
							}
						}
					}
				}
				else if (pCopper = dynamic_cast<CCopper*>(m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetAt(j)))
				{
					int* nRGB = vGetRGB(pCopper->m_nLibArtworkLayNo);
					int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

					for (int k = 0; k < pCopper->m_aDrawObj.GetSize(); k++)
					{
						if (pPolygon = dynamic_cast<CPolygon*>(pCopper->m_aDrawObj[k]))
						{
							for (int l = 0; l < pPolygon->m_aDrawObj.GetSize(); l++)
							{
								if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj[l]))
								{
									if (pLine->m_nLibTurretNo == 0)
									{
										vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
									}
									else
									{
										for (int n = 0; n < m_pPdb->m_LibTurret.m_aTur.GetSize(); n++)
										{
											if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[n]->m_nLibTurretNo)
											{
												vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[n]);
												break;
											}
										}
									}
								}
								else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj[l]))
								{
									if (pArc->m_nLibTurretNo == 0)
									{
										vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
									}
									else
									{
										for (int n = 0; n < m_pPdb->m_LibTurret.m_aTur.GetSize(); n++)
										{
											if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[n]->m_nLibTurretNo)
											{
												vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[n]);
												break;
											}
										}
									}
								}
								else
									cout << "부족함" << endl;
							}
						}
						else if (pVoid = dynamic_cast<CVoid*>(pCopper->m_aDrawObj[k]))
						{
							for (int l = 0; l < pVoid->m_aDrawObj.GetSize(); l++)
							{
								if (pPolygon = dynamic_cast<CPolygon*>(pVoid->m_aDrawObj[l]))
								{
									for (int n = 0; n < pPolygon->m_aDrawObj.GetSize(); n++)
									{
										if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj[n]))
										{
											if (pLine->m_nLibTurretNo == 0)
											{
												vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
											}
											else
											{
												for (int m = 0; m < m_pPdb->m_LibTurret.m_aTur.GetSize(); m++)
												{
													if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[m]->m_nLibTurretNo)
													{
														vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[m]);
														break;
													}
												}
											}
										}
										else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj[n]))
										{
											if (pArc->m_nLibTurretNo == 0)
											{
												vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
											}
											else
											{
												for (int m = 0; m < m_pPdb->m_LibTurret.m_aTur.GetSize(); m++)
												{
													if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[m]->m_nLibTurretNo)
													{
														vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[m]);
														break;
													}
												}
											}
										}
										else
											cout << "부족함" << endl;
									}
								}
							}
						}
						else
							cout << "부족함" << endl;
					}
				}
				else if (pVia = dynamic_cast<CVia*>(m_pPdb->m_Route.m_aRnet.GetAt(i)->m_aDrawObj.GetAt(j)))
				{
					int* nRGB = vGetRGB(pVia->m_nLibArtworkLayNo);
					int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

					for (int k = 0; k < m_pPdb->m_LibVia.m_aViaDefinition.GetSize(); k++)
					{
						if (pVia->m_nLibViaNo == m_pPdb->m_LibVia.m_aViaDefinition.GetAt(k)->m_nLibViaNo)
						{
							CViaDefinition * pViaDefinition = m_pPdb->m_LibVia.m_aViaDefinition.GetAt(k);

							for (int l = 0; l < pViaDefinition->m_aLayerTypeName.GetSize(); l++)
							{
								for (int n = 0; n < pViaDefinition->m_aLayerTypeName.GetAt(l)->m_aConnectionType.GetSize(); n++)
								{
									CConnectionType *pConnectionType = pViaDefinition->m_aLayerTypeName.GetAt(l)->m_aConnectionType.GetAt(n);
									for (int m = 0; m < pConnectionType->m_aDrawObj.GetSize(); m++)
									{
										CPt * pPt;
										CLine * pLine;
										CVoid * pVoid;

										if (pPt = dynamic_cast<CPt*>(pConnectionType->m_aDrawObj.GetAt(m)))
										{
											for (int o = 0; o < m_pPdb->m_LibTurret.m_aTur.GetSize(); o++)
											{
												if (m_pPdb->m_LibTurret.m_aTur[o]->m_nLibTurretNo == pPt->m_nLibTurretNum)
												{
													vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[o], naRGB[0], naRGB[1], naRGB[2]);
													break;
												}
											}
										}
										else if (pVoid = dynamic_cast<CVoid*>(pConnectionType->m_aDrawObj.GetAt(m)))
										{
											for (int o = 0; o < pVoid->m_aDrawObj.GetSize(); o++)
											{
												CPolygon * pPolygon;
												if (pPt = dynamic_cast<CPt*>(pVoid->m_aDrawObj.GetAt(o)))
												{
													for (int p = 0; p < m_pPdb->m_LibTurret.m_aTur.GetSize(); p++)
													{
														if (m_pPdb->m_LibTurret.m_aTur[p]->m_nLibTurretNo == pPt->m_nLibTurretNum)
														{
															vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[p], naRGB[0], naRGB[1], naRGB[2]);
															break;
														}
													}
												}
												else if (pPolygon = dynamic_cast<CPolygon*>(pVoid->m_aDrawObj.GetAt(o)))
												{
													for (int p = 0; p < pPolygon->m_aDrawObj.GetSize(); p++)
													{
														CLine * pLine;
														CArc* pArc;
														if (pLine = dynamic_cast<CLine*>(pPolygon->m_aDrawObj.GetAt(p)))
														{
															if (pLine->m_nLibTurretNo == 0)
															{
																vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
															}
															else
															{
																for (int q = 0; q < m_pPdb->m_LibTurret.m_aTur.GetSize(); q++)
																{
																	if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[q]->m_nLibTurretNo)
																	{
																		vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[q]);
																		break;
																	}
																}
															}
														}
														else if (pArc = dynamic_cast<CArc*>(pPolygon->m_aDrawObj.GetAt(j)))
														{
															if (pArc->m_nLibTurretNo == 0)
															{
																vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
															}
															else
															{
																for (int q = 0; q < m_pPdb->m_LibTurret.m_aTur.GetSize(); q++)
																{
																	if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[q]->m_nLibTurretNo)
																	{
																		vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[q]);
																		break;
																	}
																}
															}
														}
														else
															cout << "부족함" << endl;
													}
												}
												else
													cout << "부족함" << endl;
											}
										}
										else
											cout << "부족함" << endl;
									}
								}
							}
						}
					}
				}
				else
					cout << "dd" << endl;
			}
		}
		for (int i = 0; i < m_pPdb->m_BoardFigure.m_aDrawObj.GetSize(); i++) // BOARDFIGURE
		{
			CPolyline* pPolyline;
			CVoid *pVoid;
			if (pPolyline = dynamic_cast<CPolyline*>(m_pPdb->m_BoardFigure.m_aDrawObj.GetAt(i)))
			{
				int* nRGB = vGetRGB(pPolyline->m_nLibArtworkLayNo);
				int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

				for (int j = 0; j < pPolyline->m_aDrawObj.GetSize(); j++)
				{
					CLine * pLine;
					CArc* pArc;
					if (pLine = dynamic_cast<CLine*>(pPolyline->m_aDrawObj.GetAt(j)))
					{
						if (pLine->m_nLibTurretNo == 0)
						{
							vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2]);
						}
						else
						{
							for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
							{
								if (pLine->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
								{
									vDrawLine(pLine, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
									break;
								}
							}
						}
					}
					else if (pArc = dynamic_cast<CArc*>(pPolyline->m_aDrawObj.GetAt(j)))
					{
						if (pArc->m_nLibTurretNo == 0)
						{
							vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2]);
						}
						else
						{
							for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
							{
								if (pArc->m_nLibTurretNo == m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo)
								{
									vDrawArc(pArc, pDC, naRGB[0], naRGB[1], naRGB[2], m_pPdb->m_LibTurret.m_aTur[k]);
									break;
								}
							}
						}
					}
					else
						cout << "부족함" << endl;
				}
			}
			else if (pVoid = dynamic_cast<CVoid*>(m_pPdb->m_BoardFigure.m_aDrawObj.GetAt(i)))
			{
				int* nRGB = vGetRGB(pVoid->m_nLibArtworkLayNo);
				int naRGB[3] = { nRGB[0],nRGB[1],nRGB[2] };

				for (int j = 0; j < pVoid->m_aDrawObj.GetSize(); j++)
				{
					CPt* pPt;
					if (pPt = dynamic_cast<CPt*>(pVoid->m_aDrawObj.GetAt(j)))
					{
						for (int k = 0; k < m_pPdb->m_LibTurret.m_aTur.GetSize(); k++)
						{
							if (m_pPdb->m_LibTurret.m_aTur[k]->m_nLibTurretNo == pPt->m_nLibTurretNum)
							{
								vDrawPt(pPt, pDC, m_pPdb->m_LibTurret.m_aTur[k], naRGB[0], naRGB[1], naRGB[2], dCopperHoleRadius);
								break;
							}
						}
					}
					else
						cout << "부족함" << endl;
				}
			}
		}
		for (int i = 0; i < m_pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.GetSize(); i++)
		{
			CRef * pRef = m_pPdb->m_CNetListRefdesList.m_ReferenceList.m_aRef.GetAt(i);

			for (int j = 0; j < m_pPdb->m_LibComponent.m_aPart.GetSize(); j++)
			{
				if (m_pPdb->m_LibComponent.m_aPart[j]->m_nLibPartNo == pRef->m_nLibPartNo)
				{
					for (int k = 0; k < m_pPdb->m_LibComponent.m_aPart[j]->m_SilkScreenDefinition.m_aDrawObj.GetSize(); k++)
					{
						CPolyline* pPolyLine;
						CPolygon * pPolygon;
						if (pPolyLine = dynamic_cast<CPolyline*>(m_pPdb->m_LibComponent.m_aPart[j]->m_SilkScreenDefinition.m_aDrawObj[k]))
						{
							for (int l = 0; l < pPolyLine->m_aDrawObj.GetSize(); l++)
							{
								CLine * pLine;
								CArc *pArc;
								if (pLine = dynamic_cast<CPolyline*>)
								{

								}
								else if (pArc = dynamic_cast<CPolyline*>)
								{

								}
								else
									cout << "다른게 더 있다" << endl;
							}
						}
						else if (pPolygon = dynamic_cast<CPolygon*>(m_pPdb->m_LibComponent.m_aPart[j]->m_SilkScreenDefinition.m_aDrawObj[k]))
						{

						}
						else
							cout << "다른게 더 있다" << endl;
					}
					for (int k = 0; k < m_pPdb->m_LibComponent.m_aPart[j]->m_FigureDefinition.m_aDrawObj.GetSize(); k++)
					{

					}
					break;
				}
			}

			for (int j = 0; j < pRef->m_RefText2.m_aDrawObj.GetSize(); j++)
			{
				CText *pText;
				if (pText = dynamic_cast<CText*>(pRef->m_RefText2.m_aDrawObj[j]))
				{
					int* nRGB = vGetRGB(pText->m_nArtworkLayNo);
					int naRGB[3] = { nRGB[0], nRGB[1], nRGB[2] };
					CLibTextText *pLibTextText;

					for (int k = 0; k < m_pPdb->m_LibText.m_aText.GetSize(); k++)
					{
						if (m_pPdb->m_LibText.m_aText[k]->m_nLibTextNo == pText->m_nLibFontNo)
							pLibTextText = m_pPdb->m_LibText.m_aText[k];
					}

					std::wstring widestr = std::wstring(pText->m_sValue.begin(), pText->m_sValue.end());
					const wchar_t* widecstr = widestr.c_str();

					FontFamily  fontFamily(L"Times New Roman");
					Gdiplus::Font font(&fontFamily, pLibTextText->m_dTextHeight * DrawSize, FontStyleRegular, UnitPixel);
					SolidBrush  solidBrush(Color(naRGB[0], naRGB[1], naRGB[2]));

					graphics.TranslateTransform(pText->m_dPtX * DrawSize, -pText->m_dPtY * DrawSize);
					graphics.RotateTransform(-pText->m_dAngle);

					if (pText->m_sMirror == "UNMIRROR")
						graphics.DrawString(widecstr, -1, &font, PointF(0, 0), &solidBrush);
					else
						cout << "다른 미러" << endl;

					graphics.ResetTransform();
				}
				else
					cout << "부족함" << endl;
			}
		}
		MessageBox("그리기 완료!");
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CMFCGUIDrawingView::vOnPDBChange(CPdb* pPdb)
{
	if (m_pPdb)
		delete m_pPdb;
	m_pPdb = pPdb->clone();
	//*g_pPdb = *pPdb;
	//CDC* pDC = GetDC();// CDC 클래스 객체의 포인터를 반환
	//pDC->Rectangle(10, 10, 100, 100);
	//ReleaseDC(pDC);//GetDC로 할당을 받으면 해제 
	Invalidate(TRUE);
}

void CMFCGUIDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCGUIDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCGUIDrawingView 진단

#ifdef _DEBUG
void CMFCGUIDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCGUIDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCGUIDrawingDoc* CMFCGUIDrawingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCGUIDrawingDoc)));
	return (CMFCGUIDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCGUIDrawingView 메시지 처리기


BOOL CMFCGUIDrawingView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CView::OnEraseBkgnd(pDC);

	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));

	return TRUE;
}
