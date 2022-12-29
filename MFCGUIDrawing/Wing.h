#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CWing
{
public:
	double m_dWingAngle, m_dWingDistance;
	int m_nWingCount1, m_nWingCount2, m_nWingCount3, m_nWingCount4;
public:
	CWing();
	CWing(const CWing& src);
	virtual ~CWing();
	void vSetCWing(double WingAngle, double WingDistance, int WingCount, int WingCount1, int WingCount2, int WingCount3, int WingCount4);
	virtual CWing & operator =(const CWing & rhs);
	virtual BOOL operator==(const CWing & rhs);
	BOOL operator!=(const CWing & rhs);
	virtual CWing* clone();
//	virtual CWing* clone() const { return new CWing(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};