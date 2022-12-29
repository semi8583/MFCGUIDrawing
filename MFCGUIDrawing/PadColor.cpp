#include "stdafx.h"
#include "PadColor.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPadColor::CPadColor()
{
	cout << "생성자 CPadColor() 호출" << endl;
}
CPadColor::CPadColor(const CPadColor& src)
{
	*this = src;
}
CPadColor::~CPadColor()
{
	cout << "소멸자 ~CPadColor() 호출" << endl;
}
void CPadColor::vSetPadColor(int nR, int nG, int nB)
{
	this->m_nR = nR;
	this->m_nG = nG;
	this->m_nB = nB;
}
CPadColor& CPadColor::operator =(const CPadColor& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nR = rhs.m_nR;
	this->m_nG = rhs.m_nG;
	this->m_nB = rhs.m_nB;

	// Add code to serialize member variable
	return *this;
}


BOOL CPadColor::operator==(const CPadColor & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPadColor::operator!=(const CPadColor& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPadColor* CPadColor::clone()
{
	return new CPadColor(*this);

}
// const int CPadColor::m_nVersion = 1;