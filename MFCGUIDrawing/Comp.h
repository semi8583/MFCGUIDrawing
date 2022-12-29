#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;
class CComp :public CDrawObj
{
public:
	string m_sPlaceLayer, m_sReferenceName, m_sPinNumber, m_sTeardropExist;
	double m_dPtX, m_dPtY;
public:
	CComp();
	CComp(const CComp& src);
	virtual ~CComp();
	void vSetCompPlaceLayer(string sPlaceLayer);
	void vSetCompReferenceName(string sReferenceName);
	void vSetCompPinNumber(string sPinNumber);
	void vSetCompTeardropExist(string sTeardropExist);
	void vSetCompPtX(double dPtX);
	void vSetCompPtY(double dPtY);
	string sGetCompPlaceLayer();
	string sSetCompReferenceName();
	string sSetCompPinNumber();
	string sSetCompTeardropExist();
	double dSetCompPtX();
	double vSetCompPtY();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CComp& operator =(const CComp& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual CComp* clone() const { return new CComp(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};