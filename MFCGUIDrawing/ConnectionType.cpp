#include "stdafx.h"
#include "ConnectionType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC

#endif
CConnectionType::CConnectionType()
{
	cout << "생성자 CConnectionType() 호출" << endl;
}
CConnectionType::CConnectionType(const CConnectionType& src)
{
	*this = src;
}
CConnectionType::~CConnectionType()
{
	for (int i = 0; i < this->m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CConnectionType() 호출" << endl;
}
void CConnectionType::vSetCConnectionType(string sConnectionType, CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	m_sConnectionType = sConnectionType;

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
	}

}
void CConnectionType::vAddPolygonToConnectionType(CDrawObj* pDrawObj)
{
	CPolygon* pPolygon;
	if (pPolygon = dynamic_cast<CPolygon*>(pDrawObj))
		m_aDrawObj.Add(pPolygon->clone());
	delete pPolygon;
}
void CConnectionType::vAddPolygonToConnectionType(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CPolygon* pPolygon;
		if (pPolygon = dynamic_cast<CPolygon*>(aDrawObj[i]))
			m_aDrawObj.Add(pPolygon->clone());
		delete pPolygon;
	}
}
CConnectionType& CConnectionType::operator =(const CConnectionType& rhs)
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
	this->m_sConnectionType = rhs.m_sConnectionType;
	// Add code to serialize member variable
	return *this;
}


BOOL CConnectionType::operator==(const CConnectionType & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CConnectionType::operator!=(const CConnectionType& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CConnectionType* CConnectionType::clone()
{
	return new CConnectionType(*this);
}
//const int CConnectionType::m_nVersion = 1;

CConnectionTypeArray::CConnectionTypeArray()
{
}
CConnectionTypeArray::CConnectionTypeArray(const CConnectionTypeArray& src)
{
	*this = src;
}
CConnectionTypeArray::~CConnectionTypeArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CConnectionType * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CConnectionTypeArray& CConnectionTypeArray::operator =(const CConnectionTypeArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CConnectionType * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CConnectionType* pItem = new CConnectionType();
		pItem->m_sConnectionType = rhs.GetAt(i)->m_sConnectionType;
		for (int j = 0; j < rhs.GetAt(i)->m_aDrawObj.GetSize(); j++)
		{
			CDrawObj* pItem2 = rhs.GetAt(i)->m_aDrawObj.GetAt(j);
			pItem->m_aDrawObj.Add(pItem2->clone());
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CConnectionTypeArray::operator==(const CConnectionTypeArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CConnectionType* pItem1;
	CConnectionType* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CConnectionTypeArray::operator!=(const CConnectionTypeArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CConnectionTypeArray* CConnectionTypeArray::clone()
{
	return new CConnectionTypeArray(*this);

}