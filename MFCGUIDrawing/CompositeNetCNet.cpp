#include "stdafx.h"
#include "CompositeNetCNet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CCompositeNetCNet::CCompositeNetCNet()
{
	cout << "생성자 CCompositeNetCNet() 호출" << endl;
}
CCompositeNetCNet::CCompositeNetCNet(const CCompositeNetCNet& src)
{
	*this = src;
}
CCompositeNetCNet::~CCompositeNetCNet()
{
	for (int i = 0; i < m_aConnectInfo.GetSize(); i++)
	{
		CConnectInfo* pItem = m_aConnectInfo.GetAt(i);
		delete pItem;
	}
	m_aConnectInfo.RemoveAll();

	cout << "소멸자 ~CCompositeNetCNet() 호출" << endl;
}
void CCompositeNetCNet::vSetNet(string sCompositeNetName, CArray<int> naLibNetNo, string sNetClassName, CConnectInfoArray aConnectInfo, CNetType NetType, CDiffPair DiffPair, CNetClass NetClassName, CNetElectricConstraints ElectricConstraints)
{
	m_sCompositeNetName = sCompositeNetName;

	for (int i = 0; i < m_aConnectInfo.GetSize(); i++)
	{
		CConnectInfo* pItem = m_aConnectInfo.GetAt(i);
		delete pItem;
	}
	m_aConnectInfo.RemoveAll();

	for (int i = 0; i < naLibNetNo.GetSize(); i++)
		m_naLibNetNo.Add(naLibNetNo[i]);
	m_sNetClassName = sNetClassName;

	for (int i = 0; i < aConnectInfo.GetSize(); i++)
	{
		CConnectInfo * pItem = aConnectInfo.GetAt(i);
		this->m_aConnectInfo.Add(pItem->clone());
		delete pItem;
	}

	m_NetType = NetType;
	m_DiffPair = DiffPair;
	m_NetClass = NetClassName;
	m_ElectricConstraints = ElectricConstraints;
}
CCompositeNetCNet& CCompositeNetCNet::operator =(const CCompositeNetCNet& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_aConnectInfo = rhs.m_aConnectInfo;
	this->m_DiffPair = rhs.m_DiffPair;
	this->m_ElectricConstraints = rhs.m_ElectricConstraints;
	for (int i = 0; i < m_aConnectInfo.GetSize(); i++)
	{
		CConnectInfo* pItem = m_aConnectInfo.GetAt(i);
		delete pItem;
	}
	m_aConnectInfo.RemoveAll();


	for (int i = 0; i < rhs.m_aConnectInfo.GetSize(); i++)
	{
		CConnectInfo * pItem = rhs.m_aConnectInfo.GetAt(i);
		this->m_aConnectInfo.Add(pItem->clone());
	}

	this->m_NetClass = rhs.m_NetClass;
	this->m_NetType = rhs.m_NetType;
	this->m_sCompositeNetName = rhs.m_sCompositeNetName;
	this->m_sNetClassName = rhs.m_sNetClassName;
	// Add code to serialize member variable
	return *this;
}


BOOL CCompositeNetCNet::operator==(const CCompositeNetCNet & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CCompositeNetCNet::operator!=(const CCompositeNetCNet& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CCompositeNetCNet* CCompositeNetCNet::clone()
{
	return new CCompositeNetCNet(*this);

}
//const int CCompositeNetCNet::m_nVersion = 1;


CCompositeNetCNetArray::CCompositeNetCNetArray()
{
}
CCompositeNetCNetArray::CCompositeNetCNetArray(const CCompositeNetCNetArray& src)
{
	*this = src;
}
CCompositeNetCNetArray::~CCompositeNetCNetArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CCompositeNetCNet * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CCompositeNetCNetArray& CCompositeNetCNetArray::operator =(const CCompositeNetCNetArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CCompositeNetCNet * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CCompositeNetCNet *pItem = new CCompositeNetCNet();
		pItem->m_DiffPair = rhs.GetAt(i)->m_DiffPair;
		pItem->m_ElectricConstraints = rhs.GetAt(i)->m_ElectricConstraints;
		pItem->m_NetClass = rhs.GetAt(i)->m_NetClass;
		pItem->m_NetType = rhs.GetAt(i)->m_NetType;
		pItem->m_sCompositeNetName = rhs.GetAt(i)->m_sCompositeNetName;
		pItem->m_sNetClassName = rhs.GetAt(i)->m_sNetClassName;
		for (int j = 0; j < rhs.GetAt(i)->m_aConnectInfo.GetSize(); j++)
		{
			CConnectInfo* pItem2 = new CConnectInfo();
			pItem2->m_nLibNetNoFirst = rhs.GetAt(i)->m_aConnectInfo.GetAt(j)->m_nLibNetNoFirst;
			pItem2->m_nLibNetNoSecond = rhs.GetAt(i)->m_aConnectInfo.GetAt(j)->m_nLibNetNoSecond;
			pItem2->m_nPinNumberFirst = rhs.GetAt(i)->m_aConnectInfo.GetAt(j)->m_nPinNumberFirst;
			pItem2->m_nPinNumberSecond = rhs.GetAt(i)->m_aConnectInfo.GetAt(j)->m_nPinNumberSecond;
			pItem2->m_nRefIndex = rhs.GetAt(i)->m_aConnectInfo.GetAt(j)->m_nRefIndex;
			pItem->m_aConnectInfo.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < rhs.GetAt(i)->m_naLibNetNo.GetSize(); j++)
		{
			int nItem = rhs.GetAt(i)->m_naLibNetNo.GetAt(j);
			pItem->m_naLibNetNo.Add(nItem);
		}
		this->Add(pItem->clone());
		delete pItem;
	}

	return *this;
}

bool CCompositeNetCNetArray::operator==(const CCompositeNetCNetArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CCompositeNetCNet* pItem1;
	CCompositeNetCNet* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CCompositeNetCNetArray::operator!=(const CCompositeNetCNetArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CCompositeNetCNetArray* CCompositeNetCNetArray::clone()
{
	return new CCompositeNetCNetArray(*this);

}