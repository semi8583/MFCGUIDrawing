#pragma once
#include <iostream>
#include "PinNumber.h"
#include "GateNo.h"
using namespace std;

class CSymbolDefinition
{
public:
	int m_nSymbolNo, m_nPinNumber;
	string m_sSymbolName;
	CGateNo m_GateNo;
	CPinNumber m_PinNumber;

public:
	CSymbolDefinition();
	CSymbolDefinition(const CSymbolDefinition& src);
	virtual ~CSymbolDefinition();
	void vSetSymbol(int nSymbolNo, string sSymbolName, int nPinNumber, CGateNo GateNo, CPinNumber PinNumber2);
	virtual CSymbolDefinition & operator =(const CSymbolDefinition & rhs);
	virtual BOOL operator==(const CSymbolDefinition & rhs);
	BOOL operator!=(const CSymbolDefinition & rhs);
	virtual CSymbolDefinition* clone();
//	virtual CSymbolDefinition clone() const { return  CSymbolDefinition(*this); };
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};