#pragma once
#include <iostream>
#include "afxtempl.h"
#include "DrawObj.h"


using namespace std;

class CLocalShape
{
public:
	int m_nArtwork, m_nLayerNumber;
	CDrawObjArray m_aDrawObj;
public:
	CLocalShape();
	CLocalShape(const CLocalShape& src);
	virtual ~CLocalShape();
	void vSetLocalshape(int dArtwork, int dLayerNumber, CDrawObjArray paDrawObj);
	virtual CLocalShape & operator =(const CLocalShape & rhs);
	virtual BOOL operator==(const CLocalShape & rhs);
	BOOL operator!=(const CLocalShape & rhs);

	virtual CLocalShape* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};
