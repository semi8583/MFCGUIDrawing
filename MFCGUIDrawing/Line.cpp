#include "stdafx.h"
#include "Line.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLine::CLine()
{
	cout << "생성자 CLine() 호출" << endl;
}
CLine::CLine(const CLine& src)
{
	*this = src;
}
CLine::~CLine()
{
	cout << "소멸자 ~CLine() 호출" << endl;
}
void CLine::vSetLineLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CLine::vSetLineLibTurretNo(int nLibTurretNo)
{
	m_nLibTurretNo = nLibTurretNo;
}
void CLine::vSetLineStartPtX(double dStartPtX)
{
	m_dStartPtX = dStartPtX;
}
void CLine::vSetLineStartPtY(double dStartPtY)
{
	m_dStartPtY = dStartPtY;
}
void CLine::vSetLineEndPtX(double dEndPtX)
{
	m_dEndPtX = dEndPtX;
}
void CLine::vSetLineEndPtY(double dEndPtY)
{
	m_dEndPtY = dEndPtY;
}
void CLine::vSetLineStartFilletExist(int nStartFilletExist)
{
	m_nStartFilletExist = nStartFilletExist;
}
void CLine::vSetLineStartFilletLength(double dStartFilletLength)
{
	m_dStartFilletLength = dStartFilletLength;
}
void CLine::vSetLineEndFilletExist(int nEndFilletExist)
{
	m_nEndFilletExist = nEndFilletExist;
}
void CLine::vSetLineEndFilletLength(double dEndFilletLength)
{
	m_dEndFilletLength = dEndFilletLength;
}
void CLine::vSetLineLibPenType(int nLibPenType)
{
	m_nLibPenType = nLibPenType;
}
///
int CLine::nGetLineLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
int CLine::nGetLineLibTurretNo()
{
	return m_nLibTurretNo;
}
double CLine::dGetLineStartPtX()
{
	return m_dStartPtX;
}
double CLine::dGetLineStartPtY()
{
	return m_dStartPtY;
}
double CLine::dGetLineEndPtX()
{
	return m_dEndPtX;
}
double CLine::dGetLineEndPtY()
{
	return m_dEndPtY;
}
int CLine::nGetLineStartFilletExist()
{
	return m_nStartFilletExist;
}
double CLine::dGetLineStartFilletLength()
{
	return m_dStartFilletLength;
}
int CLine::nGetLineEndFilletExist()
{
	return m_nEndFilletExist;
}
double  CLine::dGetLineEndFilletLength()
{
	return m_dEndFilletLength;
}
int CLine::nGetLineLibPenType()
{
	return m_nLibPenType;
}

CDrawObj& CLine::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CLine & CLine::operator =(const CLine & rhs)
{
	CDrawObj::operator=(rhs);
	this->m_dEndFilletLength = rhs.m_dEndFilletLength;
	this->m_dEndPtX = rhs.m_dEndPtX;
	this->m_dEndPtY = rhs.m_dEndPtY;
	this->m_dStartFilletLength = rhs.m_dStartFilletLength;
	this->m_dStartPtX = rhs.m_dStartPtX;
	this->m_dStartPtY = rhs.m_dStartPtY;
	this->m_nEndFilletExist = rhs.m_nEndFilletExist;
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	this->m_nLibPenType = rhs.m_nLibPenType;
	this->m_nLibTurretNo = rhs.m_nLibTurretNo;
	this->m_nStartFilletExist = rhs.m_nStartFilletExist;
	return *this;
}

BOOL CLine::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLine::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CLine::clone()
{
	return new CLine(*this);
}
// const int CLine::m_nVersion = 1;