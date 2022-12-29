#pragma once
#include <iostream>
using namespace std;

class CPinNumber
{
public:
	int m_nPinNumber;
	CPinNumber();
	CPinNumber(const CPinNumber& src);
	virtual ~CPinNumber();
	void vSetCPinNumber(int nPinNumber);
	virtual CPinNumber & operator =(const CPinNumber & rhs);
	virtual BOOL operator==(const CPinNumber & rhs);
	BOOL operator!=(const CPinNumber & rhs);
	virtual CPinNumber* clone();
//	virtual CPinNumber* clone() const { return new CPinNumber(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};