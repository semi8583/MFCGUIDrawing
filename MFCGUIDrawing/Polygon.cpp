#include "stdafx.h"
#include "Polygon.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPolygon::CPolygon()
{
	cout << "생성자 CPolygon() 호출" << endl;
}
CPolygon::CPolygon(const CPolygon& src)
{
	*this = src;
}
CPolygon:: ~CPolygon()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CPolygon() 호출" << endl;
}
void CPolygon::vSetPolygonLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CPolygon::vSetPolygonDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
int CPolygon::nGetPolygonLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
CDrawObjArray CPolygon::vGetPolygonDrawObj()
{
	return m_aDrawObj;
}
void CPolygon::vAddDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
void CPolygon::vAddLineAndArc(CDrawObj* aDrawObj)
{
	CLine* pLine;
	CArc* pArc;
	if (pLine = dynamic_cast<CLine*>(aDrawObj)) //line하고 arc에만 virtual 함수 사용 
	{
		m_aDrawObj.Add(pLine->clone());
		delete pLine;
	}
	else if (pArc = dynamic_cast<CArc*>(aDrawObj)) //line하고 arc에만 virtual 함수 사용 
	{
		m_aDrawObj.Add(pArc->clone());
		delete pArc;
	}
}

CDrawObj& CPolygon::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}

CPolygon& CPolygon::operator =(const CPolygon& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	CDrawObj::operator=(rhs);
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CPolygon::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPolygon::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CPolygon::clone()
{
	return new CPolygon(*this);
}
// const int CPolygon::m_nVersion = 1;