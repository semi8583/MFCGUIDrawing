#include "stdafx.h"
#include "Board.h"
#include "Polyline.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CBoard::CBoard()
{
	cout << "생성자 CBoard() 호출" << endl;
}
CBoard::CBoard(const CBoard& src)
{
	*this = src;
}
CBoard::~CBoard()
{
	for (int i = 0; i < this->m_aStackUp.GetSize(); i++)
	{
		CStackUp * pItem = m_aStackUp.GetAt(i);
		delete pItem;
	}
	m_aStackUp.RemoveAll();
	cout << "소멸자 ~CBoard() 호출" << endl;
}
void CBoard::vSetBoard(int nNoOfPhysicalLayers, CDrawingArea DrawingArea, CPanel Pannel,
	CBoardOutline BoardOutline, CStackUpArray aStackUp, CLibMaterial LibMaterial, CRigidFlexiblePcb RigidFlexiblePcb)
{
	m_nNoOfPhysicalLayers = nNoOfPhysicalLayers;
	m_DrawingArea = DrawingArea;
	m_Pannel = Pannel;

	for (int i = 0; i < this->m_aStackUp.GetSize(); i++)
	{
		CStackUp * pItem = m_aStackUp.GetAt(i);
		delete pItem;
	}
	m_aStackUp.RemoveAll();

	for (int i = 0; i < BoardOutline.m_aBoardOutline.GetSize();i++)
		m_BoardOutline.m_aBoardOutline[i] = BoardOutline.m_aBoardOutline[i];
	for (int i = 0; i < aStackUp.GetSize(); i++)
		m_aStackUp[i] = aStackUp[i];
	m_LibMaterial = LibMaterial;
	m_RigidFlexiblePcb = RigidFlexiblePcb;
}
void CBoard::vAddPolylineToBoardOutline(CDrawObj* pDrawObj, int nLibArtworkLayNo)
{
	CPolyline* pPolyline;
	if (pPolyline = dynamic_cast<CPolyline*>(pDrawObj))
	{
		pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
		m_BoardOutline.m_aBoardOutline.Add(pPolyline->clone());
	}
}
void CBoard::vAddPolylineToBoardOutline(CDrawObjArray aDrawObj, int nLibArtworkLayNo)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CPolyline* pPolyline = new CPolyline();

		if (pPolyline = dynamic_cast<CPolyline*>(aDrawObj[i]))
		{
			pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
			m_BoardOutline.m_aBoardOutline.Add(pPolyline->clone());
		}
	}
}
CBoard& CBoard::operator =(const CBoard& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < this->m_aStackUp.GetSize(); i++)
	{
		CStackUp * pItem = m_aStackUp.GetAt(i);
		delete pItem;
	}
	m_aStackUp.RemoveAll();

	this->m_BoardOutline = rhs.m_BoardOutline;

	for (int i = 0; i < rhs.m_aStackUp.GetSize(); i++)
	{
		CStackUp* pItem = rhs.m_aStackUp.GetAt(i);
		this->m_aStackUp.Add(pItem->clone());
	}

	
	this->m_DrawingArea = rhs.m_DrawingArea;
	this->m_LibMaterial = rhs.m_LibMaterial;
	this->m_nNoOfPhysicalLayers = rhs.m_nNoOfPhysicalLayers;
	this->m_Pannel = rhs.m_Pannel;
	this->m_RigidFlexiblePcb = rhs.m_RigidFlexiblePcb;
	// Add code to serialize member variable
	return *this;
}


BOOL CBoard::operator==(const CBoard & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CBoard::operator!=(const CBoard& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CBoard* CBoard::clone()
{
	return new CBoard(*this);

}
//const int CBoard::m_nVersion = 1;