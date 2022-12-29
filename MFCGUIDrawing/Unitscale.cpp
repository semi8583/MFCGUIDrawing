#include "stdafx.h"
#include "Unitscale.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CUnitscale::CUnitscale()
{
	cout << "생성자 CUnitscale() 호출" << endl;
}
CUnitscale::CUnitscale(const CUnitscale& src)
{
	*this = src;
}
CUnitscale::~CUnitscale()
{
	cout << "소멸자 ~CUnitscale() 호출" << endl;
}
void CUnitscale::vSetCUnitscale(int nUnitScale)
{
	m_nUnitScale = nUnitScale;
}
CUnitscale& CUnitscale::operator =(const CUnitscale& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nUnitScale = rhs.m_nUnitScale;
	// Add code to serialize member variable
	return *this;
}


BOOL CUnitscale::operator==(const CUnitscale & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CUnitscale::operator!=(const CUnitscale& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CUnitscale* CUnitscale::clone()
{
	return new CUnitscale(*this);

}
// const int CUnitscale::m_nVersion = 1;