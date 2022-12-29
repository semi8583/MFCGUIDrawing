#pragma once
#include <iostream>
#include "stdafx.h"

#include "DrawObj.h"
#include "Subboard.h"
using namespace std;

class CPanel
{
public:
	CDrawObjArray m_aPanel;
	CSubboard m_Subboard;
public:
	CPanel();
	CPanel(const CPanel& src);
	virtual ~CPanel();
	void vSetCPanel(CDrawObjArray aPanel, CSubboard Subboard);
	virtual CPanel & operator =(const CPanel & rhs);
	virtual BOOL operator==(const CPanel & rhs);
	BOOL operator!=(const CPanel & rhs);
	virtual CPanel* clone();
//	virtual CPanel* clone() const { return new CPanel(*this); }
//
//protected:
//private:
};
