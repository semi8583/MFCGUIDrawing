#pragma once
#include <iostream>
#include "Information.h"
#include "Board.h"
#include "LibLayer.h"
#include "LayerUnion.h"
#include "LibTurret.h"
#include "LibPenType.h"
#include "LibText.h"
#include "LibPadStack.h"
#include "LibVia.h"
#include "LibComponent.h"
#include "NetListRefdesList.h"
#include "Route.h"
#include "BoardFigure.h"
#include "Gerber.h"
using namespace std;

class CPdb
{
public:
	CInformation m_Information;
	CBoard m_Board;
	CLibLayer m_LibLayer;
	CLayerUnion m_LayerUnion;
	CLibTurret m_LibTurret;
	CLibPenType m_LibPenType;
	CLibText m_LibText;
	CLibPadStack m_LibPadStack;
	CLibVia m_LibVia;
	CLibComponent m_LibComponent;
	CNetListRefdesList m_CNetListRefdesList;
	CRoute m_Route;
	CBoardFigure m_BoardFigure;
	CGerber m_Gerber;
public:
	CPdb();
	CPdb(const CPdb& src);
	virtual ~CPdb();
	virtual CPdb & operator =(const CPdb & rhs);
	virtual BOOL operator==(const CPdb & rhs);
	BOOL operator!=(const CPdb & rhs);
	virtual CPdb* clone();
//	virtual CPdb* clone() const { return new CPdb(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};