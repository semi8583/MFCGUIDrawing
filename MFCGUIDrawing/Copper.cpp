#include "stdafx.h"
#include "Copper.h"
#include "DrawObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CCopper::CCopper()
{
	cout << "생성자 CCopper() 호출" << endl;
}
CCopper::CCopper(const CCopper& src)
{
	*this = src;
}
CCopper:: ~CCopper()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CCopper() 호출" << endl;
}
void CCopper::vSetCopperLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CCopper::bSetCopperMeshStatus(bool bMeshStatus)
{
	m_bMeshStatus = bMeshStatus;
}
void CCopper::vSetCopperDrawObj(CDrawObjArray aDrawObj)
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
//
int CCopper::nGetCopperLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
bool CCopper::bGetCopperMeshStatus()
{
	return m_bMeshStatus;
}
CDrawObjArray CCopper::vGetCopperDrawObj()
{
	return m_aDrawObj;
}
void CCopper::vAddDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		m_aDrawObj.Add(aDrawObj[i]->clone());
		delete aDrawObj[i];
	}
}
CDrawObj& CCopper::operator =(const CDrawObj& rhs)
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
	// Add code to serialize member variable
	return *this;
}

CCopper& CCopper::operator =(const CCopper& rhs)
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
	this->m_bMeshStatus = rhs.m_bMeshStatus;

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CCopper::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CCopper::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CCopper::clone()
{
	return new CCopper(*this);
}
//const int CCopper::m_nVersion = 1;