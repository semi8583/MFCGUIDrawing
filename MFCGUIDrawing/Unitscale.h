#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CUnitscale
{
public:
	int m_nUnitScale;
public:
	CUnitscale();
	CUnitscale(const CUnitscale& src);
	virtual ~CUnitscale();
	void vSetCUnitscale(int nUnitScale);
	virtual CUnitscale & operator =(const CUnitscale & rhs);
	virtual BOOL operator==(const CUnitscale & rhs);
	BOOL operator!=(const CUnitscale & rhs);
	virtual CUnitscale* clone();
//	virtual CUnitscale* clone() const { return new CUnitscale(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};