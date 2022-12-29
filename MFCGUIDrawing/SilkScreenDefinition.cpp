#include "stdafx.h"
#include "SilkScreenDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CSilkScreenDefinition::CSilkScreenDefinition()
{
	cout << "생성자 CSilkScreenDefinition() 호출" << endl;
}
CSilkScreenDefinition::CSilkScreenDefinition(const CSilkScreenDefinition& src)
{
	*this = src;
}
CSilkScreenDefinition::~CSilkScreenDefinition()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CSilkScreenDefinition() 호출" << endl;
}
void CSilkScreenDefinition::vSetSilkScreenDefinition(CDrawObjArray aDrawOb)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawOb.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawOb.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
CSilkScreenDefinition& CSilkScreenDefinition::operator =(const CSilkScreenDefinition& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CSilkScreenDefinition::operator==(const CSilkScreenDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CSilkScreenDefinition::operator!=(const CSilkScreenDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CSilkScreenDefinition* CSilkScreenDefinition::clone()
{
	return new CSilkScreenDefinition(*this);

}
// const int CSilkScreenDefinition::m_nVersion = 1;