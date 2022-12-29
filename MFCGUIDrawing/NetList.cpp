#include "stdafx.h"
#include "NetList.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetList::CNetList()
{
	cout << "생성자 CNetList() 호출" << endl;
}
CNetList::CNetList(const CNetList& src)
{
	*this = src;
}
CNetList::~CNetList()
{
	for (int i = 0; i < m_aNetListNet.GetSize(); i++)
	{
		CNetListNet * pItem = m_aNetListNet.GetAt(i);
		delete pItem;
	}
	m_aNetListNet.RemoveAll();
	cout << "소멸자 ~CNetList() 호출" << endl;
}
void CNetList::vSetNetList(CNetListNetArray aNetListNet)
{
	for (int i = 0; i < m_aNetListNet.GetSize(); i++)
	{
		CNetListNet * pItem = m_aNetListNet.GetAt(i);
		delete pItem;
	}
	m_aNetListNet.RemoveAll();

	for (int i = 0; i < aNetListNet.GetSize(); i++)
	{
		CNetListNet * pItem = aNetListNet.GetAt(i);
		m_aNetListNet.Add(pItem->clone());
		delete pItem;
	}
}
CNetList& CNetList::operator =(const CNetList& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aNetListNet.GetSize(); i++)
	{
		CNetListNet * pItem = m_aNetListNet.GetAt(i);
		delete pItem;
	}
	m_aNetListNet.RemoveAll();

	for (int i = 0; i < rhs.m_aNetListNet.GetSize(); i++)
	{
		CNetListNet * pItem = rhs.m_aNetListNet.GetAt(i);
		m_aNetListNet.Add(pItem->clone());
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CNetList::operator==(const CNetList & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetList::operator!=(const CNetList& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetList* CNetList::clone()
{
	return new CNetList(*this);

}
// const int CNetList::m_nVersion = 1;