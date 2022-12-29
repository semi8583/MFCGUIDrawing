#pragma once
#include <iostream>
#include "stdafx.h"
#include "PenType.h"
using namespace std;

class CLibPenType
{
public:
	CPenType m_PenType;
public:
	CLibPenType();
	CLibPenType(const CLibPenType& src);
	virtual ~CLibPenType();
	void vSetCLibPenType(CPenType PenType);
	virtual CLibPenType & operator =(const CLibPenType & rhs);
	virtual BOOL operator==(const CLibPenType & rhs);
	BOOL operator!=(const CLibPenType & rhs);
	virtual CLibPenType* clone();
//	virtual CLibPenType* clone() const { return new CLibPenType(*this); };
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
