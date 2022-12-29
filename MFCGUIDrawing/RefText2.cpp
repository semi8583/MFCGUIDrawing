#include "stdafx.h"
#include "RefText2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRefText2::CRefText2()
{
	cout << "생성자 CRefText2() 호출" << endl;
}
CRefText2::CRefText2(const CRefText2& src)
{
	*this = src;
}
CRefText2::~CRefText2()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CRefText2() 호출" << endl;
}
void CRefText2::vSetRefText2(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj *  pItem = aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
}
CRefText2& CRefText2::operator =(const CRefText2& rhs)
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


BOOL CRefText2::operator==(const CRefText2 & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRefText2::operator!=(const CRefText2& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRefText2* CRefText2::clone()
{
	return new CRefText2(*this);

}
 //const int CRefText2::m_nVersion = 1;