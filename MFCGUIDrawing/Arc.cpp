
#include "stdafx.h"
#include "Arc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CArc::CArc()
{
	cout << "생성자 CArc() 호출" << endl;
}
CArc::CArc(const CArc& src)
{
	*this = src;
}

CArc:: ~CArc()
{
	cout << "소멸자 ~CArc() 호출" << endl;
}
void CArc::vSetArcLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CArc::vSetArcLibTurretNo(int nLibTurretNo)
{
	m_nLibTurretNo = nLibTurretNo;
}
void CArc::vSetArcRadius(double dRadius)
{
	m_dRadius = dRadius;
}
void CArc::vSetArcStartAngle(double dStartAngle)
{
	m_dStartAngle = dStartAngle;
}
void CArc::vSetArcEndAngle(double dEndAngle)
{
	m_dEndAngle = dEndAngle;
}
void CArc::vSetArcDirection(string sDirection)
{
	m_sDirection = sDirection;
}
void CArc::vSetArcStartPtX(double dStartPtX)
{
	m_dStartPtX = dStartPtX;
}
void CArc::vSetArcStartPtY(double dStartPtY)
{
	m_dStartPtY = dStartPtY;
}
void CArc::vSetArcEndPtX(double dEndPtX)
{
	m_dEndPtX = dEndPtX;
}
void CArc::vSetArcEndPtY(double dEndPtY)
{
	m_dEndPtY = dEndPtY;
}
void CArc::vSetArcCenterPtX(double dCenterPtX)
{
	m_dCenterPtX = dCenterPtX;
}
void CArc::vSetArcCenterPtY(double dCenterPtY)
{
	m_dCenterPtY = dCenterPtY;
}
void CArc::vSetArcLibPenType(int nLibPenType)
{
	m_nLibPenType = nLibPenType;
}
int CArc::nGetArcLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
int CArc::nGetArcLibTurretNo()
{
	return m_nLibTurretNo;
}
double CArc::dGetArcRadius()
{
	return m_dRadius;
}
double CArc::dGetArcStartAngle()
{
	return m_dStartAngle;
}
double CArc::dGetArcEndAngle()
{
	return m_dEndAngle;
}
string CArc::sGetArcDirection()
{
	return m_sDirection;
}
double CArc::dGetArcStartPtX()
{
	return m_dStartPtX;
}
double CArc::dGetArcStartPtY()
{
	return m_dStartPtY;
}
double CArc::dGetArcEndPtX()
{
	return m_dEndPtX;
}
double CArc::dGetArcEndPtY()
{
	return m_dEndPtY;
}
double CArc::dGetArcCenterPtX()
{
	return m_dCenterPtX;
}
double CArc::dGetArcCenterPtY()
{
	return m_dCenterPtY;
}
int CArc::nGetArcLibPenType()
{
	return m_nLibPenType;
}
CDrawObj& CArc::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CArc& CArc::operator =(const CArc& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	this->m_nLibTurretNo = rhs.m_nLibTurretNo;
	this->m_nLibPenType = rhs.m_nLibPenType;
	this->m_dRadius = rhs.m_dRadius;
	this->m_dStartAngle = rhs.m_dStartAngle;
	this->m_dEndAngle = rhs.m_dEndAngle;
	this->m_dStartPtX = rhs.m_dStartPtX;
	this->m_dStartPtY = rhs.m_dStartPtY;
	this->m_dEndPtX = rhs.m_dEndPtX;
	this->m_dEndPtY = rhs.m_dEndPtY;
	this->m_dCenterPtX = rhs.m_dCenterPtX;
	this->m_dCenterPtY = rhs.m_dCenterPtY;
	this->m_sDirection = rhs.m_sDirection;
	// Add code to serialize member variable
	return *this;
}


BOOL CArc::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CArc::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CArc::clone()
{
	return new CArc(*this);
}
//const int CArc::m_nVersion = 1;