#pragma once
#include <iostream>


#include "DrawObj.h"
using namespace std;

class CRefText2
{
public:
	CDrawObjArray m_aDrawObj;
	CRefText2();
	CRefText2(const CRefText2& src);
	virtual ~CRefText2();
	void vSetRefText2(CDrawObjArray aDrawObj);
	virtual CRefText2 & operator =(const CRefText2 & rhs);
	virtual BOOL operator==(const CRefText2 & rhs);
	BOOL operator!=(const CRefText2 & rhs);
	virtual CRefText2* clone();
//	virtual CRefText2* clone() const { return new CRefText2(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};