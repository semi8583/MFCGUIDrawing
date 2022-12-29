#pragma once
#include <iostream>
using namespace std;

class CPadColor
{
public:
	int m_nR, m_nG, m_nB;
public:
	CPadColor();
	CPadColor(const CPadColor& src);
	~CPadColor();
	void vSetPadColor(int nR, int nG, int nB);
	virtual CPadColor & operator =(const CPadColor & rhs);
	virtual BOOL operator==(const CPadColor & rhs);
	BOOL operator!=(const CPadColor & rhs);
	virtual CPadColor* clone();
//	virtual CPadColor* clone() const { return new CPadColor(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
