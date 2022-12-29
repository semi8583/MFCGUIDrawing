#include "stdafx.h"
#include "NetType.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetType::CNetType()
{
	cout << "생성자 CNetType() 호출" << endl;
}
CNetType::CNetType(const CNetType& src)
{
	*this = src;
}
CNetType::~CNetType()
{
	cout << "소멸자 ~CNetType() 호출" << endl;
}
void CNetType::vSetNetType(int nNetType)
{
	this->m_nNetType = nNetType;
}
CNetType& CNetType::operator =(const CNetType& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nNetType = rhs.m_nNetType;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetType::operator==(const CNetType & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetType::operator!=(const CNetType& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetType* CNetType::clone()
{
	return new CNetType(*this);

}
// const int CNetType::m_nVersion = 1;