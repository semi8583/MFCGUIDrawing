#include "stdafx.h"
#include "GateNo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CGateNo::CGateNo()
{
	cout << "생성자 CGateNo() 호출" << endl;
}
CGateNo::CGateNo(const CGateNo& src)
{
	*this = src;
}
CGateNo::~CGateNo()
{
	cout << "소멸자 ~CGateNo() 호출" << endl;
}
void CGateNo::vSetGateNo(int nGateNo)
{
	m_nGateNo = nGateNo;
}
CGateNo& CGateNo::operator =(const CGateNo& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nGateNo = rhs.m_nGateNo;
	// Add code to serialize member variable
	return *this;
}


BOOL CGateNo::operator==(const CGateNo & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CGateNo::operator!=(const CGateNo& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CGateNo* CGateNo::clone()
{
	return new CGateNo(*this);

}
//const int CGateNo::m_nVersion = 1;