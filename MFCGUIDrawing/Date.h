#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CDate
{
public:
	string m_sMakingDate;
public:
	CDate();
	CDate(const CDate& src);
	virtual ~CDate();
	void vSetCDate(string sMakingDate);
	virtual CDate & operator =(const CDate & rhs);
	virtual BOOL operator==(const CDate & rhs);
	BOOL operator!=(const CDate & rhs);
	virtual CDate*clone();
	//virtual CDate* clone() const { return new CDate(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};