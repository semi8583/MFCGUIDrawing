#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CLibTextText
{
public:
	int m_nLibTextNo, m_nEcadFontID;
	string m_sFontName, m_sFontType;
	double m_dTextHeight, m_dTextWidth, m_dTextSpace, m_dTextLineSpace, m_dTextThickness;
public:
	CLibTextText();
	CLibTextText(const CLibTextText& src);
	virtual ~CLibTextText();
	void vSetCLibTextText(int nLibTextNo, string sFontName, string sFontType, double dTextHeight, double dTextWidth, double dTextSpace
		, double dTextLineSpace, double dTextThickness, int nECADFontID);
	virtual CLibTextText & operator =(const CLibTextText & rhs);
	virtual BOOL operator==(const CLibTextText & rhs);
	BOOL operator!=(const CLibTextText & rhs);
	virtual CLibTextText* clone();
//	virtual CLibTextText* clone() const { return new CLibTextText(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CLibTextTextArray : public CArray< CLibTextText *, CLibTextText * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CLibTextTextArray();
	CLibTextTextArray(const CLibTextTextArray& src);
	virtual ~CLibTextTextArray();

	virtual CLibTextTextArray& operator =(const CLibTextTextArray& rhs);
	virtual bool operator==(const CLibTextTextArray& rhs) const;
	bool operator!=(const CLibTextTextArray& rhs) const;
	virtual CLibTextTextArray* clone();
	virtual CLibTextTextArray * clone() const { return new CLibTextTextArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
