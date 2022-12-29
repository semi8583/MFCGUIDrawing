#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;
class CArc : public CDrawObj
{
public:
	int m_nLibArtworkLayNo, m_nLibTurretNo, m_nLibPenType;
	double m_dRadius, m_dStartAngle, m_dEndAngle, m_dStartPtX, m_dStartPtY, m_dEndPtX, m_dEndPtY, m_dCenterPtX, m_dCenterPtY;
	string m_sDirection;
public:
	CArc();
	CArc(const CArc& src);
	virtual ~CArc();
	void vSetArcLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetArcLibTurretNo(int nLibTurretNo);
	void vSetArcRadius(double dRadius);
	void vSetArcStartAngle(double dStartAngle);
	void vSetArcEndAngle(double dEndAngle);
	void vSetArcDirection(string sDirection);
	void vSetArcStartPtX(double dStartPtX);
	void vSetArcStartPtY(double dStartPtY);
	void vSetArcEndPtX(double dEndPtX);
	void vSetArcEndPtY(double dEndPtY);
	void vSetArcCenterPtX(double dCenterPtX);
	void vSetArcCenterPtY(double dCenterPtY);
	void vSetArcLibPenType(int nLibPenType);
	int nGetArcLibArtworkLayNo();
	int nGetArcLibTurretNo();
	double dGetArcRadius();
	double dGetArcStartAngle();
	double dGetArcEndAngle();
	string sGetArcDirection();
	double dGetArcStartPtX();
	double dGetArcStartPtY();
	double dGetArcEndPtX();
	double dGetArcEndPtY();
	double dGetArcCenterPtX();
	double dGetArcCenterPtY();
	int nGetArcLibPenType();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CArc& operator =(const CArc& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};
