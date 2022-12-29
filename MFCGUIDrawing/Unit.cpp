#include "stdafx.h"
#include "Unit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CUnit::CUnit()
{
	cout << "생성자 CUnit() 호출" << endl;
}
CUnit::CUnit(const CUnit& src)
{
	*this = src;
}
CUnit::~CUnit()
{
	cout << "소멸자 ~CUnit() 호출" << endl;
}
void CUnit::vSetCUnit(string sUnit)
{
	m_sUnit = sUnit;
}
CUnit& CUnit::operator =(const CUnit& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sUnit = rhs.m_sUnit;
	// Add code to serialize member variable
	return *this;
}


BOOL CUnit::operator==(const CUnit & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CUnit::operator!=(const CUnit& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CUnit* CUnit::clone()
{
	return new CUnit(*this);

}
// const int CUnit::m_nVersion = 1;