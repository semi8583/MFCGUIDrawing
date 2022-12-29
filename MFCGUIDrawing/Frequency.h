#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CFrequency
{
public:
	double m_dFrequency, m_dElectricProperty1, m_dElectricProperty2;
public:
	CFrequency();
	CFrequency(const CFrequency& src);
	virtual ~CFrequency();
	void vSetCFrequency(double dFrequency, double dElectricProperty1, double dElectricProperty2);
	virtual CFrequency & operator =(const CFrequency & rhs);
	virtual BOOL operator==(const CFrequency & rhs);
	BOOL operator!=(const CFrequency & rhs);
	virtual CFrequency* clone();
//	virtual CFrequency* clone() const { return new CFrequency(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

