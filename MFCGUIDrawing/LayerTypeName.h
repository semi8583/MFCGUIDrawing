#pragma once
#include <iostream>
#include "ConnectionType.h"
#include "stdafx.h"


using namespace std;

class CLayerTypeName
{
public:
	string m_sLayerTypeName;
	CConnectionTypeArray m_aConnectionType;

	CLayerTypeName();
	CLayerTypeName(const CLayerTypeName& src);
	virtual ~CLayerTypeName();
	void vSetCsLayerTypeName(string sLayerTypeName, CConnectionTypeArray aConnectionType);
	virtual CLayerTypeName & operator =(const CLayerTypeName & rhs);
	virtual BOOL operator==(const CLayerTypeName & rhs);
	BOOL operator!=(const CLayerTypeName & rhs);
	virtual CLayerTypeName* clone();
//	virtual CLayerTypeName* clone() const { return new CLayerTypeName(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CLayerTypeNameArray : public CArray< CLayerTypeName *, CLayerTypeName * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CLayerTypeNameArray();
	CLayerTypeNameArray(const CLayerTypeNameArray& src);
	virtual ~CLayerTypeNameArray();

	virtual CLayerTypeNameArray& operator =(const CLayerTypeNameArray& rhs);
	virtual bool operator==(const CLayerTypeNameArray& rhs) const;
	bool operator!=(const CLayerTypeNameArray& rhs) const;
	virtual CLayerTypeNameArray* clone();
	virtual CLayerTypeNameArray * clone() const { return new CLayerTypeNameArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};