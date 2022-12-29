#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CFlexibleArea
{
public:
	double m_dMinX, m_dMinY, m_dMaxX, m_dMaxY, m_dTopCoverlayThickness, m_dBottomCoverlayThickness;
	string m_sTopLayerName, m_sBottomLayerName, m_sCoverlayMaterialName;
public:
	CFlexibleArea();
	CFlexibleArea(const CFlexibleArea& src);
	virtual ~CFlexibleArea();
	void vSetCFlexibleArea(double dMinX, double dMinY, double dMaxX, double dMaxY, double  dTopLayerName, double dBottomLayerName,
		string sCoverlayMaterialName, double dTopCoverlayThickness, double dBottomCoverlayThickness);
	virtual CFlexibleArea & operator =(const CFlexibleArea & rhs);
	virtual BOOL operator==(const CFlexibleArea & rhs);
	BOOL operator!=(const CFlexibleArea & rhs);
	virtual CFlexibleArea* clone();
//	virtual CFlexibleArea* clone() const { return new CFlexibleArea(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};


