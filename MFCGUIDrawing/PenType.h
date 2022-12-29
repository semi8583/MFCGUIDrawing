#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CPenType
{
public:
	int m_nLibPenType = 0, m_nPenType = 0, m_nTurretNo = 0;
	double m_dLineLength = 0, m_dDotLineLength = 0, m_dLineSpace = 0;
public:
	CPenType();
	CPenType(const CPenType& src);
	virtual ~CPenType();
	void vSetLibPenType(int nLibPenType, int nPenType, int nTurretNo, double dLineLength, double dDotLineLength, double dLineSpace);
	virtual CPenType & operator =(const CPenType & rhs);
	virtual BOOL operator==(const CPenType & rhs);
	BOOL operator!=(const CPenType & rhs);
	virtual CPenType* clone();
//	virtual CPenType* clone() const { return new CPenType(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

