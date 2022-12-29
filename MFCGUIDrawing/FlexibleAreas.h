#pragma once
#include <iostream>
#include "stdafx.h"
#include "FlexibleArea.h"
using namespace std;

class CFlexibleAreas
{
public:
	CFlexibleArea m_FlexibleArea;
public:
	CFlexibleAreas();
	CFlexibleAreas(const CFlexibleAreas& src);
	virtual ~CFlexibleAreas();
	void vSetCFlexibleAreas(CFlexibleArea FlexibleArea);
	virtual CFlexibleAreas & operator =(const CFlexibleAreas & rhs);
	virtual BOOL operator==(const CFlexibleAreas & rhs);
	BOOL operator!=(const CFlexibleAreas & rhs);
	virtual CFlexibleAreas* clone();
//	virtual CFlexibleAreas* clone() const { return new CFlexibleAreas(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
