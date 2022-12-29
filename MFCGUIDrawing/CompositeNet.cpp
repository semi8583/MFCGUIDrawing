#include "stdafx.h"
#include "CompositeNet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CCompositeNet::CCompositeNet()
{
	cout << "생성자 CCompositeNet() 호출" << endl;
}
CCompositeNet::CCompositeNet(const CCompositeNet& src)
{
	*this = src;
}
CCompositeNet::~CCompositeNet()
{
	for (int i = 0; i < m_aCompositeNet.GetSize(); i++)
	{
		CCompositeNetCNet* pItem = m_aCompositeNet.GetAt(i);
		delete pItem;
	}
	m_aCompositeNet.RemoveAll();
	cout << "소멸자 ~CCompositeNet() 호출" << endl;
}
void CCompositeNet::vSetCompositeNet(CCompositeNetCNetArray aCompositeNet)
{
	for (int i = 0; i < m_aCompositeNet.GetSize(); i++)
	{
		CCompositeNetCNet* pItem = m_aCompositeNet.GetAt(i);
		delete pItem;
	}
	m_aCompositeNet.RemoveAll();

	for (int i = 0; i < aCompositeNet.GetSize(); i++)
	{
		CCompositeNetCNet * pItem = aCompositeNet.GetAt(i);
		this->m_aCompositeNet.Add(pItem->clone());
		delete pItem;
	}

}
CCompositeNet& CCompositeNet::operator =(const CCompositeNet& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aCompositeNet.GetSize(); i++)
	{
		CCompositeNetCNet* pItem = m_aCompositeNet.GetAt(i);
		delete pItem;
	}
	m_aCompositeNet.RemoveAll();

	for (int i = 0; i < rhs.m_aCompositeNet.GetSize(); i++)
	{
		CCompositeNetCNet* pItem = rhs.m_aCompositeNet.GetAt(i);
		this->m_aCompositeNet.Add(pItem->clone());
	}

	this->m_aCompositeNet = rhs.m_aCompositeNet;
	// Add code to serialize member variable
	return *this;
}


BOOL CCompositeNet::operator==(const CCompositeNet & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CCompositeNet::operator!=(const CCompositeNet& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CCompositeNet* CCompositeNet::clone()
{
	return new CCompositeNet(*this);

}
//const int CCompositeNet::m_nVersion = 1;