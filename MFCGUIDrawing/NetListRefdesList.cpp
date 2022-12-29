#include "stdafx.h"
#include "NetListRefdesList.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetListRefdesList::CNetListRefdesList()
{
	cout << "생성자 CNetListRefdesList() 호출" << endl;
}
CNetListRefdesList::CNetListRefdesList(const CNetListRefdesList& src)
{
	*this = src;
}
CNetListRefdesList::~CNetListRefdesList()
{
	for (int i = 0; i < m_aNetClassList.GetSize(); i++)
	{
		CNetClassList * pItem = m_aNetClassList.GetAt(i);
		delete pItem;
	}
	m_aNetClassList.RemoveAll();
	cout << "소멸자 ~CNetListRefdesList() 호출" << endl;
}
void CNetListRefdesList::vSetCNetListRefdesList(CReferenceList ReferenceList, CNetList NetList, CCompositeNet CompositeNet, CNetBusGroupList NetBusGroupList, CNetClassListArray aNetClassList)
{
	m_ReferenceList = ReferenceList;
	m_NetList = NetList;
	m_CompositeNet = CompositeNet;
	m_NetBusGroupList = NetBusGroupList;
	
	for (int i = 0; i < m_aNetClassList.GetSize(); i++)
	{
		CNetClassList * pItem = m_aNetClassList.GetAt(i);
		delete pItem;
	}
	m_aNetClassList.RemoveAll();

	for (int i = 0; i < aNetClassList.GetSize(); i++)
	{
		CNetClassList * pItem = aNetClassList.GetAt(i);
		this->m_aNetClassList.Add(pItem->clone());
		delete pItem;
	}

}
CNetListRefdesList& CNetListRefdesList::operator =(const CNetListRefdesList& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_ReferenceList = rhs.m_ReferenceList;
	this->m_NetList = rhs.m_NetList;
	this->m_CompositeNet = rhs.m_CompositeNet;
	this->m_NetBusGroupList = rhs.m_NetBusGroupList;

	for (int i = 0; i < m_aNetClassList.GetSize(); i++)
	{
		CNetClassList * pItem = m_aNetClassList.GetAt(i);
		delete pItem;
	}
	m_aNetClassList.RemoveAll();

	for (int i = 0; i < rhs.m_aNetClassList.GetSize(); i++)
	{
		CNetClassList * pItem = rhs.m_aNetClassList.GetAt(i);
		this->m_aNetClassList.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CNetListRefdesList::operator==(const CNetListRefdesList & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetListRefdesList::operator!=(const CNetListRefdesList& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetListRefdesList* CNetListRefdesList::clone()
{
	return new CNetListRefdesList(*this);

}
// const int CNetListRefdesList::m_nVersion = 1;