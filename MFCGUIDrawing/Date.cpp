#include "stdafx.h"
#include "Date.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CDate::CDate()
{
	cout << "생성자 CDate() 호출" << endl;
}
CDate::CDate(const CDate& src)
{
	*this = src;
}
CDate::~CDate()
{
	cout << "소멸자 ~CDate() 호출" << endl;
}
void CDate::vSetCDate(string sMakingDate)
{
	m_sMakingDate = sMakingDate;
}
CDate& CDate::operator =(const CDate& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sMakingDate = rhs.m_sMakingDate;
	// Add code to serialize member variable
	return *this;
}


BOOL CDate::operator==(const CDate & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CDate::operator!=(const CDate& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDate* CDate::clone()
{
	return new CDate(*this);

}
//const int CDate::m_nVersion = 1;