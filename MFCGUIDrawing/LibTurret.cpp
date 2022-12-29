#include "stdafx.h"
#include "LibTurret.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibTurret::CLibTurret()
{
	cout << "생성자 CLibTurret() 호출" << endl;
}
CLibTurret::CLibTurret(const CLibTurret& src)
{
	*this = src;
}
CLibTurret::~CLibTurret()
{
	for (int i = 0; i < m_aTur.GetSize(); i++)
	{
		CTur * pItem = m_aTur.GetAt(i);
		delete pItem;
	}
	m_aTur.RemoveAll();
	cout << "소멸자 ~CLibTurret() 호출" << endl;
}
void CLibTurret::vSetCLibTurret(CTurArray aTur)
{
	for (int i = 0; i < m_aTur.GetSize(); i++)
	{
		CTur * pItem = m_aTur.GetAt(i);
		delete pItem;
	}
	m_aTur.RemoveAll();

	for (int i = 0; i < aTur.GetSize(); i++)
	{
		CTur * pItem = aTur.GetAt(i);
		this->m_aTur.Add(pItem->clone());
		delete pItem;
	}

}
CLibTurret& CLibTurret::operator =(const CLibTurret& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aTur.GetSize(); i++)
	{
		CTur * pItem = m_aTur.GetAt(i);
		delete pItem;
	}
	m_aTur.RemoveAll();

	for (int i = 0; i < rhs.m_aTur.GetSize(); i++)
	{
		CTur * pItem = rhs.m_aTur.GetAt(i);
		this->m_aTur.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLibTurret::operator==(const CLibTurret & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibTurret::operator!=(const CLibTurret& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibTurret* CLibTurret::clone()
{
	return new CLibTurret(*this);

}
//const int CLibTurret::m_nVersion = 1;