#pragma once
#include <iostream>
#include "DrawObj.h"
#include "stdafx.h"
#include "DrawObj.h"
#include "Polygon.h"
#include "Pt.h"
using namespace std;
class CVoid :public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	CDrawObjArray m_aDrawObj;//기존에 있던 변수가 복사되서 들어간다
public:
	CVoid();
	CVoid(const CVoid& src);
	virtual ~CVoid();
	void vSetVoidLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetVoidDrawObj(CDrawObjArray aDrawObj);
	int nGetVoidLibArtworkLayNo();
	CDrawObjArray vGetVoidDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	void vAddPolygon(CDrawObj* pDrawObj);
	void vAddPt(CDrawObj* aDrawObj);
	void vAddPt(CDrawObjArray aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CVoid & operator =(const CVoid & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CVoid* clone() const { return new CVoid(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};