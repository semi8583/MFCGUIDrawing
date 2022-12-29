#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CPolliwogDatabase
{
public:
	string m_sVersion = "";
	int m_nMinorVersionNum;
public:
	CPolliwogDatabase();
	CPolliwogDatabase(const CPolliwogDatabase& src);
	virtual ~CPolliwogDatabase();
	void vSetPolliwogDatabase(int nMinorVersionNum);
	void vSetVersion(string sVersion);
	virtual CPolliwogDatabase & operator =(const CPolliwogDatabase & rhs);
	virtual BOOL operator==(const CPolliwogDatabase & rhs);
	BOOL operator!=(const CPolliwogDatabase & rhs);
	virtual CPolliwogDatabase* clone();
//	virtual CPolliwogDatabase* clone() const { return new CPolliwogDatabase(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};