#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
#include "StackUp.h"
#include "DrawingArea.h"
#include "Panel.h"
#include "LibMaterial.h"
#include "RigidFlexiblePcb.h"
#include "afxtempl.h"

using namespace std;

class CBoardOutline
{
public:
	CDrawObjArray m_aBoardOutline;
public:
	CBoardOutline();
	CBoardOutline(const CBoardOutline& src);
	virtual ~CBoardOutline();
	void vSetCBoardOutline(CDrawObjArray aBoardOutline);
	virtual CBoardOutline & operator =(const CBoardOutline & rhs);
	virtual BOOL operator==(const CBoardOutline & rhs);
	BOOL operator!=(const CBoardOutline & rhs);
	virtual CBoardOutline* clone();
	//virtual CBoard* clone() const { return new CBoard(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

