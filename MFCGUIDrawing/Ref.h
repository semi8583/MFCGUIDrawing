#pragma once
#include <iostream>
#include "Propertys.h"
#include "PinConnectionStatus.h"
#include "RefText.h"
#include "RefText2.h"
using namespace std;

class CRef
{
public:
	int m_nLibPartNo;
	string m_sReferenceName, m_sPlacedLayer;
	double m_dPtX, m_dPtY, m_dAngle, m_dECADAngle, m_dPassiveValue;
	char m_cPassiveType;
	bool m_bReferenceTextReversePlaced, m_bExistInBom;
	CRefText m_RefText;
	CPinConnectionStatusArray m_aPinConnectionStatus;
	CPropertysArray m_aProperty;
	CRefText2 m_RefText2;
	string m_sReferenceThermalCondition;
public:
	CRef();
	CRef(const CRef& src);
	virtual ~CRef();
	void vSetRef(int nLibPartNo, string sReferenceName, string sPlacedLayer, double dPtX, double dPtY, double dAngle, double dECADAngle, char cPassiveType, double dPassiveValue
		, bool bReferenceTextReversePlaced, bool bExistInBom, CRefText RefText, CPinConnectionStatusArray aPinConnectionStatus, CRefText2 RefText2, string sreferenceThermalCondition, CPropertysArray aProperty);
	virtual CRef & operator =(const CRef & rhs);
	virtual BOOL operator==(const CRef & rhs);
	BOOL operator!=(const CRef & rhs);
	virtual CRef* clone();
//	virtual CRef* clone() const { return new CRef(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CRefArray : public CArray< CRef *, CRef * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CRefArray();
	CRefArray(const CRefArray& src);
	virtual ~CRefArray();

	virtual CRefArray& operator =(const CRefArray& rhs);
	virtual bool operator==(const CRefArray& rhs) const;
	bool operator!=(const CRefArray& rhs) const;
	virtual CRefArray* clone();
	virtual CRefArray * clone() const { return new CRefArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
