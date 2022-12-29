#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;
class CPadStack :public CDrawObj
{
public:
	int m_nLibArtworkLayNo, m_nLibPadstackNo;
	double m_dAngle, m_dPtX, m_dPtY;
	string m_sTeardropExist;
public:
	CPadStack();
	CPadStack(const CPadStack& src);
	virtual ~CPadStack();
	void vSetPadStackLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetPadStackLibPadstackNo(int nLibPadstackNo);
	void vSetPadStackAngle(double dAngle);
	void vSetPadStackTeardropExist(string sTeardropExist);
	void vSetPadStackPtX(double dPtX);
	void vSetPadStackPtY(double dPtY);
	int nGetPadStackLibArtworkLayNo();
	int nGetPadStackLibPadstackNo();
	double dGetPadStackAngle();
	string sGetPadStackTeardropExist();
	double dGetPadStackPtX();
	double dGetPadStackPtY();

	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CPadStack & operator =(const CPadStack & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CPadStack* clone() const { return new CPadStack(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

