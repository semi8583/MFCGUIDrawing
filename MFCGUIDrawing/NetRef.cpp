#include "stdafx.h"
#include "NetRef.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetRef::CNetRef()
{
	cout << "생성자 CNetRef() 호출" << endl;
}
CNetRef::CNetRef(const CNetRef& src)
{
	*this = src;
}
CNetRef::~CNetRef()
{
	cout << "소멸자 ~CNetRef() 호출" << endl;
}
void CNetRef::vSetNetRef(string sReferenceName, int nPinNo)
{
	m_sReferenceName = sReferenceName;
	m_nPinNo = nPinNo;
}
CNetRef& CNetRef::operator =(const CNetRef& rhs)
{
	if (this == &rhs)
		return *this;
	m_sReferenceName = rhs.m_sReferenceName;
	m_nPinNo = rhs.m_nPinNo;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetRef::operator==(const CNetRef & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetRef::operator!=(const CNetRef& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetRef* CNetRef::clone()
{
	return new CNetRef(*this);

}
// const int CNetRef::m_nVersion = 1;


CNetRefArray::CNetRefArray()
{
}
CNetRefArray::CNetRefArray(const CNetRefArray& src)
{
	*this = src;
}
CNetRefArray::~CNetRefArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CNetRef * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CNetRefArray& CNetRefArray::operator =(const CNetRefArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CNetRef * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CNetRef* pItem = new CNetRef();
		pItem->m_nPinNo = rhs.GetAt(i)->m_nPinNo;
		pItem->m_sReferenceName = rhs.GetAt(i)->m_sReferenceName;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CNetRefArray::operator==(const CNetRefArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CNetRef* pItem1;
	CNetRef* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CNetRefArray::operator!=(const CNetRefArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetRefArray* CNetRefArray::clone()
{
	return new CNetRefArray(*this);

}