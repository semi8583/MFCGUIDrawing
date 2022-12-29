#include "stdafx.h"
#include "LibPadStack.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibPadStack::CLibPadStack()
{
	cout << "생성자 CLibPadStack() 호출" << endl;
}
CLibPadStack::CLibPadStack(const CLibPadStack& src)
{
	*this = src;
}
CLibPadStack::~CLibPadStack()
{
	for (int i = 0; i < m_aPadStackDefinition.GetSize(); i++)
	{
		CPadDefinition * pItem = m_aPadStackDefinition.GetAt(i);
		delete pItem;
	}
	m_aPadStackDefinition.RemoveAll();
	cout << "소멸자 ~CLibPadStack() 호출" << endl;
}
void CLibPadStack::vSetCLibPadStack(CPadDefinitionArray aPadStackDefinition, CLocalShape LocalShape)
{
	for (int i = 0; i < m_aPadStackDefinition.GetSize(); i++)
	{
		CPadDefinition * pItem = m_aPadStackDefinition.GetAt(i);
		delete pItem;
	}
	m_aPadStackDefinition.RemoveAll();

	for (int i = 0; i < aPadStackDefinition.GetSize(); i++)
	{
		CPadDefinition * pItem = aPadStackDefinition.GetAt(i);
		this->m_aPadStackDefinition.Add(pItem->clone());
		delete pItem;
	}

	m_LocalShape = LocalShape;
}
CLibPadStack& CLibPadStack::operator =(const CLibPadStack& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aPadStackDefinition.GetSize(); i++)
	{
		CPadDefinition * pItem = m_aPadStackDefinition.GetAt(i);
		delete pItem;
	}
	m_aPadStackDefinition.RemoveAll();

	for (int i = 0; i < rhs.m_aPadStackDefinition.GetSize(); i++)
	{
		CPadDefinition * pItem = rhs.m_aPadStackDefinition.GetAt(i);
		this->m_aPadStackDefinition.Add(pItem->clone());
	}

	m_LocalShape = this->m_LocalShape;
	// Add code to serialize member variable
	return *this;
}


BOOL CLibPadStack::operator==(const CLibPadStack & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibPadStack::operator!=(const CLibPadStack& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibPadStack* CLibPadStack::clone()
{
	return new CLibPadStack(*this);

}
//const int CLibPadStack::m_nVersion = 1;