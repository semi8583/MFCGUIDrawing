#include "stdafx.h"
#include "NetElectricConstraints.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetElectricConstraints::CNetElectricConstraints()
{
	cout << "생성자 CNetElectricConstraints() 호출" << endl;
}
CNetElectricConstraints::CNetElectricConstraints(const CNetElectricConstraints& src)
{
	*this = src;
}
CNetElectricConstraints::~CNetElectricConstraints()
{
	cout << "소멸자 ~CNetElectricConstraints() 호출" << endl;
}
void CNetElectricConstraints::vSetCNetElectricConstraints(double dMaximumCrosstalkJitter, double dMaximumCrosstalk, double dMaximumFECrosstalk, double dOperatingFrequency, double dDifferentialPairNetSkew,
	double dEyeMaskHeight, double dEyeMaskWidthPercent, double dEyeMaskMiddleWidthPercent)
{
	this->m_dMaximumCrosstalkJitter = dMaximumCrosstalkJitter;
	this->m_dMaximumCrosstalk = dMaximumCrosstalk;
	this->m_dMaximumFECrosstalk = dMaximumFECrosstalk;
	this->m_dOperatingFrequency = dOperatingFrequency;
	this->m_dDifferentialPairNetSkew = dDifferentialPairNetSkew;
	this->m_dEyeMaskHeight = dEyeMaskHeight;
	this->m_dEyeMaskWidthPercent = dEyeMaskWidthPercent;
	this->m_dEyeMaskMiddleWidthPercent = dEyeMaskMiddleWidthPercent;
}
CNetElectricConstraints& CNetElectricConstraints::operator =(const CNetElectricConstraints& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_dMaximumCrosstalkJitter = rhs.m_dMaximumCrosstalkJitter;
	this->m_dMaximumCrosstalk = rhs.m_dMaximumCrosstalk;
	this->m_dMaximumFECrosstalk = rhs.m_dMaximumFECrosstalk;
	this->m_dOperatingFrequency = rhs.m_dOperatingFrequency;
	this->m_dDifferentialPairNetSkew = rhs.m_dDifferentialPairNetSkew;
	this->m_dEyeMaskHeight = rhs.m_dEyeMaskHeight;
	this->m_dEyeMaskWidthPercent = rhs.m_dEyeMaskWidthPercent;
	this->m_dEyeMaskMiddleWidthPercent = rhs.m_dEyeMaskMiddleWidthPercent;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetElectricConstraints::operator==(const CNetElectricConstraints & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetElectricConstraints::operator!=(const CNetElectricConstraints& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetElectricConstraints* CNetElectricConstraints::clone()
{
	return new CNetElectricConstraints(*this);

}
// const int CNetElectricConstraints::m_nVersion = 1;