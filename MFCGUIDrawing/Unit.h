#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CUnit
{
public:
	string m_sUnit;
public:
	CUnit();
	CUnit(const CUnit& src);
	virtual ~CUnit();
	void vSetCUnit(string sUnit);

	virtual CUnit & operator =(const CUnit & rhs);
	virtual BOOL operator==(const CUnit & rhs);
	BOOL operator!=(const CUnit & rhs);
	virtual CUnit* clone();
//	virtual CUnit* clone() const { return new CUnit(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};