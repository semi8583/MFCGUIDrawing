#pragma once
#include <iostream>
using namespace std;

class CNetElectricConstraints
{
public:
	double m_dMaximumCrosstalkJitter, m_dMaximumCrosstalk, m_dMaximumFECrosstalk, m_dOperatingFrequency, m_dDifferentialPairNetSkew, m_dEyeMaskHeight, m_dEyeMaskWidthPercent, m_dEyeMaskMiddleWidthPercent;
	CNetElectricConstraints();
	CNetElectricConstraints(const CNetElectricConstraints& src);
	virtual ~CNetElectricConstraints();
	void vSetCNetElectricConstraints(double dMaximumCrosstalkJitter, double dMaximumCrosstalk, double dMaximumFECrosstalk, double dOperatingFrequency, double dDifferentialPairNetSkew,
		double dEyeMaskHeight, double dEyeMaskWidthPercent, double dEyeMaskMiddleWidthPercent);
	virtual CNetElectricConstraints & operator =(const CNetElectricConstraints & rhs);
	virtual BOOL operator==(const CNetElectricConstraints & rhs);
	BOOL operator!=(const CNetElectricConstraints & rhs);
	virtual CNetElectricConstraints* clone();
//	virtual CNetElectricConstraints* clone() const { return new CNetElectricConstraints(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};