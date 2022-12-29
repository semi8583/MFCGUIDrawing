#pragma once
#include <iostream>
#include "ViaDefinition.h"
using namespace std;

class CLibVia
{
public:
	CViaDefinitionArray m_aViaDefinition;
public:
	CLibVia();
	CLibVia(const CLibVia& src);
	~CLibVia();
	void vSetCLibVia(CViaDefinitionArray aViaDefinition);
	virtual CLibVia & operator =(const CLibVia & rhs);
	virtual BOOL operator==(const CLibVia & rhs);
	BOOL operator!=(const CLibVia & rhs);
	virtual CLibVia* clone();
	//virtual CLibVia* clone() const { return new CLibVia(*this); }
	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

