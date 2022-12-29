#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CDrawingArea
{
public:
	double m_dLowLeftMinX, m_dLowLeftMaxY, m_dUpperRightX, m_dUpperRightY;
public:
	CDrawingArea();
	CDrawingArea(const CDrawingArea& src);
	virtual ~CDrawingArea();
	void vSetCDrawingArea(double dLowLeftMinX, double dLowLeftMaxY,
		double dUpperRightX, double dUpperRightY);
	virtual CDrawingArea & operator =(const CDrawingArea & rhs);
	virtual BOOL operator==(const CDrawingArea & rhs);
	BOOL operator!=(const CDrawingArea & rhs);
	virtual CDrawingArea* clone();
	//virtual CDrawingArea* clone() const { return new CDrawingArea(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

