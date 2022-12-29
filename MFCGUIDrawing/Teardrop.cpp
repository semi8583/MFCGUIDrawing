#include "stdafx.h"
#include "Teardrop.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CTeardrop::CTeardrop()
{
	cout << "생성자 CTeardrop() 호출" << endl;
}
CTeardrop::CTeardrop(const CTeardrop& src)
{
	*this = src;
}
CTeardrop:: ~CTeardrop()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	cout << "소멸자 ~CTeardrop() 호출" << endl;
}
void CTeardrop::vSetCopperLibArtworkLayNo(int nLibArtworkLayNo)
{
	this->m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CTeardrop::vSetCopperDrawObj(CDrawObjArray aDrawObj)
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
		this->m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
int CTeardrop::nGetCopperLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
CDrawObjArray CTeardrop::vGetCopperDrawObj()
{
	return m_aDrawObj;
}
void CTeardrop::vAddDrawObj(CDrawObjArray aDrawObj)
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
	}
}
CDrawObj& CTeardrop::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;

	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CTeardrop& CTeardrop::operator =(const CTeardrop& rhs)
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
	CDrawObj* pItem;
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++) 
	{
		pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem);
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CTeardrop::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CTeardrop::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CTeardrop::clone()
{
	return new CTeardrop(*this);
}
// const int CTeardrop::m_nVersion = 1;