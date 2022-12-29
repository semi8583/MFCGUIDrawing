#include "stdafx.h"
#include "PenType.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPenType::CPenType()
{
	cout << "생성자 CPenType() 호출" << endl;
}
CPenType::CPenType(const CPenType& src)
{
	*this = src;
}
CPenType::~CPenType()
{
	cout << "소멸자 ~CPenType() 호출" << endl;
}
void CPenType::vSetLibPenType(int nLibPenType, int nPenType, int nTurretNo, double dLineLength, double dDotLineLength, double dLineSpace)
{
	this->m_nLibPenType = nLibPenType;
	this->m_nPenType = nPenType;
	this->m_nTurretNo = nTurretNo;
	this->m_dLineLength = dLineLength;
	this->m_dDotLineLength = dDotLineLength;
	this->m_dLineSpace = dLineSpace;
}
CPenType& CPenType::operator =(const CPenType& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nLibPenType = rhs.m_nLibPenType;
	this->m_nPenType = rhs.m_nPenType;
	this->m_nTurretNo = rhs.m_nTurretNo;
	this->m_dLineLength = rhs.m_dLineLength;
	this->m_dDotLineLength = rhs.m_dDotLineLength;
	this->m_dLineSpace = rhs.m_dLineSpace;
	// Add code to serialize member variable
	return *this;
}


BOOL CPenType::operator==(const CPenType & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPenType::operator!=(const CPenType& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPenType* CPenType::clone()
{
	return new CPenType(*this);

}

// const int CPenType::m_nVersion = 1;