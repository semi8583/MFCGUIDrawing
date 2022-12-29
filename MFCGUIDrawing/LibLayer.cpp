#include "stdafx.h"
#include "LibLayer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibLayer::CLibLayer()
{
	cout << "생성자 CLibLayer() 호출" << endl;
}
CLibLayer::CLibLayer(const CLibLayer& src)
{
	*this = src;
}
CLibLayer::~CLibLayer()
{
	for (int i = 0; i < this->m_aLay.GetSize(); i++)
	{
		CLay * pItem = m_aLay.GetAt(i);
		delete pItem;
	}
	m_aLay.RemoveAll();
	cout << "소멸자 ~CLibLayer() 호출" << endl;
}
void CLibLayer::vSetCLibLayer(CLayArray aLay)
{
	for (int i = 0; i < this->m_aLay.GetSize(); i++)
	{
		CLay * pItem = m_aLay.GetAt(i);
		delete pItem;
	}
	m_aLay.RemoveAll();

	for (int i = 0; i < aLay.GetSize(); i++)
	{
		CLay * pItem = aLay.GetAt(i);
		this->m_aLay.Add(pItem->clone());
		delete pItem;
	}

}
CLibLayer& CLibLayer::operator =(const CLibLayer& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < this->m_aLay.GetSize(); i++)
	{
		CLay * pItem = m_aLay.GetAt(i);
		delete pItem;
	}
	m_aLay.RemoveAll();

	for (int i = 0; i < rhs.m_aLay.GetSize(); i++)
	{
		CLay * pItem = rhs.m_aLay.GetAt(i);
		this->m_aLay.Add(pItem->clone());
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CLibLayer::operator==(const CLibLayer & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibLayer::operator!=(const CLibLayer& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibLayer* CLibLayer::clone()
{
	return new CLibLayer(*this);

}
//const int CLibLayer::m_nVersion = 1;