
#include "stdafx.h"
#include "Color.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CColor::CColor()
{
	cout << "생성자 CColor() 호출" << endl;
}
CColor::CColor(const CColor& src)
{
	*this = src;
}
CColor::~CColor()
{
	cout << "소멸자 ~CColor() 호출" << endl;
}
void CColor::vSetColor(int nR, int nG, int nB)
{
	m_nR = nR;
	m_nG = nG;
	m_nB = nB;
}
CColor& CColor::operator =(const CColor& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nB = rhs.m_nB;
	this->m_nG = rhs.m_nG;
	this->m_nR = rhs.m_nR;
	// Add code to serialize member variable
	return *this;
}


BOOL CColor::operator==(const CColor & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CColor::operator!=(const CColor& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CColor* CColor::clone()
{
	return new CColor(*this);

}
//const int CColor::m_nVersion = 1;