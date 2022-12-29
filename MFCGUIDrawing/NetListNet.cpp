#include "stdafx.h"
#include "NetListNet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetListNet::CNetListNet()
{
	cout << "생성자 CNetListNet() 호출" << endl;
}
CNetListNet::CNetListNet(const CNetListNet& src)
{
	*this = src;
}
CNetListNet::~CNetListNet()
{
	for (int i = 0; i < m_aNetRef.GetSize(); i++)
	{
		CNetRef * pItem = m_aNetRef.GetAt(i);
		delete pItem;
	}
	m_aNetRef.RemoveAll();
	cout << "소멸자 ~CNetListNet() 호출" << endl;
}
void CNetListNet::vSetCNetListNet(string sNetName, string sNetType, string sNetClassName, int nNetType, CNetStatus NetStatus, CNetRefArray aNetRef, CNetListElectricConstraints ElectricConstraints)
{
	this->m_sNetName = sNetName;
	this->m_sNetType = sNetType;
	this->m_sNetClassName = sNetClassName;
	this->m_nNetType = nNetType;
	this->m_NetStatus = NetStatus;
	this->m_ElectricConstraints = ElectricConstraints;
	for (int i = 0; i < m_aNetRef.GetSize(); i++)
	{
		CNetRef * pItem = m_aNetRef.GetAt(i);
		delete pItem;
	}
	m_aNetRef.RemoveAll();
	for (int i = 0; i < aNetRef.GetSize(); i++)
	{
		CNetRef * pItem = aNetRef.GetAt(i);
		this->m_aNetRef.Add(pItem->clone());
	}
}
CNetListNet& CNetListNet::operator =(const CNetListNet& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sNetName = rhs.m_sNetName;
	this->m_sNetType = rhs.m_sNetType;
	this->m_sNetClassName = rhs.m_sNetClassName;
	this->m_nNetType = rhs.m_nNetType;
	this->m_NetStatus = rhs.m_NetStatus;
	this->m_ElectricConstraints = rhs.m_ElectricConstraints;
	
	for (int i = 0; i < m_aNetRef.GetSize(); i++)
	{
		CNetRef * pItem = m_aNetRef.GetAt(i);
		delete pItem;
	}
	m_aNetRef.RemoveAll();

	for (int i = 0; i < rhs.m_aNetRef.GetSize(); i++)
	{
		CNetRef * pItem = rhs.m_aNetRef.GetAt(i);
		this->m_aNetRef.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CNetListNet::operator==(const CNetListNet & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetListNet::operator!=(const CNetListNet& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetListNet* CNetListNet::clone()
{
	return new CNetListNet(*this);

}
// const int CNetListNet::m_nVersion = 1;



CNetListNetArray::CNetListNetArray()
{
}
CNetListNetArray::CNetListNetArray(const CNetListNetArray& src)
{
	*this = src;
}
CNetListNetArray::~CNetListNetArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CNetListNet * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CNetListNetArray& CNetListNetArray::operator =(const CNetListNetArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CNetListNet * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CNetListNet* pItem = new CNetListNet();
		pItem->m_sNetType = rhs.GetAt(i)->m_sNetType;
		pItem->m_sNetName = rhs.GetAt(i)->m_sNetName;
		pItem->m_sNetClassName = rhs.GetAt(i)->m_sNetClassName;
		pItem->m_nNetType = rhs.GetAt(i)->m_nNetType;
		pItem->m_NetStatus = rhs.GetAt(i)->m_NetStatus;
		pItem->m_ElectricConstraints = rhs.GetAt(i)->m_ElectricConstraints;
		for (int j = 0; j < rhs.GetAt(i)->m_aNetRef.GetSize(); j++)
		{
			CNetRef* pItem2 = new CNetRef();
			pItem2->m_sReferenceName = rhs.GetAt(i)->m_aNetRef.GetAt(j)->m_sReferenceName;
			pItem2->m_nPinNo = rhs.GetAt(i)->m_aNetRef.GetAt(j)->m_nPinNo;
			pItem->m_aNetRef.Add(pItem2->clone());
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CNetListNetArray::operator==(const CNetListNetArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CNetListNet* pItem1;
	CNetListNet* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CNetListNetArray::operator!=(const CNetListNetArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetListNetArray* CNetListNetArray::clone()
{
	return new CNetListNetArray(*this);

}