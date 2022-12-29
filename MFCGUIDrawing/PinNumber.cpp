#include "stdafx.h"
#include "PinNumber.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPinNumber::CPinNumber()
{
	cout << "생성자 CPinNumber() 호출" << endl;
}
CPinNumber::CPinNumber(const CPinNumber& src)
{
	*this = src;
}
CPinNumber::~CPinNumber()
{
	cout << "소멸자 ~CPinNumber() 호출" << endl;
}
void CPinNumber::vSetCPinNumber(int nPinNumber)
{
	this->m_nPinNumber = nPinNumber;
}
CPinNumber& CPinNumber::operator =(const CPinNumber& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nPinNumber = rhs.m_nPinNumber;
	// Add code to serialize member variable
	return *this;
}


BOOL CPinNumber::operator==(const CPinNumber & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPinNumber::operator!=(const CPinNumber& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CPinNumber* CPinNumber::clone()
{
	return new CPinNumber(*this);

}
// const int CPinNumber::m_nVersion = 1;
