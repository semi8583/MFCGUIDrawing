#pragma once
#include <iostream>
#include "stdafx.h"
#include "Wing.h"
using namespace std;

class CTur
{
public:
	int m_nLibTurretNo;
	string m_sTurretType;
	double m_dInnerSize, m_dOuterSize;
	CWing m_Wing;
public:
	CTur();
	CTur(const CTur& src);
	virtual ~CTur();
	void vSetCTur(int nLibTurretNo, string sTurretType, double dInnerSize, double dOuterSize, CWing Wing);
	virtual CTur & operator =(const CTur & rhs);
	virtual BOOL operator==(const CTur & rhs);
	BOOL operator!=(const CTur & rhs);
	virtual CTur* clone();
//	virtual CTur clone() const { return CTur(*this); };
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
class  CTurArray : public CArray< CTur*, CTur* >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CTurArray();
	CTurArray(const CTurArray& src);
	virtual ~CTurArray();

	virtual CTurArray& operator =(const CTurArray& rhs);
	virtual bool operator==(const CTurArray& rhs) const;
	bool operator!=(const CTurArray& rhs) const;
	virtual CTurArray* clone();
	virtual CTurArray * clone() const { return new CTurArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};