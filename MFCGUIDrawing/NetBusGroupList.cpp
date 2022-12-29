#include "stdafx.h"
#include "NetBusGroupList.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetBusGroupList::CNetBusGroupList()
{
	cout << "생성자 CNetBusGroupList() 호출" << endl;
}
CNetBusGroupList::CNetBusGroupList(const CNetBusGroupList& src)
{
	*this = src;
}
CNetBusGroupList::~CNetBusGroupList()
{
	for (int i = 0; i < m_aNetBusGroup.GetSize(); i++)
	{
		CNetBusGroup * pItem = m_aNetBusGroup.GetAt(i);
		delete pItem;
	}
	m_aNetBusGroup.RemoveAll();

	for (int i = 0; i < m_aNetIndex.GetSize(); i++)
	{
		CNetIndex * pItem = m_aNetIndex.GetAt(i);
		delete pItem;
	}
	m_aNetIndex.RemoveAll();

	for (int i = 0; i < m_aStrobedNetIndex.GetSize(); i++)
	{
		CStrobedNetIndex * pItem = m_aStrobedNetIndex.GetAt(i);
		delete pItem;
	}
	m_aStrobedNetIndex.RemoveAll();

	cout << "소멸자 ~CNetBusGroupList() 호출" << endl;
}
void CNetBusGroupList::vSetNetIndex(CNetBusGroupArray aNetBusGroup, CStrobedNetIndexArray aStrobedNetIndex, CNetIndexArray aNetIndex)
{
	for (int i = 0; i < m_aNetBusGroup.GetSize(); i++)
	{
		CNetBusGroup * pItem = m_aNetBusGroup.GetAt(i);
		delete pItem;
	}
	m_aNetBusGroup.RemoveAll();

	for (int i = 0; i < m_aNetIndex.GetSize(); i++)
	{
		CNetIndex * pItem = m_aNetIndex.GetAt(i);
		delete pItem;
	}
	m_aNetIndex.RemoveAll();

	for (int i = 0; i < m_aStrobedNetIndex.GetSize(); i++)
	{
		CStrobedNetIndex * pItem = m_aStrobedNetIndex.GetAt(i);
		delete pItem;
	}
	m_aStrobedNetIndex.RemoveAll();

	for (int i = 0; i < aNetBusGroup.GetSize(); i++)
	{
		CNetBusGroup * pItem1 = aNetBusGroup.GetAt(i);
		m_aNetBusGroup.Add(pItem1->clone());
		delete pItem1;
	}

	for (int i = 0; i < aStrobedNetIndex.GetSize(); i++)
	{
		CStrobedNetIndex * pItem2 = aStrobedNetIndex.GetAt(i);
		m_aStrobedNetIndex.Add(pItem2->clone());
		delete pItem2;
	}

	this->m_aNetIndex.RemoveAll();
	for (int i = 0; i < aNetIndex.GetSize(); i++)
	{
		CNetIndex * pItem3 = aNetIndex.GetAt(i);
		m_aNetIndex.Add(pItem3->clone());
		delete pItem3;
	}
}
CNetBusGroupList& CNetBusGroupList::operator =(const CNetBusGroupList& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aNetBusGroup.GetSize(); i++)
	{
		CNetBusGroup * pItem = m_aNetBusGroup.GetAt(i);
		delete pItem;
	}
	m_aNetBusGroup.RemoveAll();

	for (int i = 0; i < m_aNetIndex.GetSize(); i++)
	{
		CNetIndex * pItem = m_aNetIndex.GetAt(i);
		delete pItem;
	}
	m_aNetIndex.RemoveAll();

	for (int i = 0; i < m_aStrobedNetIndex.GetSize(); i++)
	{
		CStrobedNetIndex * pItem = m_aStrobedNetIndex.GetAt(i);
		delete pItem;
	}
	m_aStrobedNetIndex.RemoveAll();

	for (int i = 0; i < rhs.m_aNetBusGroup.GetSize(); i++)
	{
		CNetBusGroup * pItem1 = rhs.m_aNetBusGroup.GetAt(i);
		m_aNetBusGroup.Add(pItem1->clone());
	}

	for (int i = 0; i < rhs.m_aStrobedNetIndex.GetSize(); i++)
	{
		CStrobedNetIndex * pItem2 = rhs.m_aStrobedNetIndex.GetAt(i);
		m_aStrobedNetIndex.Add(pItem2->clone());
	}

	this->m_aNetIndex.RemoveAll();
	for (int i = 0; i < rhs.m_aNetIndex.GetSize(); i++)
	{
		CNetIndex * pItem3 = rhs.m_aNetIndex.GetAt(i);
		m_aNetIndex.Add(pItem3->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CNetBusGroupList::operator==(const CNetBusGroupList & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetBusGroupList::operator!=(const CNetBusGroupList& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetBusGroupList* CNetBusGroupList::clone()
{
	return new CNetBusGroupList(*this);

}
// const int CNetBusGroupList::m_nVersion = 1;