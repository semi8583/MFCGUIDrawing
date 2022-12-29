#pragma once
#include <iostream>
#include "DrawObj.h"


using namespace std;

class CFigureDefinition
{
public:
	CDrawObjArray m_aDrawObj;
public:
	CFigureDefinition();
	CFigureDefinition(const CFigureDefinition& src);
	virtual ~CFigureDefinition();
	void vSetFigure(CDrawObjArray aDrawObj);
	virtual CFigureDefinition & operator =(const CFigureDefinition & rhs);
	virtual BOOL operator==(const CFigureDefinition & rhs);
	BOOL operator!=(const CFigureDefinition & rhs);
	virtual CFigureDefinition* clone();
//	virtual CFigureDefinition* clone() const { return new CFigureDefinition(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;

};