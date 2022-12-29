#pragma once
#include <iostream>
using namespace std;

class CNetListElectricConstraints
{
public:
	int m_nTargetImpedance, m_nOperatingFrequency, m_nDiffPairNetIndex;
	double m_dMininumDelay, m_dMaximumDelay, m_dMaximumCrosstalk, m_dSignalDelay, m_dMinimumFrequency, m_dMaximumFrequency, m_dEyeMaskHeight, m_dEyeMaskWidthPercent, m_dEyeMaskMiddleWidthPercent
		, m_dVoltage, m_dImpedanceTolerance, m_dMaxCrosstalkJitter, m_dDiffPairSkew, m_dDifferentialImpedance, m_dCommonImpedance, m_dMaxFECrosstalk, m_dDiffImpedanceTolerance;

	CNetListElectricConstraints();
	CNetListElectricConstraints(const CNetListElectricConstraints& src);
	virtual ~CNetListElectricConstraints();
	void vSetCNetListElectricConstraints(int nTargetImpedance, double dMininumDelay, double dMaximumDelay, double dMaximumCrosstalk, double dSignalDelay, int nOperatingFrequency,
		double dMinimumFrequency, double dMaximumFrequency, double dEyeMaskHeight, double dEyeMaskWidthPercent, double dEyeMaskMiddleWidthPercent, double dVoltage,
		int nDiffPairNetIndex, double dImpedanceTolerance, double dMaxCrosstalkJitter, double dDiffPairSkew, double dDifferentialImpedance, double dCommonImpedance,
		double dMaxFECrosstalk, double dDiffImpedanceTolerance);
	virtual CNetListElectricConstraints & operator =(const CNetListElectricConstraints & rhs);
	virtual BOOL operator==(const CNetListElectricConstraints & rhs);
	BOOL operator!=(const CNetListElectricConstraints & rhs);
	virtual CNetListElectricConstraints* clone();
//	virtual CNetListElectricConstraints* clone() const { return new CNetListElectricConstraints(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};