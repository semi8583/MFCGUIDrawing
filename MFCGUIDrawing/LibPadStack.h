#pragma once
#include <iostream>
#include "LocalShape.h"
#include "PadDefinition.h"
using namespace std;

class CLibPadStack
{
public:
	CPadDefinitionArray m_aPadStackDefinition;
	CLocalShape m_LocalShape;
public:
	CLibPadStack();
	CLibPadStack(const CLibPadStack& src);
	virtual ~CLibPadStack();
	void vSetCLibPadStack(CPadDefinitionArray aPadStackDefinition, CLocalShape LocalShape);
	virtual CLibPadStack & operator =(const CLibPadStack & rhs);
	virtual BOOL operator==(const CLibPadStack & rhs);
	BOOL operator!=(const CLibPadStack & rhs);
	virtual CLibPadStack* clone();
//	virtual CLibPadStack* clone() const { return new CLibPadStack(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};