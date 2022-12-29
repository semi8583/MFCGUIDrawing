#include "stdafx.h"
#include "LibPenType.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibPenType::CLibPenType()
{
	cout << "생성자 CLibPenType() 호출" << endl;
}
CLibPenType::CLibPenType(const CLibPenType& src)
{
	*this = src;
}
CLibPenType::~CLibPenType()
{
	cout << "소멸자 ~CLibPenType() 호출" << endl;
}
void CLibPenType::vSetCLibPenType(CPenType PenType)
{
	m_PenType = PenType;
}
CLibPenType& CLibPenType::operator =(const CLibPenType& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_PenType = rhs.m_PenType;
	// Add code to serialize member variable
	return *this;
}


BOOL CLibPenType::operator==(const CLibPenType & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibPenType::operator!=(const CLibPenType& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibPenType* CLibPenType::clone()
{
	return new CLibPenType(*this);

}
//const int CLibPenType::m_nVersion = 1;