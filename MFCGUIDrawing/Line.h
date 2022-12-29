#pragma once
#include <iostream>
#include "DrawObj.h"
using namespace std;
class CLine :public CDrawObj {
public:
	int m_nLibArtworkLayNo, m_nLibTurretNo, m_nStartFilletExist, m_nEndFilletExist, m_nLibPenType;
	double m_dStartPtX, m_dStartPtY, m_dEndPtX, m_dEndPtY, m_dStartFilletLength, m_dEndFilletLength;
public:
	CLine();
	CLine(const CLine& src);
	virtual ~CLine();
	void vSetLineLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetLineLibTurretNo(int nLibTurretNo);
	void vSetLineStartPtX(double dStartPtX);
	void vSetLineStartPtY(double dStartPtY);
	void vSetLineEndPtX(double dEndPtX);
	void vSetLineEndPtY(double dEndPtY);
	void vSetLineStartFilletExist(int nStartFilletExist);
	void vSetLineStartFilletLength(double dStartFilletLength);
	void vSetLineEndFilletExist(int nEndFilletExist);
	void vSetLineEndFilletLength(double dEndFilletLength);
	void vSetLineLibPenType(int nLibPenType);
	int nGetLineLibArtworkLayNo();
	int nGetLineLibTurretNo();
	double dGetLineStartPtX();
	double dGetLineStartPtY();
	double dGetLineEndPtX();
	double dGetLineEndPtY();
	int nGetLineStartFilletExist();
	double dGetLineStartFilletLength();
	int nGetLineEndFilletExist();
	double  dGetLineEndFilletLength();
	int nGetLineLibPenType();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CLine & operator =(const CLine & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

