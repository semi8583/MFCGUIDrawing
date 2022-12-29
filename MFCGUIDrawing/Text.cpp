#include "stdafx.h"
#include "Text.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CText::CText()
{
	cout << "생성자 CText() 호출" << endl;
}
CText::CText(const CText& src)
{
	*this = src;
}
CText:: ~CText()
{
	cout << "소멸자 ~CText() 호출" << endl;
}
void CText::vSetTextArtworkLayNo(int nArtworkLayNo)
{
	m_nArtworkLayNo = nArtworkLayNo;
}
void CText::vSetTextLibFontNo(int nLibFontNo)
{
	m_nLibFontNo = nLibFontNo;
}
void CText::vSetTextValue(string sValue)
{
	m_sValue = sValue;
}
void CText::vSetTextAngle(double dAngle)
{
	m_dAngle = dAngle;
}
void CText::vSetTextMirror(string sMirror)
{
	m_sMirror = sMirror;
}
void CText::vSetTextJustification(int nJustification)
{
	m_nJustification = nJustification;
}
void CText::vSetTextPtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CText::vSetTextPtY(double dPtY)
{
	m_dPtY = dPtY;
}
int CText::nGetTextArtworkLayNo()
{
	return m_nArtworkLayNo;
}
int CText::nGetTextLibFontNo()
{
	return m_nLibFontNo;
}
string CText::sGetTextValue()
{
	return m_sValue;
}
double CText::dGetTextAngle()
{
	return m_dAngle;
}
string CText::sGetTextMirror()
{
	return m_sMirror;
}
int CText::nGetTextJustification()
{
	return m_nJustification;
}
double CText::dGetTextPtX()
{
	return m_dPtX;
}
double CText::dGetTextPtY()
{
	return m_dPtY;
}
CDrawObj& CText::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);

	// Add code to serialize member variable
	return *this;
}
CText & CText::operator =(const CText & rhs)
{
	CDrawObj::operator=(rhs);
	this->m_dAngle = rhs.m_dAngle;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nArtworkLayNo = rhs.m_nArtworkLayNo;
	this->m_nJustification = rhs.m_nJustification;
	this->m_nLibFontNo = rhs.m_nLibFontNo;
	this->m_sMirror = rhs.m_sMirror;
	this->m_sValue = rhs.m_sValue;
	return *this;
}

BOOL CText::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CText::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CText::clone()
{
	return new CText(*this);
}
// const int CText::m_nVersion = 1;