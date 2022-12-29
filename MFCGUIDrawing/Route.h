#pragma once
#include <iostream>
#include "RNET.h"
using namespace std;

class CRoute
{
public:
	CRNETArray m_aRnet;
public:
	CRoute();
	CRoute(const CRoute& src);
	virtual ~CRoute();
	void vSetRoute(CRNETArray aRnet);
	virtual CRoute & operator =(const CRoute & rhs);
	virtual BOOL operator==(const CRoute & rhs);
	BOOL operator!=(const CRoute & rhs);
	virtual CRoute* clone();
//	virtual CRoute* clone() const { return new CRoute(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};