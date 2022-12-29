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
	CDrawObjArray m_aDrawObj;//������ �ִ� ������ ����Ǽ� ����
public:
	CPolyline();
	CPolyline(const CPolyline& src);
	virtual ~CPolyline();
	void vSetPolylineLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetPolylineDrawObj(CDrawObjArray aDrawObj);
	int  nGetPolylineLibArtworkLayNo();
	CDrawObjArray vGetPolylineDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	//// ���� aDrawObj�� ���� ���� �𸣴µ� arc�� line�� �Ű������� �޾Ƽ� ���� m_aDrawObj�� �߰�
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
	// ���� CDrawObj�� ���� ���� �𸣴µ� arc�� line�� �Ű������� �޾Ƽ� ���� vobj�� �߰�  (���� �� �븮�� �ۼ�)
};