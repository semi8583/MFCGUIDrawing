#include "stdafx.h"
#include "ConnectInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC

#endif
CConnectInfo::CConnectInfo()
{
	cout << "생성자 CConnectInfo() 호출" << endl;
}
CConnectInfo::CConnectInfo(const CConnectInfo& src)
{
	*this = src;
}
CConnectInfo::~CConnectInfo()
{
	cout << "소멸자 ~CConnectInfo() 호출" << endl;
}
void CConnectInfo::vSetConnectInfo(int nRefIndex, int nLibNetNoFirst, int nPinNumberFirst, int nLibNetNoSecond, int nPinNumberSecond)
{
	m_nRefIndex = nRefIndex;
	m_nLibNetNoFirst = nLibNetNoFirst;
	m_nPinNumberFirst = nPinNumberFirst;
	m_nLibNetNoSecond = nLibNetNoSecond;
	m_nPinNumberSecond = nPinNumberSecond;
}
CConnectInfo& CConnectInfo::operator =(const CConnectInfo& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nLibNetNoFirst = rhs.m_nLibNetNoFirst;
	this->m_nLibNetNoSecond = rhs.m_nLibNetNoSecond;
	this->m_nPinNumberFirst = rhs.m_nPinNumberFirst;
	this->m_nPinNumberSecond = rhs.m_nPinNumberSecond;
	this->m_nRefIndex = rhs.m_nRefIndex;
	// Add code to serialize member variable
	return *this;
}


BOOL CConnectInfo::operator==(const CConnectInfo & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CConnectInfo::operator!=(const CConnectInfo& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CConnectInfo* CConnectInfo::clone()
{
	return new CConnectInfo(*this);

}
//const int CConnectInfo::m_nVersion = 1;


CConnectInfoArray::CConnectInfoArray()
{
}
CConnectInfoArray::CConnectInfoArray(const CConnectInfoArray& src)
{
	*this = src;
}
CConnectInfoArray::~CConnectInfoArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CConnectInfo * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CConnectInfoArray& CConnectInfoArray::operator =(const CConnectInfoArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CConnectInfo * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CConnectInfo* pItem = new CConnectInfo();
		pItem->m_nLibNetNoFirst = rhs.GetAt(i)->m_nLibNetNoFirst;
		pItem->m_nLibNetNoSecond = rhs.GetAt(i)->m_nLibNetNoSecond;
		pItem->m_nPinNumberFirst = rhs.GetAt(i)->m_nPinNumberFirst;
		pItem->m_nPinNumberSecond = rhs.GetAt(i)->m_nPinNumberSecond;
		pItem->m_nRefIndex = rhs.GetAt(i)->m_nRefIndex;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CConnectInfoArray::operator==(const CConnectInfoArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CConnectInfo* pItem1;
	CConnectInfo* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CConnectInfoArray::operator!=(const CConnectInfoArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CConnectInfoArray* CConnectInfoArray::clone()
{
	return new CConnectInfoArray(*this);

}