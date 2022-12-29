#pragma once
#include <iostream>
#include "stdafx.h"

#include "DrawObj.h"
using namespace std;

class CSubboard
{
public:
	string m_sSubBoardName;
	CDrawObjArray m_aCDrawObj;
public:
	CSubboard();
	CSubboard(const CSubboard& src);
	virtual ~CSubboard();
	void vSetSubboard(string sSubBoardName, CDrawObjArray aDrawObj);
	virtual CSubboard & operator =(const CSubboard & rhs);
	virtual BOOL operator==(const CSubboard & rhs);
	BOOL operator!=(const CSubboard & rhs);
	virtual CSubboard* clone();
//	virtual CSubboard* clone() const { return new CSubboard(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

