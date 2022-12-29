#pragma once
#include <iostream>
#include "stdafx.h"
#include "Frequency.h"
using namespace std;

class CMaterial
{
public:
	string m_sMaterialName, m_sMaterialType;
	double m_dThermalConductivityX, m_dThermalConductivityY, m_dThermalConductivityZ;
	CFrequency m_Frequency;
public:
	CMaterial();
	CMaterial(const CMaterial& src);
	virtual ~CMaterial();
	void vSetCMaterial(string sMaterialName, string sMaterialType, double dThermalConductivityX, double dThermalConductivityY
		, double dThermalConductivityZ, CFrequency Frequency);
	virtual CMaterial & operator =(const CMaterial & rhs);
	virtual BOOL operator==(const CMaterial & rhs);
	BOOL operator!=(const CMaterial & rhs);

	virtual CMaterial* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

class  CMaterialArray : public CArray< CMaterial*, CMaterial* >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CMaterialArray();
	CMaterialArray(const CMaterialArray& src);
	virtual ~CMaterialArray();

	virtual CMaterialArray& operator =(const CMaterialArray& rhs);
	virtual bool operator==(const CMaterialArray& rhs) const;
	bool operator!=(const CMaterialArray& rhs) const;
	virtual CMaterialArray* clone();
	virtual CMaterialArray * clone() const { return new CMaterialArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};