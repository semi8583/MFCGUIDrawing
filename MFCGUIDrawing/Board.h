#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
#include "StackUp.h"
#include "DrawingArea.h"
#include "Panel.h"
#include "LibMaterial.h"
#include "RigidFlexiblePcb.h"
#include "BoardOutline.h"
#include "afxtempl.h"

using namespace std;

class CBoard
{
public:
	int m_nNoOfPhysicalLayers;
	CDrawingArea m_DrawingArea;
	CPanel m_Pannel;
	CBoardOutline m_BoardOutline;
	CStackUpArray m_aStackUp;
	CLibMaterial m_LibMaterial;
	CRigidFlexiblePcb m_RigidFlexiblePcb;
public:
	CBoard();
	CBoard(const CBoard& src);
	virtual ~CBoard();
	void vSetBoard(int nNoOfPhysicalLayers, CDrawingArea DrawingArea, CPanel Pannel,
		CBoardOutline BoardOutline, CStackUpArray aStackUp, CLibMaterial LibMaterial, CRigidFlexiblePcb RigidFlexiblePcb);
	void vAddPolylineToBoardOutline(CDrawObj* pDrawObj, int nLibArtworkLayNo);
	void vAddPolylineToBoardOutline(CDrawObjArray aDrawObj, int nLibArtworkLayNo);
	virtual CBoard & operator =(const CBoard & rhs);
	virtual BOOL operator==(const CBoard & rhs);
	BOOL operator!=(const CBoard & rhs);
	virtual CBoard* clone();
	//virtual CBoard* clone() const { return new CBoard(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

