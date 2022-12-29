#include "stdafx.h"
#include "RefText.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRefText::CRefText()
{
	cout << "생성자 CRefText() 호출" << endl;
}
CRefText::CRefText(const CRefText& src)
{
	*this = src;
}
CRefText::~CRefText()
{
	cout << "소멸자 ~CRefText() 호출" << endl;
}
void CRefText::setReftext(int nLibTextNo, string sString, double dAngle, string sMirror, double dPtX, double dPtY, int nJustification)
{
	this->m_nLibTextNo = nLibTextNo;
	this->m_sString = sString;
	this->m_dAngle = dAngle;
	this->m_sMirror = sMirror;
	this->m_dPtX = dPtX;
	this->m_dPtY = dPtY;
	this->m_nJustification = nJustification;
}
CRefText& CRefText::operator =(const CRefText& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nLibTextNo = rhs.m_nLibTextNo;
	this->m_sString = rhs.m_sString;
	this->m_dAngle = rhs.m_dAngle;
	this->m_sMirror = rhs.m_sMirror;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nJustification = rhs.m_nJustification;
	// Add code to serialize member variable
	return *this;
}


BOOL CRefText::operator==(const CRefText & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRefText::operator!=(const CRefText& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRefText* CRefText::clone()
{
	return new CRefText(*this);

}
// const int CRefText::m_nVersion = 1;