#pragma once
#include <iostream>
#include "DrawObj.h"
#include "afxtempl.h"
#include "Polyline.h"
#include "Void.h"

using namespace std;

class CBoardFigure
{
public:
	int m_nNoOfPhysicalLayers=0;
	CDrawObjArray m_aDrawObj;
public:
	CBoardFigure();
	CBoardFigure(const CBoardFigure& src);
	virtual ~CBoardFigure();
	void vSetBoardFigurevector(int m_nNoOfPhysicalLayers, CDrawObjArray aDrawObj);
	void vAddPolylineToBoardFigure(CDrawObj* pDrawObj, int nLibArtworkLayNo);
	void vAddPolylineToBoardFigure(CDrawObjArray aDrawObj, int nLibArtworkLayNo);
	void vAddVoidToBoardFigure(CDrawObj* pDrawObj, int nLibArtworkLayNo);
	void vAddVoidToBoardFigure(CDrawObjArray aDrawObj, int nLibArtworkLayNo);
	virtual CBoardFigure & operator =(const CBoardFigure & rhs);
	virtual BOOL operator==(const CBoardFigure & rhs);
	BOOL operator!=(const CBoardFigure & rhs);
	virtual CBoardFigure* clone();
	//virtual CBoardFigure* clone() const { return new CBoardFigure(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};