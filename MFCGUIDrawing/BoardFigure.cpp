
#include "stdafx.h"
#include "BoardFigure.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CBoardFigure::CBoardFigure()
{
	cout << "생성자 CBoardFigure() 호출" << endl;
}
CBoardFigure::CBoardFigure(const CBoardFigure& src)
{
	*this = src;
}
CBoardFigure::~CBoardFigure()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CBoardFigure() 호출" << endl;
}
void CBoardFigure::vSetBoardFigurevector(int nNoOfPhysicalLayers, CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
	}
	m_aDrawObj.RemoveAll();

	m_nNoOfPhysicalLayers = nNoOfPhysicalLayers;
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
	}
}
void CBoardFigure::vAddPolylineToBoardFigure(CDrawObj* pDrawObj, int nLibArtworkLayNo)
{
	CPolyline* pPolyline;
	if (pPolyline = dynamic_cast<CPolyline*>(pDrawObj))
	{
		pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
		m_aDrawObj.Add(pPolyline->clone());
	}
}
void CBoardFigure::vAddPolylineToBoardFigure(CDrawObjArray aDrawObj,int nLibArtworkLayNo)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CPolyline* pPolyline;

		if (pPolyline = dynamic_cast<CPolyline*>(aDrawObj[i]))
		{
			pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
			m_aDrawObj.Add(pPolyline->clone());
		}
		delete pPolyline;
	}
}
void CBoardFigure::vAddVoidToBoardFigure(CDrawObj* pDrawObj, int nLibArtworkLayNo)
{
	CVoid* pVoid;
	if (pVoid = dynamic_cast<CVoid*>(pDrawObj))
	{
		pVoid->m_nLibArtworkLayNo = nLibArtworkLayNo;
		m_aDrawObj.Add(pVoid->clone());
	}
}
void CBoardFigure::vAddVoidToBoardFigure(CDrawObjArray aDrawObj, int nLibArtworkLayNo)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CPolyline* pPolyline;

		if (pPolyline = dynamic_cast<CPolyline*>(aDrawObj[i]))
		{
			pPolyline->m_nLibArtworkLayNo = nLibArtworkLayNo;
			m_aDrawObj.Add(pPolyline->clone());
		}
	}
}
CBoardFigure& CBoardFigure::operator =(const CBoardFigure& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();


	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}

	this->m_nNoOfPhysicalLayers = rhs.m_nNoOfPhysicalLayers;
	// Add code to serialize member variable
	return *this;
}


BOOL CBoardFigure::operator==(const CBoardFigure & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CBoardFigure::operator!=(const CBoardFigure& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CBoardFigure* CBoardFigure::clone()
{
	return new CBoardFigure(*this);

}
//const int CBoardFigure::m_nVersion = 1;