#pragma once
#include <iostream>
#include "afxtempl.h"
#include "LibTextText.h"


using namespace std;

class CLibText
{
public:
	CLibTextTextArray m_aText;
public:
	CLibText();
	CLibText(const CLibText& src);
	virtual ~CLibText();
	void vSetCLibText(CLibTextTextArray aText);
	virtual CLibText & operator =(const CLibText & rhs);
	virtual BOOL operator==(const CLibText & rhs);
	BOOL operator!=(const CLibText & rhs);
	virtual CLibText* clone();
//	virtual CLibText* clone() const { return new CLibText(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};