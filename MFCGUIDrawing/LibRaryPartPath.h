#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CLibRaryPartPath
{
public:
	string m_sLibRaryPartPath;
public:
	CLibRaryPartPath();
	CLibRaryPartPath(const CLibRaryPartPath& src);
	virtual ~CLibRaryPartPath();
	void vSetCLibRaryPartPath(string sLibRaryPartPath);
	virtual CLibRaryPartPath & operator =(const CLibRaryPartPath & rhs);
	virtual BOOL operator==(const CLibRaryPartPath & rhs);
	BOOL operator!=(const CLibRaryPartPath & rhs);
	virtual CLibRaryPartPath* clone();
//	virtual CLibRaryPartPath* clone() const { return new CLibRaryPartPath(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

