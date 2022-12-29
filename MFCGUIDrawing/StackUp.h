#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CStackUp {
public:
	string m_sLayerType, m_sConductingMaterial, m_sDielectricMaterial;
	int m_nArtworkLayNo, m_nPhysicalLayerNo, m_nWiderTraceSide;
	double m_dTraceWidthDifference, m_dThickness;
public:
	CStackUp();
	CStackUp(const CStackUp& src);
	virtual ~CStackUp();
	void vSetCStackUp(string sLayerType, int nArtworkLayNo, int nPhysicalLayerNo, string sConductingMaterial
		, string sDielectricMaterial, double dThickness, double dTraceWidthDifference, int nWiderTraceSide);
	virtual CStackUp & operator =(const CStackUp & rhs);
	virtual BOOL operator==(const CStackUp & rhs);
	BOOL operator!=(const CStackUp & rhs);
	virtual CStackUp* clone();
//	virtual CStackUp* clone() const { return new CStackUp(*this); };
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;

};

class  CStackUpArray : public CArray< CStackUp *, CStackUp * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CStackUpArray();
	CStackUpArray(const CStackUpArray& src);
	virtual ~CStackUpArray();

	virtual CStackUpArray& operator =(const CStackUpArray& rhs);
	virtual bool operator==(const CStackUpArray& rhs) const;
	bool operator!=(const CStackUpArray& rhs) const;
	virtual CStackUpArray* clone();
	virtual CStackUpArray * clone() const { return new CStackUpArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};

