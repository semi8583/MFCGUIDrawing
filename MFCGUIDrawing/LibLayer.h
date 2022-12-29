#pragma once
#include <iostream>
#include "stdafx.h"
#include "Lay.h"


using namespace std;

class CLibLayer
{
public:
	CLayArray m_aLay;
public:
	CLibLayer();
	CLibLayer(const CLibLayer& src);
	virtual ~CLibLayer();
	void vSetCLibLayer(CLayArray aLay);
	virtual CLibLayer & operator =(const CLibLayer & rhs);
	virtual BOOL operator==(const CLibLayer & rhs);
	BOOL operator!=(const CLibLayer & rhs);
	virtual CLibLayer* clone();
//	virtual CLibLayer* clone() const { return new CLibLayer(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

