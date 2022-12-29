#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
#include "PinConnectionStatus.h"
using namespace std;
class CVia : public CDrawObj
{
public:
	int m_nLibArtworkLayNo, m_nLibViaNo;
	double m_dAngle, m_dPtX, m_dPtY;
	string m_sTearDropExist;
	CPinConnectionStatus m_PinConnectionStatus;
public:
	CVia();
	CVia(const CVia& src);
	virtual ~CVia();
	void vSetViaLibArtworkLayNo(int nLibArtworkLayNo);
	void vSetViaLibViaNo(int nLibViaNo);
	void vSetViaAngle(double dAngle);
	void vSetViaTearDropExist(string sTearDropExist);
	void vSetViaPtX(double dPtX);
	void vSetViaPtY(double dPtY);
	//void vSetViaPinConnectionStatus(string sPinConnectionStatus);
	int nGetViaLibArtworkLayNo();
	int nGetViaLibViaNo();
	double dGetViaAngle();
	string  sGetViaTearDropExist();
	double dGetViaPtX();
	double dGetViaPtY();
	//string  sGetViaPinConnectionStatus();

	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CVia & operator =(const CVia & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CVia* clone() const { return new CVia(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};