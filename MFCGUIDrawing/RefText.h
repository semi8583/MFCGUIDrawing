#pragma once
#include <iostream>
using namespace std;

class CRefText
{
public:
	int m_nLibTextNo, m_nJustification;
	string m_sString, m_sMirror;
	double m_dAngle, m_dPtX, m_dPtY;
public:
	CRefText();
	CRefText(const CRefText& src);
	virtual ~CRefText();
	void setReftext(int nLibTextNo, string sString, double dAngle, string sMirror, double dPtX, double dPtY, int nJustification);
	virtual CRefText & operator =(const CRefText & rhs);
	virtual BOOL operator==(const CRefText & rhs);
	BOOL operator!=(const CRefText & rhs);
	virtual CRefText* clone();
//	virtual CRefText* clone() const { return new CRefText(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};