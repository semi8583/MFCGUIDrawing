#include "stdafx.h"
#include "Route.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRoute::CRoute()
{
	cout << "생성자 CRoute() 호출" << endl;
}
CRoute::CRoute(const CRoute& src)
{
	*this = src;
}
CRoute::~CRoute()
{
	for (int i = 0; i < m_aRnet.GetSize(); i++)
	{
		CRNET * pItem = m_aRnet.GetAt(i);
		delete pItem;
	}
	m_aRnet.RemoveAll();
	cout << "소멸자 ~CRoute() 호출" << endl;
}
void CRoute::vSetRoute(CRNETArray aRnet)
{
	for (int i = 0; i < m_aRnet.GetSize(); i++)
	{
		CRNET * pItem = m_aRnet.GetAt(i);
		delete pItem;
	}
	m_aRnet.RemoveAll();

	for (int i = 0; i < aRnet.GetSize(); i++)
	{
		CRNET * pItem = aRnet.GetAt(i);
		this->m_aRnet.Add(pItem->clone());
		delete pItem;
	}
}
CRoute& CRoute::operator =(const CRoute& rhs)
{
	if (this == &rhs)
		return *this;
	
	for (int i = 0; i < m_aRnet.GetSize(); i++)
	{
		CRNET * pItem = m_aRnet.GetAt(i);
		delete pItem;
	}
	m_aRnet.RemoveAll();

	for (int i = 0; i < rhs.m_aRnet.GetSize(); i++)
	{
		CRNET * pItem = rhs.m_aRnet.GetAt(i);
		this->m_aRnet.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}

BOOL CRoute::operator==(const CRoute & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRoute::operator!=(const CRoute& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRoute* CRoute::clone()
{
	return new CRoute(*this);

}
// const int CRoute::m_nVersion = 1;