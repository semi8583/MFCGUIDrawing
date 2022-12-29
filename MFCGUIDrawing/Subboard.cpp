#include "stdafx.h"
#include "Subboard.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CSubboard::CSubboard()
{
	cout << "생성자 CSubboard() 호출" << endl;
}
CSubboard::CSubboard(const CSubboard& src)
{
	*this = src;
}
CSubboard::~CSubboard()
{
	for (int i = 0; i < m_aCDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aCDrawObj.GetAt(i);
		delete pItem;
	}
	m_aCDrawObj.RemoveAll();
	cout << "소멸자 ~CSubboard() 호출" << endl;
}
void CSubboard::vSetSubboard(string sSubBoardName, CDrawObjArray aDrawObj)
{
	this->m_sSubBoardName = sSubBoardName;
	for (int i = 0; i < m_aCDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aCDrawObj.GetAt(i);
		delete pItem;
	}
	m_aCDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		this->m_aCDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
CSubboard& CSubboard::operator =(const CSubboard& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sSubBoardName = rhs.m_sSubBoardName;

	for (int i = 0; i < m_aCDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aCDrawObj.GetAt(i);
		delete pItem;
	}
	m_aCDrawObj.RemoveAll();

	for (int i = 0; i < rhs.m_aCDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aCDrawObj.GetAt(i);
		this->m_aCDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CSubboard::operator==(const CSubboard & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CSubboard::operator!=(const CSubboard& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CSubboard* CSubboard::clone()
{
	return new CSubboard(*this);

}
// const int CSubboard::m_nVersion = 1;