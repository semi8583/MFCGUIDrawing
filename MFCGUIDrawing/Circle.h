#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;
class CCircle :public CDrawObj
{
public:
	int m_nLibArtworkLayNo, m_nLibTurretNo;
	double m_dDiameter, m_dPtX, m_dPtY;
public:
	CCircle();
	CCircle(const CCircle& src);
	virtual ~CCircle();
	void vSetCircleLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetCircleLibTurretNo(int nLibTurretNo);
	void vSetCircleDiameter(double dDiameter);
	void vSetCirclePtX(double dPtX);
	void vSetCirclePtY(double dPtY);
	int nGetCircleLibArtworkLayNo();
	int nGetCircleLibTurretNo();
	double dGetCircleDiameter();
	double dGetCirclePtX();
	double dGetCirclePtY();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CCircle & operator =(const CCircle & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();

	//virtual CCircle* clone() const { return new CCircle(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};