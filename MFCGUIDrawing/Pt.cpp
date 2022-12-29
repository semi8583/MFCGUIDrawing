#include "stdafx.h"
#include "Pt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPt::CPt()
{
	cout << "생성자 CPt() 호출" << endl;
}
CPt::CPt(const CPt& src)
{
	*this = src;
}
CPt::~CPt()
{
	cout << "소멸자 ~CPt() 호출" << endl;
}
void CPt::vSetPtLibArtworkLayNum(int nLibArtworkLayNum)
{
	m_nLibArtworkLayNum = nLibArtworkLayNum;
}
void CPt::vSetPtLibTurretNum(int nLibTurretNum)
{
	m_nLibTurretNum = nLibTurretNum;
}
void CPt::vSetPtPtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CPt::vSetPtPtY(double dPtY)
{
	m_dPtY = dPtY;
}
int CPt::nGetPtLibArtworkLayNum()
{
	return m_nLibArtworkLayNum;
}
int CPt::nGetPtLibTurretNum()
{
	return m_nLibTurretNum;
}
double CPt::dGetPtPtX()
{
	return m_dPtX;
}
double CPt::dGetPtPtY()
{
	return m_dPtY;
}
CDrawObj& CPt::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CPt& CPt::operator =(const CPt& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nLibArtworkLayNum = rhs.m_nLibArtworkLayNum;
	this->m_nLibTurretNum = rhs.m_nLibTurretNum;
	// Add code to serialize member variable
	return *this;
}

BOOL CPt::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPt::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CPt::clone()
{
	return new CPt(*this);
}
// const int CPt::m_nVersion = 1;