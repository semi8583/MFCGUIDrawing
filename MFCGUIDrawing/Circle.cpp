
#include "stdafx.h"
#include "Circle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CCircle::CCircle()
{
	cout << "������ CCircle() ȣ��" << endl;
}
CCircle::CCircle(const CCircle& src)
{
	*this = src;
}
CCircle:: ~CCircle()
{
	cout << "�Ҹ��� ~CCircle() ȣ��" << endl;
}
void CCircle::vSetCircleLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CCircle::vSetCircleLibTurretNo(int nLibTurretNo)
{
	m_nLibTurretNo = nLibTurretNo;
}
void CCircle::vSetCircleDiameter(double dDiameter)
{
	m_dDiameter = dDiameter;
}
void CCircle::vSetCirclePtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CCircle::vSetCirclePtY(double dPtY)
{
	m_dPtY = dPtY;
}
int CCircle::nGetCircleLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
int CCircle::nGetCircleLibTurretNo()
{
	return m_nLibTurretNo;
}
double CCircle::dGetCircleDiameter()
{
	return m_dDiameter;
}
double CCircle::dGetCirclePtX()
{
	return m_dPtX;
}
double CCircle::dGetCirclePtY()
{
	return m_dPtY;
}
CDrawObj& CCircle::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;

	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CCircle& CCircle::operator =(const CCircle& rhs)
{
	if (this == &rhs)
		return *this;

	CDrawObj::operator=(rhs);
	this->m_dDiameter = rhs.m_dDiameter;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	this->m_nLibTurretNo = rhs.m_nLibTurretNo;
	// Add code to serialize member variable
	return *this;
}


BOOL CCircle::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CCircle::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CCircle::clone()
{
	return new CCircle(*this);
}
//const int CCircle::m_nVersion = 1;