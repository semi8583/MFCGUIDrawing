#pragma once
#include <iostream>
#include "DrawObj.h"
#include "Line.h"
#include "Arc.h"


using namespace std;

class CPolyline : public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	CDrawObjArray m_aDrawObj;//기존에 있던 변수가 복사되서 들어간다
public:
	CPolyline();
	CPolyline(const CPolyline& src);
	virtual ~CPolyline();
	void vSetPolylineLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetPolylineDrawObj(CDrawObjArray aDrawObj);
	int  nGetPolylineLibArtworkLayNo();
	CDrawObjArray vGetPolylineDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	//// 문제 aDrawObj가 뭐가 될지 모르는데 arc랑 line만 매개변수로 받아서 기존 m_aDrawObj에 추가
	void vAddLineAndArc(CDrawObj* aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	virtual CPolyline& operator =(const CPolyline& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CPolyline* clone() const { return new CPolyline(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
	// 문제 CDrawObj가 뭐가 될지 모르는데 arc랑 line만 매개변수로 받아서 기존 vobj에 추가  (기존 희도 대리님 작성)
};