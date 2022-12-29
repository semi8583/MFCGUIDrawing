#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;

class CText :public CDrawObj
{
public:
	int m_nArtworkLayNo, m_nLibFontNo, m_nJustification;
	string m_sValue, m_sMirror;
	double m_dAngle, m_dPtX, m_dPtY;
public:
	CText();
	CText(const CText& src);
	virtual ~CText();
	void vSetTextArtworkLayNo(int nArtworkLayNo);
	void vSetTextLibFontNo(int nLibFontNo);
	void vSetTextValue(string sValue);
	void vSetTextAngle(double dAngle);
	void vSetTextMirror(string sMirror);
	void vSetTextJustification(int nJustification);
	void vSetTextPtX(double dPtX);
	void vSetTextPtY(double dPtY);
	int nGetTextArtworkLayNo();
	int nGetTextLibFontNo();
	string sGetTextValue();
	double dGetTextAngle();
	string sGetTextMirror();
	int nGetTextJustification();
	double dGetTextPtX();
	double dGetTextPtY();	
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	CText & operator =(const CText & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
//	virtual CText* clone() const { return new CText(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};