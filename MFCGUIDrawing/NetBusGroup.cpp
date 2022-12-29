#include "stdafx.h"
#include "NetBusGroup.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetBusGroup::CNetBusGroup()
{
	cout << "생성자 CNetBusGroup() 호출" << endl;
}
CNetBusGroup::CNetBusGroup(const CNetBusGroup& src)
{
	*this = src;
}
CNetBusGroup::~CNetBusGroup()
{
	cout << "소멸자 ~CNetBusGroup() 호출" << endl;
}
void CNetBusGroup::vSetNetBusGroup(string sBusGroupName, double dMaxBusSkew, double dMaxStrobedSkew, string sControlDevice)
{
	this->m_sBusGroupName = sBusGroupName;
	this->m_dMaxBusSkew = dMaxBusSkew;
	this->m_dMaxStrobedSkew = dMaxStrobedSkew;
	this->m_sControlDevice = sControlDevice;
}
CNetBusGroup& CNetBusGroup::operator =(const CNetBusGroup& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sBusGroupName = rhs.m_sBusGroupName;
	this->m_dMaxBusSkew = rhs.m_dMaxBusSkew;
	this->m_dMaxStrobedSkew = rhs.m_dMaxStrobedSkew;
	this->m_sControlDevice = rhs.m_sControlDevice;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetBusGroup::operator==(const CNetBusGroup & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetBusGroup::operator!=(const CNetBusGroup& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetBusGroup* CNetBusGroup::clone()
{
	return new CNetBusGroup(*this);

}
// const int CNetBusGroup::m_nVersion = 1;


CNetBusGroupArray::CNetBusGroupArray()
{
}
CNetBusGroupArray::CNetBusGroupArray(const CNetBusGroupArray& src)
{
	*this = src;
}
CNetBusGroupArray::~CNetBusGroupArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CNetBusGroup * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CNetBusGroupArray& CNetBusGroupArray::operator =(const CNetBusGroupArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CNetBusGroup * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CNetBusGroup* pItem = new CNetBusGroup();
		pItem->m_dMaxBusSkew = rhs.GetAt(i)->m_dMaxBusSkew;
		pItem->m_dMaxStrobedSkew = rhs.GetAt(i)->m_dMaxStrobedSkew;
		pItem->m_sBusGroupName = rhs.GetAt(i)->m_sBusGroupName;
		pItem->m_sControlDevice = rhs.GetAt(i)->m_sControlDevice;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CNetBusGroupArray::operator==(const CNetBusGroupArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CNetBusGroup* pItem1;
	CNetBusGroup* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CNetBusGroupArray::operator!=(const CNetBusGroupArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetBusGroupArray* CNetBusGroupArray::clone()
{
	return new CNetBusGroupArray(*this);

}