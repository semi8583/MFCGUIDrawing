#pragma once
#include <iostream>
#include "stdafx.h"
#include "Alu.h"
using namespace std;

class CLayerUnion
{
public:
	CAlu m_Alu;
public:
	CLayerUnion();
	CLayerUnion(const CLayerUnion& src);
	virtual ~CLayerUnion();
	void vSetCLayerUnion(CAlu Alu);
	virtual CLayerUnion & operator =(const CLayerUnion & rhs);
	virtual BOOL operator==(const CLayerUnion & rhs);
	BOOL operator!=(const CLayerUnion & rhs);
	virtual CLayerUnion* clone();
//	virtual CLayerUnion* clone() const { return new CLayerUnion(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

