#include "stdafx.h"
#include "LibText.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibText::CLibText()
{
	cout << "생성자 CLibText() 호출" << endl;
}
CLibText::CLibText(const CLibText& src)
{
	*this = src;
}
CLibText::~CLibText()
{
	for (int i = 0; i < m_aText.GetSize(); i++)
	{
		CLibTextText * pItem = m_aText.GetAt(i);
		delete pItem;
	}
	m_aText.RemoveAll();
	cout << "소멸자 ~CLibText() 호출" << endl;
}
void CLibText::vSetCLibText(CLibTextTextArray aText)
{
	for (int i = 0; i < m_aText.GetSize(); i++)
	{
		CLibTextText * pItem = m_aText.GetAt(i);
		delete pItem;
	}
	m_aText.RemoveAll();

	for (int i = 0; i < aText.GetSize(); i++)
	{
		CLibTextText * pItem = aText.GetAt(i);
		this->m_aText.Add(pItem->clone());
		delete pItem;
	}

}
CLibText& CLibText::operator =(const CLibText& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aText.GetSize(); i++)
	{
		CLibTextText * pItem = m_aText.GetAt(i);
		delete pItem;
	}
	m_aText.RemoveAll();

	for (int i = 0; i < rhs.m_aText.GetSize(); i++)
	{
		CLibTextText * pItem = rhs.m_aText.GetAt(i);
		this->m_aText.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLibText::operator==(const CLibText & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibText::operator!=(const CLibText& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibText* CLibText::clone()
{
	return new CLibText(*this);

}
//const int CLibText::m_nVersion = 1;