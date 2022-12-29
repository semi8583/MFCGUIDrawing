#include "stdafx.h"
#include "NetListElectricConstraints.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetListElectricConstraints::CNetListElectricConstraints()
{
	cout << "생성자 CNetListElectricConstraints() 호출" << endl;
}
CNetListElectricConstraints::CNetListElectricConstraints(const CNetListElectricConstraints& src)
{
	*this = src;
}
CNetListElectricConstraints::~CNetListElectricConstraints()
{
	cout << "소멸자 ~CNetListElectricConstraints() 호출" << endl;
}
void CNetListElectricConstraints::vSetCNetListElectricConstraints(int nTargetImpedance, double dMininumDelay, double dMaximumDelay, double dMaximumCrosstalk, double dSignalDelay, int nOperatingFrequency,
	double dMinimumFrequency, double dMaximumFrequency, double dEyeMaskHeight, double dEyeMaskWidthPercent, double dEyeMaskMiddleWidthPercent, double dVoltage,
	int nDiffPairNetIndex, double dImpedanceTolerance, double dMaxCrosstalkJitter, double dDiffPairSkew, double dDifferentialImpedance, double dCommonImpedance,
	double dMaxFECrosstalk, double dDiffImpedanceTolerance)
{
	this->m_nTargetImpedance = nTargetImpedance;
	this->m_dMininumDelay = dMininumDelay;
	this->m_dMaximumDelay = dMaximumDelay;
	this->m_dMaximumCrosstalk = dMaximumCrosstalk;
	this->m_dSignalDelay = dSignalDelay;
	this->m_nOperatingFrequency = nOperatingFrequency;
	this->m_dMinimumFrequency = dMinimumFrequency;
	this->m_dMaximumFrequency = dMaximumFrequency;
	this->m_dEyeMaskHeight = dEyeMaskHeight;
	this->m_dEyeMaskWidthPercent = dEyeMaskWidthPercent;
	this->m_dEyeMaskMiddleWidthPercent = dEyeMaskMiddleWidthPercent;
	this->m_dVoltage = dVoltage;
	this->m_nDiffPairNetIndex = nDiffPairNetIndex;
	this->m_dImpedanceTolerance = dImpedanceTolerance;
	this->m_dMaxCrosstalkJitter = dMaxCrosstalkJitter;
	this->m_dDiffPairSkew = dDiffPairSkew;
	this->m_dDifferentialImpedance = dDifferentialImpedance;
	this->m_dCommonImpedance = dCommonImpedance;
	this->m_dMaxFECrosstalk = dMaxFECrosstalk;
	this->m_dDiffImpedanceTolerance = dDiffImpedanceTolerance;
}
CNetListElectricConstraints& CNetListElectricConstraints::operator =(const CNetListElectricConstraints& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nTargetImpedance = rhs.m_nTargetImpedance;
	this->m_dMininumDelay = rhs.m_dMininumDelay;
	this->m_dMaximumDelay = rhs.m_dMaximumDelay;
	this->m_dMaximumCrosstalk = rhs.m_dMaximumCrosstalk;
	this->m_dSignalDelay = rhs.m_dSignalDelay;
	this->m_nOperatingFrequency = rhs.m_nOperatingFrequency;
	this->m_dMinimumFrequency = rhs.m_dMinimumFrequency;
	this->m_dMaximumFrequency = rhs.m_dMaximumFrequency;
	this->m_dEyeMaskHeight = rhs.m_dEyeMaskHeight;
	this->m_dEyeMaskWidthPercent = rhs.m_dEyeMaskWidthPercent;
	this->m_dEyeMaskMiddleWidthPercent = rhs.m_dEyeMaskMiddleWidthPercent;
	this->m_dVoltage = rhs.m_dVoltage;
	this->m_nDiffPairNetIndex = rhs.m_nDiffPairNetIndex;
	this->m_dImpedanceTolerance = rhs.m_dImpedanceTolerance;
	this->m_dMaxCrosstalkJitter = rhs.m_dMaxCrosstalkJitter;
	this->m_dDiffPairSkew = rhs.m_dDiffPairSkew;
	this->m_dDifferentialImpedance = rhs.m_dDifferentialImpedance;
	this->m_dCommonImpedance = rhs.m_dCommonImpedance;
	this->m_dMaxFECrosstalk = rhs.m_dMaxFECrosstalk;
	this->m_dDiffImpedanceTolerance = rhs.m_dDiffImpedanceTolerance;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetListElectricConstraints::operator==(const CNetListElectricConstraints & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetListElectricConstraints::operator!=(const CNetListElectricConstraints& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetListElectricConstraints* CNetListElectricConstraints::clone()
{
	return new CNetListElectricConstraints(*this);

}
// const int CNetListElectricConstraints::m_nVersion = 1;