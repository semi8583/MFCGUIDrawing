#include "stdafx.h"
#include "NetClass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetClass::CNetClass()
{
	cout << "생성자 CNetClass() 호출" << endl;
}
CNetClass::CNetClass(const CNetClass& src)
{
	*this = src;
}
CNetClass::~CNetClass()
{
	cout << "소멸자 ~CNetClass() 호출" << endl;
}
void CNetClass::vSetNetClass(string sNetClassName)
{
	m_sNetClassName = sNetClassName;
}
CNetClass& CNetClass::operator =(const CNetClass& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sNetClassName = rhs.m_sNetClassName;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetClass::operator==(const CNetClass & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetClass::operator!=(const CNetClass& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetClass* CNetClass::clone()
{
	return new CNetClass(*this);

}
// const int CNetClass::m_nVersion = 1;