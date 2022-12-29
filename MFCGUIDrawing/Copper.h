#pragma once
#include <iostream>
#include "DrawObj.h"
#include "stdafx.h"


using namespace std;
class CCopper :public CDrawObj
{
public:
	int m_nLibArtworkLayNo;
	bool m_bMeshStatus;
	CDrawObjArray  m_aDrawObj;//기존에 있던 변수가 복사되서 들어간다
public:
	CCopper();
	CCopper(const CCopper& src);
	virtual ~CCopper();
	void vSetCopperLibArtworkLayNo(int nLibArtworkLayNo);
	void bSetCopperMeshStatus(bool bMeshStatus);
	void vSetCopperDrawObj(CDrawObjArray aDrawObj);
	int nGetCopperLibArtworkLayNo();
	bool bGetCopperMeshStatus();
	CDrawObjArray vGetCopperDrawObj();
	void vAddDrawObj(CDrawObjArray aDrawObj);
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CCopper& operator =(const CCopper& rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual CCopper* clone() const { return new CCopper(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};