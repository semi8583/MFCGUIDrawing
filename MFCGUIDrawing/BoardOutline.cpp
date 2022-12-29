
#include "stdafx.h"
#include "BoardOutline.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CBoardOutline::CBoardOutline()
{
	cout << "생성자 CBoardOutline() 호출" << endl;
}
CBoardOutline::CBoardOutline(const CBoardOutline& src)
{
	*this = src;
}
CBoardOutline::~CBoardOutline()
{
	for (int i = 0; i < m_aBoardOutline.GetSize(); i++)
	{
		CDrawObj * pItem = m_aBoardOutline.GetAt(i);
		delete pItem;
	}
	m_aBoardOutline.RemoveAll();
	cout << "소멸자 ~CBoardOutline() 호출" << endl;
}
void CBoardOutline::vSetCBoardOutline(CDrawObjArray aBoardOutline)
{
	for (int i = 0; i < m_aBoardOutline.GetSize(); i++)
	{
		CDrawObj * pItem = m_aBoardOutline.GetAt(i);
		delete pItem;
	}
	m_aBoardOutline.RemoveAll();

	for (int i = 0; i < aBoardOutline.GetSize(); i++)
	{
		CDrawObj * pItem = aBoardOutline.GetAt(i);
		m_aBoardOutline.Add(pItem->clone());
		delete pItem;
	}
}

CBoardOutline& CBoardOutline::operator =(const CBoardOutline& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aBoardOutline.GetSize(); i++)
	{
		CDrawObj * pItem = m_aBoardOutline.GetAt(i);
		delete pItem;
	}
	m_aBoardOutline.RemoveAll();


	for (int i = 0; i < rhs.m_aBoardOutline.GetSize(); i++)
	{
		CDrawObj* pItem = rhs.m_aBoardOutline.GetAt(i);
		this->m_aBoardOutline.Add(pItem->clone());
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CBoardOutline::operator==(const CBoardOutline & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CBoardOutline::operator!=(const CBoardOutline& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CBoardOutline* CBoardOutline::clone()
{
	return new CBoardOutline(*this);

}