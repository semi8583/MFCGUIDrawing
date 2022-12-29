#include "stdafx.h"
#include "PadStack.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPadStack::CPadStack()
{
	cout << "생성자 CPadStack() 호출" << endl;
}
CPadStack::CPadStack(const CPadStack& src)
{
	*this = src;
}
CPadStack::~CPadStack()
{
	cout << "소멸자 ~CPadStack() 호출" << endl;
}
void CPadStack::vSetPadStackLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CPadStack::vSetPadStackLibPadstackNo(int nLibPadstackNo)
{
	m_nLibPadstackNo = nLibPadstackNo;
}
void CPadStack::vSetPadStackAngle(double dAngle)
{
	m_dAngle = dAngle;
}
void CPadStack::vSetPadStackTeardropExist(string sTeardropExist)
{
	m_sTeardropExist = sTeardropExist;
}
void CPadStack::vSetPadStackPtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CPadStack::vSetPadStackPtY(double dPtY)
{
	m_dPtY = dPtY;
}
int CPadStack::nGetPadStackLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
int CPadStack::nGetPadStackLibPadstackNo()
{
	return m_nLibPadstackNo;
}
double CPadStack::dGetPadStackAngle()
{
	return m_dAngle;
}
string CPadStack::sGetPadStackTeardropExist()
{
	return m_sTeardropExist;
}
double CPadStack::dGetPadStackPtX()
{
	return m_dPtX;
}
double CPadStack::dGetPadStackPtY()
{
	return m_dPtY;
}
CDrawObj& CPadStack::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CPadStack& CPadStack::operator =(const CPadStack& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	this->m_dAngle = rhs.m_dAngle;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nLibArtworkLayNo = rhs.m_nLibPadstackNo;
	this->m_nLibPadstackNo = rhs.m_nLibPadstackNo;
	this->m_sTeardropExist = rhs.m_sTeardropExist;

	// Add code to serialize member variable
	return *this;
}

BOOL CPadStack::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPadStack::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CPadStack::clone()
{
	return new CPadStack(*this);
}
// const int CPadStack::m_nVersion = 1;