#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CInterfaceFilePath
{
public:
	string m_sInterfaceFilePath;
public:
	CInterfaceFilePath();
	CInterfaceFilePath(const CInterfaceFilePath& src);
	virtual ~CInterfaceFilePath();
	void vSetCInterfaceFilePath(string sInterfaceFilePath);
	virtual CInterfaceFilePath & operator =(const CInterfaceFilePath & rhs);
	virtual BOOL operator==(const CInterfaceFilePath & rhs);
	BOOL operator!=(const CInterfaceFilePath & rhs);
	virtual CInterfaceFilePath* clone();
//	virtual CInterfaceFilePath* clone() const { return new CInterfaceFilePath(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

