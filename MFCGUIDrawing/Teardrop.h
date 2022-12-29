#pragma once
#include <iostream>

#include "stdafx.h"
#include "DrawObj.h"
using namespace std;

class CTeardrop :public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	CDrawObjArray m_aDrawObj;//기존에 있던 변수가 복사되서 들어간다
public:
	CTeardrop();
	CTeardrop(const CTeardrop& src);
	virtual ~CTeardrop();
	void vSetCopperLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetCopperDrawObj(CDrawObjArray aDrawObj);
	int nGetCopperLibArtworkLayNo();
	CDrawObjArray vGetCopperDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CTeardrop& operator =(const CTeardrop& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CTeardrop* clone() const { return new CTeardrop(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};