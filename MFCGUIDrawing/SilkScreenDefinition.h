#pragma once
#include <iostream>


#include "DrawObj.h"
using namespace std;

class CSilkScreenDefinition
{
public:
	CDrawObjArray m_aDrawObj;
public:
	CSilkScreenDefinition();
	CSilkScreenDefinition(const CSilkScreenDefinition& src);
	virtual ~CSilkScreenDefinition();
	void vSetSilkScreenDefinition(CDrawObjArray aDrawOb);
	virtual CSilkScreenDefinition & operator =(const CSilkScreenDefinition & rhs);
	virtual BOOL operator==(const CSilkScreenDefinition & rhs);
	BOOL operator!=(const CSilkScreenDefinition & rhs);
	virtual CSilkScreenDefinition* clone();
//	virtual CSilkScreenDefinition* clone() const { return new CSilkScreenDefinition(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};