#pragma once
#include <iostream>
#include "DrawObj.h"
#include "stdafx.h"


using namespace std;

class CDimension :public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	CDrawObjArray m_aDrawObj;//������ �ִ� ������ ����Ǽ� ����
public:
	CDimension();
	CDimension(const CDimension& src);
	virtual ~CDimension();
	void vSetDimensionLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetDimensionDrawObj(CDrawObjArray aDrawObj);
	int nGetDimensionLibArtworkLayNo();
	CDrawObjArray vGetDimensionDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CDimension& operator =(const CDimension& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual CDimension* clone() const { return new CDimension(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};