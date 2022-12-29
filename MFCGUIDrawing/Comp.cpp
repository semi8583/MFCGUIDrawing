#include "stdafx.h"
#include "Comp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CComp::CComp()
{
	cout << "생성자 CComp() 호출" << endl;
}
CComp::CComp(const CComp& src)
{
	*this = src;
}
CComp:: ~CComp()
{
	cout << "소멸자 ~CComp() 호출" << endl;
}
void CComp::vSetCompPlaceLayer(string sPlaceLayer)
{
	m_sPlaceLayer = sPlaceLayer;
}
void CComp::vSetCompReferenceName(string sReferenceName)
{
	m_sReferenceName = sReferenceName;
}
void CComp::vSetCompPinNumber(string sPinNumber)
{
	m_sPinNumber = sPinNumber;
}
void CComp::vSetCompTeardropExist(string sTeardropExist)
{
	m_sTeardropExist = sTeardropExist;
}
void CComp::vSetCompPtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CComp::vSetCompPtY(double dPtY)
{
	m_dPtY = dPtY;
}
//
string CComp::sGetCompPlaceLayer()
{
	return m_sPlaceLayer;
}
string CComp::sSetCompReferenceName()
{
	return m_sReferenceName;
}
string CComp::sSetCompPinNumber()
{
	return m_sPinNumber;
}
string CComp::sSetCompTeardropExist()
{
	return m_sTeardropExist;
}
double CComp::dSetCompPtX()
{
	return m_dPtX;
}
double CComp::vSetCompPtY()
{
	return m_dPtY;
}
CDrawObj& CComp::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;

	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}

CComp& CComp::operator =(const CComp& rhs)
{
	if (this == &rhs)
		return *this;

	CDrawObj::operator=(rhs);
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_sPinNumber = rhs.m_sPinNumber;
	this->m_sPlaceLayer = rhs.m_sPlaceLayer;
	this->m_sReferenceName = rhs.m_sReferenceName;
	this->m_sTeardropExist = rhs.m_sTeardropExist;
	// Add code to serialize member variable
	return *this;
}


BOOL CComp::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CComp::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CComp::clone()
{
	return new CComp(*this);
}
//const int CComp::m_nVersion = 1;