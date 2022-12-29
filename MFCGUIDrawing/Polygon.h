#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
#include "Line.h"
#include "Arc.h"

using namespace std;
class CPolygon : public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	CDrawObjArray m_aDrawObj;//기존에 있던 변수가 복사되서 들어간다
public:
	CPolygon();
	CPolygon(const CPolygon& src);
	virtual ~CPolygon();
	void vSetPolygonLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetPolygonDrawObj(CDrawObjArray aDrawObj);
	int nGetPolygonLibArtworkLayNo();
	CDrawObjArray vGetPolygonDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	void vAddLineAndArc(CDrawObj* aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CPolygon & operator =(const CPolygon & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CPolygon* clone() const { return new CPolygon(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};