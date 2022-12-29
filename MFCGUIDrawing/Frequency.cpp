#include "stdafx.h"
#include "Frequency.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CFrequency::CFrequency()
{
	cout << "생성자 CFrequency() 호출" << endl;
}
CFrequency::CFrequency(const CFrequency& src)
{
	*this = src;
}
CFrequency::~CFrequency()
{
	cout << "소멸자 ~CFrequency() 호출" << endl;
}
void CFrequency::vSetCFrequency(double dFrequency, double dElectricProperty1, double dElectricProperty2)
{
	m_dFrequency = dFrequency;
	m_dElectricProperty1 = dElectricProperty1;
	m_dElectricProperty2 = dElectricProperty2;
}
CFrequency& CFrequency::operator =(const CFrequency& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_dElectricProperty1 = rhs.m_dElectricProperty1;
	this->m_dElectricProperty2 = rhs.m_dElectricProperty2;
	this->m_dFrequency = rhs.m_dFrequency;
	// Add code to serialize member variable
	return *this;
}


BOOL CFrequency::operator==(const CFrequency & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CFrequency::operator!=(const CFrequency& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CFrequency* CFrequency::clone()
{
	return new CFrequency(*this);

}
//const int CFrequency::m_nVersion = 1;