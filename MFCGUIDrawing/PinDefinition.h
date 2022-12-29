#pragma once
#include <iostream>
using namespace std;

class CPinDefinition
{
public:
	int m_nPinNo, m_nLibPadStackNo, m_nSymbolNo;
	string m_sPinName, m_sGatePinName, m_sPinType;
	double m_dAngle, m_dPtX, m_dPtY;
public:
	CPinDefinition();
	CPinDefinition(const CPinDefinition& src);
	virtual ~CPinDefinition();
	void vSetPinDefinition(int nPinNo, string sPinName, string sGatePinName, string sPinType, int nLibPadstackNo, double dAngle, int nSymbolNo, double dPtX, double dPtY);
	virtual CPinDefinition & operator =(const CPinDefinition & rhs);
	virtual BOOL operator==(const CPinDefinition & rhs);
	BOOL operator!=(const CPinDefinition & rhs);
	virtual CPinDefinition* clone();
//	virtual CPinDefinition* clone() const { return new CPinDefinition(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CPinDefinitionArray : public CArray< CPinDefinition *, CPinDefinition * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPinDefinitionArray();
	CPinDefinitionArray(const CPinDefinitionArray& src);
	virtual ~CPinDefinitionArray();

	virtual CPinDefinitionArray& operator =(const CPinDefinitionArray& rhs);
	virtual bool operator==(const CPinDefinitionArray& rhs) const;
	bool operator!=(const CPinDefinitionArray& rhs) const;
	virtual CPinDefinitionArray* clone();
	virtual CPinDefinitionArray * clone() const { return new CPinDefinitionArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};