#pragma once
#include <iostream>
using namespace std;

class CGateNo
{
public:
	int m_nGateNo;
	CGateNo();
	CGateNo(const CGateNo& src);
	virtual ~CGateNo();
	void vSetGateNo(int nGateNo);
	virtual  CGateNo & operator =(const CGateNo & rhs);
	virtual  BOOL operator==(const CGateNo & rhs);
	BOOL operator!=(const CGateNo & rhs);
	virtual CGateNo* clone();
//	virtual CGateNo* clone() const { return new CGateNo(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};