#pragma once
#include <iostream>
#include "DrawObj.h"
using namespace std;

class CPt : public CDrawObj
{
public:
	int m_nLibArtworkLayNum, m_nLibTurretNum;
	double m_dPtX, m_dPtY;
public:
	CPt();
	CPt(const CPt& src);
	virtual ~CPt();
	void vSetPtLibArtworkLayNum(int nLibArtworkLayNum);
	void vSetPtLibTurretNum(int nLibTurretNum);
	void vSetPtPtX(double dPtX);
	void vSetPtPtY(double dPtY);
	int nGetPtLibArtworkLayNum();
	int nGetPtLibTurretNum();
	double dGetPtPtX();
	double dGetPtPtY();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CPt& operator =(const CPt& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CPt* clone() const { return new CPt(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
