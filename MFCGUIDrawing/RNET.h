#pragma once
#include <iostream>


#include "DrawObj.h"
#include "Color.h"
#include "PadColor.h"
using namespace std;

class CRNET
{
public:
	string m_sNetName;
	CDrawObjArray m_aDrawObj;
	CColor m_Color;
	CPadColor m_PadColor;
public:
	CRNET();
	CRNET(const CRNET& src);
	virtual ~CRNET();
	void vSetRNET(string sNetName, CDrawObjArray aDrawObj, CColor Color, CPadColor PadColor);
	virtual CRNET & operator =(const CRNET & rhs);
	virtual BOOL operator==(const CRNET & rhs);
	BOOL operator!=(const CRNET & rhs);
	virtual CRNET* clone();
//	virtual CRNET* clone() const { return new CRNET(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CRNETArray : public CArray< CRNET *, CRNET * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CRNETArray();
	CRNETArray(const CRNETArray& src);
	virtual ~CRNETArray();

	virtual CRNETArray& operator =(const CRNETArray& rhs);
	virtual bool operator==(const CRNETArray& rhs) const;
	bool operator!=(const CRNETArray& rhs) const;
	virtual CRNETArray* clone();
	virtual CRNETArray * clone() const { return new CRNETArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};