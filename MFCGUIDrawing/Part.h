#pragma once
#include <iostream>
#include "NameDefinition.h"
#include "MPNNameDefinition.h"
#include "SymbolDefinition.h"
#include "PinDefinition.h"
#include "PinConnection.h"
#include "SilkScreenDefinition.h"
#include "FigureDefinition.h"
#include "Propertys.h"


using namespace std;

class CPart
{
public:
	int m_nLibPartNo;
	double m_dDrawingSizeX, m_dDrawingSizeY, m_dHeight, m_dHighHeight, m_dLowHeight;
	bool m_bIsBroken;
	CNameDefinition m_NameDefinition;
	CMPNNameDefinition m_CMPNNameDefinition;
	CSymbolDefinition m_SymbolDefinition;
	CPinDefinitionArray m_aPinDefinition;
	CPinConnectionArray m_aPinConnection;
	CSilkScreenDefinition m_SilkScreenDefinition;
	CFigureDefinition m_FigureDefinition;
	CPropertysArray m_aProperty;
public:
	CPart();
	CPart(const CPart& src);
	virtual ~CPart();
	void setComponent(int nLibPartNo, double dDrawingSizeX, double dDrawingSizeY, double dHeight, bool bIsBroken, double dHighHeight, double dLowHeight, CNameDefinition NameDefinition,
		CMPNNameDefinition MPNNameDefinition, CSymbolDefinition SymbolDefinition, CPinDefinitionArray aPinDefinition, CPinConnectionArray aPinConnection,
		CSilkScreenDefinition SilkScreenDefinition, CFigureDefinition FigureDefinition, CPropertysArray aProperty);
	virtual CPart & operator =(const CPart & rhs);
	virtual BOOL operator==(const CPart & rhs);
	BOOL operator!=(const CPart & rhs);
	virtual CPart* clone();
//	virtual CPart* clone() const { return new CPart(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CPartArray : public CArray< CPart *, CPart * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPartArray();
	CPartArray(const CPartArray& src);
	virtual ~CPartArray();

	virtual CPartArray& operator =(const CPartArray& rhs);
	virtual bool operator==(const CPartArray& rhs) const;
	bool operator!=(const CPartArray& rhs) const;
	virtual CPartArray* clone();
	virtual CPartArray * clone() const { return new CPartArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};