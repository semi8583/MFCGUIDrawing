#include "stdafx.h"
#include "Tur.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CTur::CTur()
{
	cout << "생성자 CTur() 호출" << endl;
}
CTur::CTur(const CTur& src)
{
	*this = src;
}
CTur::~CTur()
{
	cout << "소멸자 ~CTur() 호출" << endl;
}
void CTur::vSetCTur(int nLibTurretNo, string sTurretType, double dInnerSize, double dOuterSize, CWing Wing)
{
	this->m_nLibTurretNo = nLibTurretNo;
	this->m_sTurretType = sTurretType;
	this->m_dInnerSize = dInnerSize;
	this->m_dOuterSize = dOuterSize;
	this->m_Wing = Wing;
}
CTur& CTur::operator =(const CTur& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nLibTurretNo = rhs.m_nLibTurretNo;
	this->m_sTurretType = rhs.m_sTurretType;
	this->m_dInnerSize = rhs.m_dInnerSize;
	this->m_dOuterSize = rhs.m_dOuterSize;
	this->m_Wing = rhs.m_Wing;
	// Add code to serialize member variable
	return *this;
}


BOOL CTur::operator==(const CTur & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CTur::operator!=(const CTur& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CTur* CTur::clone()
{
	return new CTur(*this);

}
// const int CTur::m_nVersion = 1;

CTurArray::CTurArray()
{
}
CTurArray::CTurArray(const CTurArray& src)
{
	*this = src;
}
CTurArray::~CTurArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CTur * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CTurArray& CTurArray::operator =(const CTurArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CTur * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CTur* pItem = new CTur();
		pItem->m_dInnerSize = rhs.GetAt(i)->m_dInnerSize;
		pItem->m_dOuterSize = rhs.GetAt(i)->m_dOuterSize;
		pItem->m_nLibTurretNo = rhs.GetAt(i)->m_nLibTurretNo;
		pItem->m_sTurretType = rhs.GetAt(i)->m_sTurretType;
		pItem->m_Wing = rhs.GetAt(i)->m_Wing;
		this->Add(pItem->clone());
	}
	return *this;
}

bool CTurArray::operator==(const CTurArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CTur* pItem1;
	CTur* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CTurArray::operator!=(const CTurArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CTurArray* CTurArray::clone()
{
	return new CTurArray(*this);

}